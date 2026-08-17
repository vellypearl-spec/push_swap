# 「 ✦ Simple Strategy Benchmark Data ✦ 」

| Size | Disorder | Operations | Input type |
|---:|---:|---:|---|
| 5 | 0.000 | 0 | Sorted |
| 5 | 0.100 | 12 | Low disorder |
| 5 | 0.300 | 14 | Low/medium disorder |
| 5 | 0.600 | 15 | Medium disorder |
| 5 | 1.000 | 14 | Reverse sorted |
| 10 | 0.000 | 0 | Sorted |
| 10 | 0.022 | 22 | Low disorder |
| 10 | 0.089 | 26 | Low disorder |
| 10 | 0.200 | 33 | Medium disorder |
| 10 | 0.511 | 36 | Random |
| 10 | 0.556 | 37 | Random |
| 10 | 1.000 | 29 | Reverse sorted |
| 20 | 0.000 | 0 | Sorted |
| 20 | 0.458 | 110 | Random |
| 20 | 0.495 | 107 | Random |
| 20 | 0.505 | 105 | Random |
| 20 | 0.516 | 111 | Random |
| 20 | 0.521 | 106 | Random |
| 20 | 0.532 | 114 | Random |
| 20 | 0.542 | 96 | Random |
| 20 | 1.000 | 59 | Reverse sorted |
| 50 | 0.000 | 0 | Sorted |
| 50 | 0.466 | 520 | Random |
| 50 | 0.475 | 537 | Random |
| 50 | 0.483 | 500 | Random |
| 50 | 0.487 | 537 | Random |
| 50 | 0.503 | 498 | Random |
| 50 | 1.000 | 149 | Reverse sorted |

## ✎﹏﹏﹏﹏ Observations

- The simple strategy performs 0 operations on already sorted input because of the early `count_inversions() == 0` return.
- Operation count does not increase monotonically with disorder.
- Reverse-sorted inputs can require fewer operations than random inputs with approximately 0.5 disorder.
- Input size has a strong effect on operation count: random inputs around 0.5 disorder require roughly 100 operations at size 20 and roughly 500 operations at size 50.
- Disorder is useful as an input classification signal, but it should not be used alone to predict operation count.
- The custom strategy should eventually consider both input size and disorder, using benchmark data from the simple, medium, and complex strategies.

# 「 ✦ Medium Strategy Benchmark Data ✦ 」

## .✦ ݁˖ Medium Strategy — Operation Counts

| Input | Size | Disorder | Operations |
|---|---:|---:|---:|
| Random | 10 | 0.489 | 35 |
| Random | 20 | 0.500 | 82 |
| Random | 50 | 0.498 | 280 |
| Random | 100 | 0.476 | 737 |
| Random | 200 | 0.509 | 1,905 |
| Reverse sorted | 100 | 1.000000 | 775 |
| Nearly sorted | 100 | 0.000404 | 253 |

## .✦ ݁˖ Simple vs Medium Strategy

| Input | Size | Disorder | Simple | Medium | Better Strategy |
|---|---:|---:|---:|---:|---|
| Random | 100 | 0.475960 | 1,819 | **737** | Medium |
| Reverse sorted | 100 | 1.000000 | **299** | 775 | Simple |
| Nearly sorted | 100 | 0.000404 | **203** | 253 | Simple |
| Random | 200 | 0.509 | 5,330 | **1,905** | Medium |

## ✎﹏﹏﹏﹏Observations

- The medium strategy significantly reduces operations on random inputs.
- At 100 random elements, medium uses 737 operations versus 1,819 for simple.
- At 200 random elements, medium uses 1,905 operations versus 5,330 for simple.
- Reverse-sorted input is particularly efficient for the simple strategy: 299 operations.
- Nearly sorted input is also better handled by the simple strategy: 203 operations.
- The medium strategy currently does not adapt to disorder except for the already-sorted case (`disorder == 0`).
- Random-input operation growth from 100 to 200 elements is approximately 2.59×, which is reasonably close to the expected growth for an O(n√n) strategy.
- The disorder metric behaves correctly:
  - Sorted input → `0`
  - Reverse-sorted input → `1`
  - Nearly sorted 100-element input with 2 inversions → `0.000404`
  - Random permutations → approximately `0.5`

## જ⁀➴ Current Conclusion

The medium chunk-based strategy is functionally working and provides a substantial improvement over the simple strategy for random inputs. It can be considered a working baseline and should be frozen before later optimization.

Potential improvements such as adaptive strategy selection, more efficient rotations, or reducing repeated scans can be considered later during the 42-specific optimization pass and/or when designing the custom adaptive strategy.

# 「 ✦ Medium Sort Optimization Comparison  ✦ 」

| Input Type | Size | Disorder | Original Medium Sort | Optimized Medium Sort | Operations Reduced | Reduction |
|---|---:|---:|---:|---:|---:|---:|
| Sorted | 100 | 0.000000 | 1,640 | 0 | 1,640 | 100.0% |
| Random — seed 4442 | 200 | 0.506985 | 5,271 | 3,393 | 1,878 | 35.6% |
| Random — seed 4742 | 500 | 0.508208 | 20,390 | 12,969 | 7,421 | 36.4% |

## Implemented Optimizations

### ⬩➤ Already-sorted check

The optimized version checks whether stack A is already sorted before starting the chunk algorithm.
```c
if (!*a || count_inversions(*a) == 0)
	return ;
  This avoids generating unnecessary operations for an already-sorted stack.
```

### ⬩➤ Maximum search in stack B

The original implementation searched for the largest element by rotating stack B.

```c
rb
rb
rb
...
```
Because every rb is a push_swap operation, searching for an element also increased the generated operation count.

The optimized version searches the linked list directly.
```c
find_largest_index()
        ↓
find_position()
```
Pointer traversal does not generate push_swap operations.

### ⬩➤ Shortest rotation direction

After locating the largest element, the optimized version calculates its position and brings it to the top using the shorter direction.
```c
first half of B
      ↓
     rb
second half of B
      ↓
     rrb
```
The element is then returned to stack A using:
```c
pa
```

### ⬩➤ Original Reconstruction
```c
Search whole B using rb
        ↓
Find largest value
        ↓
Continue rotating with rb until it reaches the top
        ↓
pa
        ↓
Repeat
```
### ⬩➤  Optimized Reconstruction
```c 
Traverse B using pointers
        ↓
Find largest index
        ↓
Find its position
        ↓
Choose rb or rrb
        ↓
Bring it to the top
        ↓
pa
        ↓
Repeat
```


## જ⁀➴ Result

The optimization preserves the original chunk-based strategy while reducing unnecessary stack operations during reconstruction.

For the tested random inputs, the optimized implementation reduced the generated operation count by approximately 36%.