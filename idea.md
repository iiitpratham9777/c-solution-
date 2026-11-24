# Idea development

## Concept
Count subarrays whose minimum element divides the subarray into two equal-sum
parts.

## Rejected variants
1. Arbitrary positive arrays: Duplicate minima need extra tie-breaking.
2. Maximum instead of minimum: The minimum has the cleaner stack boundaries.
3. Only even-length subarrays: This removes singleton subarrays.

## Refinement
The array is a permutation, so all prefix sums are distinct.
For each minimum position `k`, nearest-smaller elements give the valid left
and right boundaries.

The balance condition becomes:

`P[l] + P[r+1] = P[k] + P[k+1]`

Enumerate only the smaller left or right range and use a hash table to find
the matching prefix sum.

## Final formulation rationale
The problem combines monotonic stacks, prefix sums, and smaller-side
amortization. Common mistakes include O(n^2) enumeration, incorrect boundaries,
and off-by-one errors.
