#  solution
Let `P[i]` be the sum of the first `i` elements, where `P[0] = 0`.
For each position `k`, let:
- `L[k]` be the nearest smaller value on the left, or `-1`;
- `R[k]` be the nearest smaller value on the right, or `n`.
The subarrays whose minimum is at `k` have
`L[k] + 1 <= l <= k <= r <= R[k] - 1`.
For `[l,r]` with minimum at `k`, the balance equation is:
`P[k] - P[l] = P[r+1] - P[k+1]`
So the matching pair must satisfy:
`P[l] + P[r+1] = P[k] + P[k+1]`.

Find the nearest smaller values with monotonic stacks. For each `k`,
store the prefix sums in a hash map and enumerate the smaller side:
left indices `[L[k]+1,k]` or right indices `[k+1,R[k]]`.
For each index checked, look up the required prefix sum and verify that
the matching index is inside the other valid range.

Expected complexity: `O(n log n)` time and `O(n)` memory.
