# 「 ✦ Benchmark & Custom Strategy Research ✦ 」

This document contains the benchmark data gathered while comparing the
simple and medium strategies and while designing the custom adaptive strategy.

> **Important:** only the final benchmark data collected after fixing the
> operation counter is included here. Earlier results where some stack B
> rotations were not counted are intentionally omitted.

---

## ⬩➤  Medium Sort Optimization

The original medium implementation was optimized without changing its overall
chunk-based architecture.

The main optimizations were:

- early return for an already-sorted stack;
- search stack B using pointer traversal instead of rotating B to inspect it;
- find the position of the largest index before performing stack operations;
- choose the shorter `rb` / `rrb` path.

### .✦ ݁˖  Original vs Optimized Medium Sort

| Input Type | Size | Disorder | Original Medium | Optimized Medium | Operations Reduced | Reduction |
|---|---:|---:|---:|---:|---:|---:|
| Sorted | 100 | 0.000000 | 1,640 | 0 | 1,640 | 100.0% |
| Random — seed 4442 | 200 | 0.506985 | 5,271 | 3,393 | 1,878 | 35.6% |
| Random — seed 4742 | 500 | 0.508208 | 20,390 | 12,969 | 7,421 | 36.4% |

For the tested random inputs, the optimization reduced the generated operation
count by approximately **36%**.

---

## ⬩➤  Simple vs Medium — Basic Structural Behaviour

The first important observation was that inversion disorder alone does not
predict how expensive a stack is to sort.

### .✦ ݁˖  Sorted Inputs

| Size | Disorder | Simple | Medium |
|---:|---:|---:|---:|
| 20 | 0.000000 | 0 | 0 |
| 50 | 0.000000 | 0 | 0 |
| 100 | 0.000000 | 0 | 0 |
| 200 | 0.000000 | 0 | 0 |

---

### .✦ ݁˖  Nearly Sorted Inputs

Each test contains only two adjacent swapped pairs.

| Size | Disorder | Simple | Medium |
|---:|---:|---:|---:|
| 20 | 0.010526 | 44 | 100 |
| 50 | 0.001633 | 104 | 404 |
| 100 | 0.000404 | 204 | 1,102 |
| 200 | 0.000101 | 404 | 3,004 |

Nearly sorted inputs are extremely inexpensive for the simple strategy.

---

### .✦ ݁˖  Reverse-Sorted Inputs

| Size | Disorder | Simple | Medium |
|---:|---:|---:|---:|
| 20 | 1.000000 | 59 | 116 |
| 50 | 1.000000 | 149 | 443 |
| 100 | 1.000000 | 299 | 1,190 |
| 200 | 1.000000 | 599 | 3,186 |

Despite having the maximum possible inversion disorder, reverse-sorted stacks
are highly structured and very inexpensive for the simple strategy.

This demonstrates that:

```text
maximum inversion disorder
        !=
maximum operational difficulty
```

### .✦ ݁˖  Random inputs 

| Size | Disorder | Simple | Medium |
| ---: | -------: | -----: | -----: |
|   20 | 0.642105 |     84 |    113 |
|   50 | 0.497143 |    453 |    446 |
|  100 | 0.505455 |  1,506 |  1,247 |
|  200 | 0.508643 |  5,330 |  3,386 |

For irregular/random inputs, the crossover between the simple and medium
strategies begins around the 50 element range.

The cost difference becomes increasingly significant as input size grows.

## ⬩➤ Structured Inputs With Similar Disorder

Several deliberately structured permutations were tested to determine whether
disorder alone could distinguish their real operational difficulty.

### .✦ ݁˖  Alternating Low / High

Example:
```
0 99 1 98 2 97 3 96 ...
```
| Size | Disorder | Simple | Medium |
| ---: | -------: | -----: | -----: |
|   20 | 0.473684 |     57 |    108 |
|   50 | 0.489796 |    147 |    421 |
|  100 | 0.494949 |    297 |  1,145 |
|  200 | 0.497487 |    597 |  3,103 |


### .✦ ݁˖  Rotated Sorted

Example:
```
50 51 52 ... 99 0 1 2 ... 49
```
| Size | Disorder | Simple | Medium |
| ---: | -------: | -----: | -----: |
|   20 | 0.526316 |     50 |    100 |
|   50 | 0.510204 |    125 |    401 |
|  100 | 0.505051 |    250 |  1,100 |
|  200 | 0.502513 |    500 |  3,005 |

A rotated sorted stack can have disorder very close to random input while
remaining extremely cheap for the simple strategy.

For example:
```
Random 100:
Disorder = 0.505455
Simple   = 1506

Rotated sorted 100:
Disorder = 0.505051
Simple   = 250
```
Almost identical inversion disorder, but more than a 6x difference in
simple-strategy cost.

## ⬩➤ Additional Structured Tests — Size 100

| Pattern                        | Disorder | Simple | Medium |
| ------------------------------ | -------: | -----: | -----: |
| Sorted                         | 0.000000 |      0 |      0 |
| Nearly sorted                  | 0.000404 |    204 |  1,102 |
| Reverse                        | 1.000000 |    299 |  1,190 |
| Rotated sorted                 | 0.505051 |    250 |  1,100 |
| Largest element moved to front | 0.020000 |    201 |  1,101 |
| Smallest element moved to end  | 0.020000 |    201 |  1,101 |
| Adjacent pairs swapped         | 0.010101 |    299 |  1,190 |
| Alternating low/high           | 0.494949 |    297 |  1,145 |


These tests led to the conclusion that a second structural metric was needed
in addition to inversion disorder.

## ⬩➤ Rank Distance Metric

A new metric called rank_distance was introduced.

It measures the average shortest circular distance between consecutive
compressed indexes:
```
index 0 -> index 1
index 1 -> index 2
index 2 -> index 3
...
```
For each pair:
```
direct distance = abs(position_current - position_next)

circular distance =
    min(direct_distance,
        size - direct_distance)
```
The final metric is:
```
average circular distance between consecutive ranks
```
The purpose of the metric is to estimate how physically scattered the next
useful ranks are inside the stack.

## ⬩➤ Rank Distance Validation — Size 100
### .✦ ݁˖  Highly Structured Inputs

| Pattern                | Disorder | Rank Distance | Simple | Medium |
| ---------------------- | -------: | ------------: | -----: | -----: |
| Sorted                 | 0.000000 |      1.000000 |      0 |      0 |
| Nearly sorted          | 0.000404 |      1.040404 |    204 |  1,102 |
| Reverse                | 1.000000 |      1.000000 |    299 |  1,190 |
| Rotated sorted         | 0.505051 |      1.000000 |    250 |  1,100 |
| Largest moved to front | 0.020000 |      1.000000 |    201 |  1,101 |
| Smallest moved to end  | 0.020000 |      1.000000 |    201 |  1,101 |
| Adjacent pairs swapped | 0.010101 |      1.989899 |    299 |  1,190 |
| Alternating low/high   | 0.494949 |      1.989899 |    297 |  1,145 |


### .✦ ݁˖  Random Inputs
| Seed | Disorder | Rank Distance | Simple | Medium |
| ---: | -------: | ------------: | -----: | -----: |
|   42 | 0.505455 |     27.272727 |  1,506 |  1,247 |
|  314 | 0.561616 |     23.494949 |  1,363 |  1,221 |
| 2026 | 0.507273 |     25.525253 |  1,489 |  1,235 |

The separation was significant:
```
structured:
rank distance ~= 1-2


random:
rank distance ~= 23-27
```
This strongly suggests that rank_distance captures structural information
that inversion disorder does not.

## ⬩➤ Controlled Rank-Distance Tests — Size 100

Special permutations were generated in which consecutive ranks are placed at a
controlled circular distance from one another.
| Rank Distance | Disorder | Simple | Medium |
| ------------: | -------: | -----: | -----: |
|             3 | 0.340000 |    299 |  1,107 |
|             7 | 0.436970 |    497 |  1,117 |
|            11 | 0.500000 |    695 |  1,125 |
|            17 | 0.446061 |    992 |  1,162 |
|            19 | 0.495152 |  1,091 |  1,165 |
|            21 | 0.484848 |  1,190 |  1,174 |
|            23 | 0.509697 |  1,289 |  1,187 |
|            31 | 0.500000 |  1,685 |  1,215 |
|            47 | 0.533939 |  2,477 |  1,287 |

At size 100, the simple/medium crossover occurs between rank distance
19 and 21.

Estimated crossover:
```
rank distance ~= 20.6
```
## ⬩➤ Controlled Rank-Distance Tests — Size 50
| Rank Distance | Disorder | Simple | Medium |
| ------------: | -------: | -----: | -----: |
|             7 | 0.480000 |    247 |    413 |
|            11 | 0.489796 |    345 |    431 |
|            13 | 0.431020 |    394 |    430 |
|            17 | 0.333061 |    492 |    452 |
|            21 | 0.489796 |    590 |    460 |

At size 50, the crossover occurs between rank distance 13 and 17.

Estimated crossover:
```
rank distance ~= 14.9
```
## ⬩➤ Controlled Rank-Distance Tests — Size 200
| Rank Distance | Disorder | Simple | Medium |
| ------------: | -------: | -----: | -----: |
|            23 | 0.481055 |  2,589 |  3,125 |
|            27 | 0.490101 |  2,987 |  3,110 |
|            29 | 0.466131 |  3,186 |  3,165 |
|            31 | 0.478643 |  3,385 |  3,182 |
|            37 | 0.499899 |  3,982 |  3,216 |

At size 200, the crossover occurs between rank distance 27 and 29.

Estimated crossover:
```
rank distance ~= 28.7
```
## ⬩➤ Boundary Validation — Size 20
| Rank Distance | Disorder | Simple | Medium |
| ------------: | -------: | -----: | -----: |
|             7 | 0.331579 |     97 |    112 |
|             9 | 0.505263 |    116 |    113 |

Estimated crossover:
```
rank distance ~= 8.7
```
## ⬩➤ Boundary Validation — Size 500
| Rank Distance | Disorder | Simple | Medium |
| ------------: | -------: | -----: | -----: |
|            43 | 0.491086 | 11,479 | 11,877 |
|            47 | 0.490124 | 12,477 | 11,906 |

Estimated crossover:
```
rank distance ~= 44.6
```
## ⬩➤ Observed Crossover Relationship

The experimentally observed simple/medium crossover was compared against:
```
2 * sqrt(size)
Size	Observed Crossover	2 * sqrt(size)
20	~8.7	8.94
50	~14.9	14.14
100	~20.6	20.00
200	~28.7	28.28
500	~44.6	44.72
```
The relationship is remarkably close across the tested sizes.

This suggests the empirical decision boundary:
```
rank_distance ~= 2 * sqrt(size)
```
The result should be treated as an empirical model, not a formal
mathematical proof.

## ⬩➤ Structural Difficulty Ratio

A useful derived metric can therefore be expressed as:
```
structural_ratio =
    rank_distance / (2 * sqrt(size))
```
Interpretation:
```
structural_ratio < 1
    -> sequential ranks are relatively cheap to access


structural_ratio ~= 1
    -> transition region


structural_ratio > 1
    -> sequential targeting becomes relatively expensive
```
Using the existing integer square-root/chunk helper means this relationship can
be approximated without requiring math.h.

## ⬩➤ Main Conclusions From the Data
Disorder alone is not enough

Examples:
```
Reverse 100:
Disorder      = 1.000000
Rank distance = 1.000000
Simple        = 299


Random 100:
Disorder      ~= 0.5
Rank distance ~= 25
Simple        ~= 1400-1500
```
The reverse stack has significantly larger inversion disorder but is much
easier for the simple strategy because consecutive ranks are physically close.

Similar disorder can hide radically different structures

Example:
```
Random 100:
Disorder      = 0.505455
Rank distance = 27.272727
Simple        = 1506


Rotated sorted 100:
Disorder      = 0.505051
Rank distance = 1.000000
Simple        = 250
```
Therefore:
```
disorder
    -> measures global inversion state
```
```
rank distance
    -> measures structural accessibility of consecutive ranks
```
Simple strategy is strongly structure-sensitive

The simple strategy becomes expensive when consecutive ranks are physically
scattered throughout the stack.

Its operation cost grows strongly with rank_distance.

Medium strategy is more size-sensitive

At a fixed size, medium operation counts stay within a relatively narrow range
across very different structures.

Example for size 100:
```
Nearly sorted       -> 1102
Rotated sorted      -> 1100
Alternating         -> 1145
Reverse             -> 1190
Random              -> ~1220-1250
```
This suggests that medium sort is driven primarily by its chunk/scanning
structure rather than by the initial arrangement of the stack.

## ⬩➤ Custom Strategy — Current Design Direction

The custom strategy should not simply call the existing simple, medium, or
complex strategies.

Instead, it can operate as an independent hybrid algorithm.
```
Phase 1 — Analyze

Collect:

size
disorder
rank distance

Interpretation:

SIZE
    -> scale of the problem


DISORDER
    -> global orientation/order


RANK DISTANCE
    -> accessibility/scattering of consecutive ranks

These values create an input profile.

Phase 2 — Cost-Aware Movement

Determine useful candidate targets and calculate movement cost before executing
operations.

Possible cost information:

candidate position
rotation cost
ra vs rra
rb vs rrb
push cost
possible rr / rrr combinations

Existing helpers that can support this phase include:

find_position()
rotation_cost()
stack_size()
bring_to_top()
bring_to_top_b()

No push_swap operation needs to be executed while estimating candidate costs.

Phase 3 — Reconstruction

Reconstruct stack A using cost-aware movements.

Possible behaviour:

inspect B
    ↓
select target
    ↓
calculate cheapest A/B rotation combination
    ↓
use ra / rra / rb / rrb
    ↓
use rr / rrr when useful
    ↓
pa
    ↓
repeat
    ↓
sorted A
```
## ⬩➤ Current Custom Strategy Hypothesis

The algorithm may adapt the width of its candidate window according to the
input profile.
```
Conceptually:

low structural ratio
        ↓
consecutive ranks are easy to reach
        ↓
use narrow / exact sequential targets




medium structural ratio
        ↓
use a small candidate window
        ↓
choose cheapest useful target




high structural ratio
        ↓
consecutive ranks are scattered
        ↓
use a wider candidate window
        ↓
cost-driven selection
```
This allows the custom strategy to inherit useful ideas from several approaches
without directly calling the existing strategies.

## ⬩➤ Current Three-Phase Architecture
```
┌──────────────────────────────────────────────┐
│ PHASE 1 — ANALYSIS                           │
│                                              │
│ size                                         │
│ disorder                                     │
│ rank distance                                │
│                                              │
│            ↓                                 │
│                                              │
│ create input profile                         │
│ determine initial behaviour/window           │
└────────────────────┬─────────────────────────┘
                     │
                     ▼
┌──────────────────────────────────────────────┐
│ PHASE 2 — COST-DRIVEN DISTRIBUTION           │
│                                              │
│ determine useful candidates                  │
│ calculate movement costs                     │
│ compare rotation directions                  │
│ choose cheapest useful movement              │
│ execute                                      │
│ adapt when necessary                         │
└────────────────────┬─────────────────────────┘
                     │
                     ▼
┌──────────────────────────────────────────────┐
│ PHASE 3 — COST-DRIVEN RECONSTRUCTION         │
│                                              │
│ inspect stack B                              │
│ calculate target costs                       │
│ combine rotations where useful               │
│ pa                                           │
│                                              │
│            ↓                                 │
│         SORTED A                             │
└──────────────────────────────────────────────┘
```
## ⬩➤ Research Summary

The benchmark process led to the following progression:
```
Initial idea:
size + disorder
        ↓


Benchmark observation:
disorder does not predict actual operational difficulty
        ↓


New metric:
rank distance
        ↓


Validation:
rank distance strongly correlates with simple-strategy cost
        ↓


Controlled testing:
simple/medium crossover changes with size
        ↓


Observed relation:
rank_distance ~= 2 * sqrt(size)
        ↓


Current direction:
use size + disorder + rank distance to build an input profile,
then perform cost-aware adaptive movements.
```
The custom strategy design is therefore based on measured behaviour rather than
arbitrary thresholds.