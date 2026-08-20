#!/usr/bin/env bash

# ============================================================
# push_swap — FINAL PRE-DEFENSE TESTS
# Run from the root of the submitted/Vogsphere repository.
#
# Optional checker path:
#   CHECKER=/path/to/checker_linux bash final_push_swap_tests.sh
#
# If checker_linux is in the current directory:
#   bash final_push_swap_tests.sh
# ============================================================

set -u

PASS=0
FAIL=0
SKIP=0
TMPDIR_PS="$(mktemp -d)"
trap 'rm -rf "$TMPDIR_PS"' EXIT

if [ -n "${CHECKER:-}" ]; then
	CHECKER_PATH="$CHECKER"
elif [ -x "./checker_linux" ]; then
	CHECKER_PATH="./checker_linux"
else
	CHECKER_PATH=""
fi

green() { printf '\033[32m%s\033[0m\n' "$1"; }
red()   { printf '\033[31m%s\033[0m\n' "$1"; }
yellow(){ printf '\033[33m%s\033[0m\n' "$1"; }
title() { printf '\n\033[1m%s\033[0m\n' "$1"; }

pass()
{
	PASS=$((PASS + 1))
	green "  ✅ $1"
}

fail()
{
	FAIL=$((FAIL + 1))
	red "  ❌ $1"
}

skip()
{
	SKIP=$((SKIP + 1))
	yellow "  ⚠️  $1"
}

check_checker()
{
	local label="$1"
	shift
	local result

	if [ -z "$CHECKER_PATH" ]; then
		skip "$label — checker not configured"
		return
	fi
	result="$(./push_swap "$@" | "$CHECKER_PATH" "$@" 2>/dev/null)"
	if [ "$result" = "OK" ]; then
		pass "$label"
	else
		fail "$label — checker returned: ${result:-<nothing>}"
	fi
}

check_flag_checker()
{
	local label="$1"
	local flag="$2"
	shift 2
	local result

	if [ -z "$CHECKER_PATH" ]; then
		skip "$label — checker not configured"
		return
	fi
	result="$(./push_swap "$flag" "$@" | "$CHECKER_PATH" "$@" 2>/dev/null)"
	if [ "$result" = "OK" ]; then
		pass "$label"
	else
		fail "$label — checker returned: ${result:-<nothing>}"
	fi
}

check_silent()
{
	local label="$1"
	shift
	local out="$TMPDIR_PS/out"
	local err="$TMPDIR_PS/err"

	./push_swap "$@" >"$out" 2>"$err"
	if [ ! -s "$out" ] && [ ! -s "$err" ]; then
		pass "$label"
	else
		fail "$label — expected no output"
	fi
}

check_error()
{
	local label="$1"
	shift
	local out="$TMPDIR_PS/out"
	local err="$TMPDIR_PS/err"

	./push_swap "$@" >"$out" 2>"$err" || true
	if [ ! -s "$out" ] && [ "$(cat "$err")" = "Error" ]; then
		pass "$label"
	else
		fail "$label — expected stdout empty and stderr exactly Error"
		printf '      stdout: %q\n' "$(cat "$out")"
		printf '      stderr: %q\n' "$(cat "$err")"
	fi
}

valgrind_clean()
{
	local label="$1"
	shift
	local log="$TMPDIR_PS/valgrind.log"

	if ! command -v valgrind >/dev/null 2>&1; then
		skip "$label — valgrind not installed"
		return
	fi

	valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		"$@" >/dev/null 2>"$log" || true

	if grep -q "in use at exit: 0 bytes in 0 blocks" "$log" \
		&& grep -q "ERROR SUMMARY: 0 errors" "$log"; then
		pass "$label"
	else
		fail "$label"
		tail -n 25 "$log"
	fi
}

random_args()
{
	local n="$1"
	python3 - "$n" <<'PY'
import random
import sys
n = int(sys.argv[1])
a = list(range(1, n + 1))
random.shuffle(a)
print(*a)
PY
}

title "1. BUILD + NORM"

if make fclean >/dev/null && make >/dev/null; then
	pass "make fclean && make"
else
	fail "make fclean && make"
fi

if norminette include src >"$TMPDIR_PS/norm.out" 2>&1 \
	&& ! grep -q "Error!" "$TMPDIR_PS/norm.out"; then
	pass "Norminette: include + src"
else
	fail "Norminette"
	cat "$TMPDIR_PS/norm.out"
fi

MAKE2="$(make 2>&1)"
if printf '%s' "$MAKE2" | grep -qi "Nothing to be done"; then
	pass "No relink on second make"
else
	yellow "  ℹ️  second make output: ${MAKE2:-<silent>}"
	skip "No-relink wording not detected — inspect Makefile manually"
fi

title "2. BASIC BEHAVIOUR"

check_silent "No arguments → silence"
check_silent "One number → silence" 42
check_silent "Already sorted → silence" 1 2 3 4 5

check_checker "Reverse 5 sorts correctly" 5 4 3 2 1
check_checker "Mixed 5 sorts correctly" 3 5 1 4 2
check_checker "Three numbers sort correctly" 3 2 1

title "3. ERROR MANAGEMENT"

check_error "Non-numeric input" 1 2 hello 3
check_error "Duplicate input" 1 2 2 3
check_error "Above INT_MAX" 1 2 2147483648 3
check_error "Below INT_MIN" 1 2 -2147483649 3
check_error "Only plus sign" "+"
check_error "Only minus sign" "-"

title "4. STRATEGY FLAGS"

check_flag_checker "--simple"   --simple   5 4 3 2 1
check_flag_checker "--medium"   --medium   5 4 3 2 1
check_flag_checker "--complex"  --complex  5 4 3 2 1
check_flag_checker "--adaptive" --adaptive 5 4 3 2 1

DEFAULT_OUT="$TMPDIR_PS/default.ops"
ADAPTIVE_OUT="$TMPDIR_PS/adaptive.ops"
./push_swap 5 4 3 2 1 >"$DEFAULT_OUT"
./push_swap --adaptive 5 4 3 2 1 >"$ADAPTIVE_OUT"
if cmp -s "$DEFAULT_OUT" "$ADAPTIVE_OUT"; then
	pass "Default behaviour matches --adaptive"
else
	fail "Default behaviour differs from --adaptive"
fi

title "5. SMALL-INPUT OPERATION COUNTS"

THREE_COUNT="$(./push_swap 3 2 1 | wc -l | tr -d ' ')"
if [ "$THREE_COUNT" -le 3 ]; then
	pass "3 numbers: $THREE_COUNT operations (≤ 3)"
else
	fail "3 numbers: $THREE_COUNT operations (> 3)"
fi

FIVE_COUNT="$(./push_swap 5 4 3 2 1 | wc -l | tr -d ' ')"
if [ "$FIVE_COUNT" -le 15 ]; then
	pass "5 numbers: $FIVE_COUNT operations (≤ 15)"
else
	fail "5 numbers: $FIVE_COUNT operations (> 15)"
fi

title "6. RANDOM 100 + 500"

read -r -a ARG100 <<< "$(random_args 100)"
OPS100="$(./push_swap "${ARG100[@]}" | wc -l | tr -d ' ')"
if [ -n "$CHECKER_PATH" ]; then
	RESULT100="$(./push_swap "${ARG100[@]}" | "$CHECKER_PATH" "${ARG100[@]}" 2>/dev/null)"
	if [ "$RESULT100" = "OK" ]; then
		pass "Random 100 checker: OK"
	else
		fail "Random 100 checker: $RESULT100"
	fi
else
	skip "Random 100 checker — checker not configured"
fi
if [ "$OPS100" -lt 2000 ]; then
	pass "Random 100: $OPS100 operations (< 2000)"
else
	fail "Random 100: $OPS100 operations (≥ 2000)"
fi

read -r -a ARG500 <<< "$(random_args 500)"
OPS500="$(./push_swap "${ARG500[@]}" | wc -l | tr -d ' ')"
if [ -n "$CHECKER_PATH" ]; then
	RESULT500="$(./push_swap "${ARG500[@]}" | "$CHECKER_PATH" "${ARG500[@]}" 2>/dev/null)"
	if [ "$RESULT500" = "OK" ]; then
		pass "Random 500 checker: OK"
	else
		fail "Random 500 checker: $RESULT500"
	fi
else
	skip "Random 500 checker — checker not configured"
fi
if [ "$OPS500" -lt 12000 ]; then
	pass "Random 500: $OPS500 operations (< 12000)"
else
	fail "Random 500: $OPS500 operations (≥ 12000)"
fi

title "7. BENCHMARK MODE"

BENCH_OUT="$TMPDIR_PS/bench.out"
BENCH_ERR="$TMPDIR_PS/bench.err"
./push_swap --bench --simple 5 4 3 2 1 >"$BENCH_OUT" 2>"$BENCH_ERR"

if [ -s "$BENCH_OUT" ]; then
	pass "--bench keeps operations on stdout"
else
	fail "--bench produced no operations on stdout"
fi

if grep -q "Disorder:" "$BENCH_ERR" && grep -q "Strategy:" "$BENCH_ERR"; then
	pass "--bench reports disorder + strategy on stderr"
else
	fail "--bench stderr is missing disorder and/or strategy"
	cat "$BENCH_ERR"
fi

SORTED_BENCH_ERR="$TMPDIR_PS/sorted_bench.err"
./push_swap --bench --simple 1 2 3 4 5 >/dev/null 2>"$SORTED_BENCH_ERR"
if grep -Eq "Disorder:[[:space:]]+0(\.0+)?%" "$SORTED_BENCH_ERR"; then
	pass "Sorted disorder ≈ 0%"
else
	fail "Sorted disorder is not 0%"
	cat "$SORTED_BENCH_ERR"
fi

REVERSE_BENCH_ERR="$TMPDIR_PS/reverse_bench.err"
./push_swap --bench --simple 5 4 3 2 1 >/dev/null 2>"$REVERSE_BENCH_ERR"
if grep -Eq "Disorder:[[:space:]]+100(\.0+)?%" "$REVERSE_BENCH_ERR"; then
	pass "Reverse disorder ≈ 100%"
else
	fail "Reverse disorder is not 100%"
	cat "$REVERSE_BENCH_ERR"
fi

title "8. VALGRIND — FINAL MEMORY SWEEP"

valgrind_clean "Adaptive normal path" ./push_swap 5 4 3 2 1
valgrind_clean "Simple strategy" ./push_swap --simple 5 4 3 2 1
valgrind_clean "Medium strategy" ./push_swap --medium 5 4 3 2 1
valgrind_clean "Complex strategy" ./push_swap --complex 5 4 3 2 1
valgrind_clean "Duplicate error path" ./push_swap 1 2 2 3
valgrind_clean "Mid-parse invalid input" ./push_swap 1 2 hello 3
valgrind_clean "Positive overflow" ./push_swap 1 2 2147483648 3
valgrind_clean "Negative overflow" ./push_swap 1 2 -2147483649 3
valgrind_clean "Random 100" ./push_swap "${ARG100[@]}"
valgrind_clean "Random 500" ./push_swap "${ARG500[@]}"

title "9. FINAL SUMMARY"

printf '\n'
green "PASS: $PASS"
if [ "$SKIP" -gt 0 ]; then
	yellow "SKIP: $SKIP"
else
	printf "SKIP: 0\n"
fi

if [ "$FAIL" -eq 0 ]; then
	green "FAIL: 0"
	printf '\n🧬 FINAL RESULT: ALL EXECUTED TESTS PASSED.\n'
	exit 0
else
	red "FAIL: $FAIL"
	printf '\n⚠️  FINAL RESULT: FIX FAILURES BEFORE DEFENSE.\n'
	exit 1
fi
