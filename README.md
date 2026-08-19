*This activity has been created as part of the 42 curriculum by <vkuzmina>, <glouis>.*

# 「 ✦ push_swap  ✦ 」

## ꫂ❁ Description

`push_swap` sorts a stack of integers using a restricted set of stated operations and a second auxiliary stack.

The project implements four strategy families:

- **Simple** — an `O(n²)` strategy.
- **Medium** — an `O(n√n)` strategy.
- **Complex** — an `O(n log n)` strategy.
- **Adaptive** — a custom strategy that uses information about the current stack and local movement costs.

The program works with two singly linked lists representing stacks `a` and `b`. Input values are validated, converted safely to `int`, checked for duplicates, and assigned compressed rank indexes before sorting.

The valid operations are:

```text
sa   sb   ss
pa   pb
ra   rb   rr
rra  rrb  rrr
```

## ꫂ❁ Instructions

### ⋆˚✿˖° Compilation

```bash
make 
```

The project is compiled with `-Wall -Wextra -Werror`.

Available Makefile rules:

```bash
make
make clean
make fclean
make re
```

### Usage

```bash
./push_swap <numbers>
```

Example:

```bash
./push_swap 4 2 5 1 3
```

The program prints only the operations required to sort stack `a`. Already sorted input produces no instructions.

### ⋆˚✿˖° Strategy flags

```bash
./push_swap --simple   <numbers>
./push_swap --medium   <numbers>
./push_swap --complex  <numbers>
./push_swap --adaptive <numbers>
```

Running without a strategy flag defaults to adaptive behaviour.

> Update if there are any changes in flags system!!!!!!

### ⋆˚✿˖° Benchmark mode

Benchmark mode should expose the information required by the subject/evaluation, including disorder, strategy information, and operation statistics.

## ꫂ❁ Algorithms

### ⋆˚✿˖° Simple — `O(n²)`

The simple strategy is a sequential rank-selection approach. It repeatedly finds the smallest remaining rank in `a`, brings it to the top using the cheaper rotation direction, pushes it to `b`, and finally pushes everything back to `a`.

It performs especially well when consecutive ranks are already structurally close, including several sorted, reverse-sorted, rotated, and low-rank-distance configurations tested during development.

### ⋆˚✿˖° Medium — `O(n√n)`

The medium strategy uses approximately `√n` rank buckets. Elements belonging to the current bucket are moved from `a` to `b`; reconstruction repeatedly retrieves the largest remaining rank in `b` using the cheaper rotation direction.

This reduces the exact sequential searching required by the simple strategy and gives more stable performance on mixed/random configurations.

> Gift, you can change it as you like!!!! 

### ⋆˚✿˖° Complex — `O(n log n)`

The complex strategy uses binary LSD radix sorting on compressed rank indexes.

For each significant bit:

1. inspect the current top index in `a`;
2. push indexes with a `0` bit to `b`;
3. rotate indexes with a `1` bit in `a`;
4. push all elements from `b` back to `a`;
5. continue with the next bit.

Coordinate compression maps values to ranks `0..n-1`, allowing the radix strategy to work on compact non-negative indexes.

> AND THIS TOO!!!!!

### ⋆˚✿˖° Adaptive — custom strategy

The adaptive strategy is a cost-aware two-stack algorithm designed for this project. It separates **target selection** from **movement execution**.

#### ❀˖° Candidate cost

For a candidate rank in `a`, the strategy predicts:

```text
shortest rotations required to reach the candidate + pb
```

The prediction itself emits no operations.

#### ❀˖° Gain-based adaptive window

The strategy compares the cost of extracting the exact smallest remaining rank with nearby candidates. A candidate can be preferred when the rotations saved justify temporarily skipping ranks.

The rank window is recalculated after every extraction, so its size changes dynamically with the current stack.

#### ❀˖° Target selection

Inside the current rank window, the cheapest available candidate is selected.

#### ❀˖° Placement prediction in B

Before pushing the selected target, the strategy searches `b` for a circular descending gap:

```text
previous_rank > target > current_rank
```

If several valid gaps exist, it prefers the cheaper one to reach.

#### ❀˖° Hitchhiking with `rr` / `rrr`

The strategy predicts the cost and direction required in both stacks.

When `b` can move toward its desired insertion position without increasing the rotations already required by `a`, the movements are combined:

```text
ra  + rb  -> rr
rra + rrb -> rrr
```

This improves the future structure of `b` using rotations that `a` was already paying for.

#### ❀˖° Reconstruction

After distribution, the strategy repeatedly finds the largest remaining rank in `b`, brings it to the top using the cheaper direction, and performs `pa`.

A small `sb` optimization is used when swapping preserves the next rank needed by reconstruction.

The final state is:

```text
stack a: sorted in ascending order
stack b: empty
```

## ꫂ❁ Input analysis

### ⋆˚✿˖° Disorder

The project calculates an inversion-based disorder value in the range `[0, 1]`:

```text
0 -> already sorted
1 -> maximally disordered according to the metric
```

### ⋆˚✿˖° Rank distance

During development, an additional structural metric measured how physically close consecutive compressed ranks were in the linked list.

It was used mainly for research and benchmarking and helped explain why the simple strategy can be extremely efficient on some structured inputs even when inversion-based disorder is high.

## ꫂ❁ Performance notes

Performance depends on the input configuration, so individual examples are not universal bounds.

Example production runs using the adaptive/custom strategy:

```text
100 random values, deterministic seed 42:
768 operations
checker: OK

500 random values, deterministic seed 42:
8790 operations
checker: OK
```

The adaptive strategy was also stress-tested on multiple deterministic random seeds for sizes 100 and 500, with all tested runs ending with sorted `a` and empty `b`.

The complex/radix strategy is especially useful for larger random inputs, while simple and adaptive approaches can perform better when the stack structure allows cheaper local movement.

## ꫂ❁ Error handling

Invalid input prints:

```text
Error
```

followed by a newline on standard error.

Handled cases include non-numeric input, duplicate values, and values outside the signed `int` range. Running with no numbers produces no output.

## ꫂ❁ Resources

- 42 project subject and evaluation material — requirements and evaluation constraints.
- 42 Norm / Norminette documentation — style requirements.
- C manual pages / documentation — linked lists, memory management, and permitted functions.
> Add more in future, too sleepy 

### ⋆˚✿˖° AI usage

AI tools were used as a learning and review aid during development, including:

- discussing algorithm alternatives and trade-offs;
- checking reasoning about complexity and operation costs;
- designing and interpreting benchmark experiments;
- organizing data analysis;

The implementation was written, tested, debugged, and defended by the project learners. 

## ꫂ❁ Contributions

### ⋆ 𐙚 ̊. vkuzmina

Main areas of contribution:

- input parsing, validation, integer-range checking, duplicate handling, and stack construction;
- linked-list and coordinate-compression utilities;
- stack operation implementation and integration;
- simple strategy;
- adaptive/custom strategy design and implementation;
- candidate-cost and gain analysis;
- dynamic adaptive window;
- cost-aware target selection;
- stack `b` descending-gap prediction;
- combined-rotation hitchhiking with `rr` and `rrr`;
- adaptive reconstruction and optimization;
- benchmarking, stress testing, and checker integration;
- project documentation.

### ⋆ 𐙚 ̊. glouis

Main areas of contribution:

- medium strategy;
- complex strategy;
- strategy / benchmark flags.

> Gift, add more explanaitions about your work done here as well!! Testing, debugging and etc!!!


## Team note

Both contributors should be able to explain and defend the complete codebase, including code originally written by the other contributor.

