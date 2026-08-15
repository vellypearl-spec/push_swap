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
