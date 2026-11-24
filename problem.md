# The Minimum Hinge
I am  given a permutation `a` of `1,2,...,n`.
For a subarray `[l,r]` (1-indexed), let `k` be the unique position of its minimum element. Define:
- `Left = a_l + a_{l+1} + ... + a_{k-1}`;
- `Right = a_{k+1} + a_{k+2} + ... + a_r`.
An empty sum is `0`. Call `[l,r]` a hinged subarray if `Left = Right`.
Count the number of hinged subarrays.
## Input
The first line contains an integer `n` (`1 <= n <= 200000`).
The second line contains a permutation `a_1,...,a_n` of `1,...,n`.
## Output
Print the number of hinged subarrays.
The answer fits in signed 64-bit integer.

## Examples
### Input
```
5
4 3 2 1 5
```
### Output
```
6
```
## Note
For every singleton subarray, both sides are empty, so all `n` singleton subarrays are hinged.
