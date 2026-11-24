# The Minimum Hinge

This package contains a competitive-programming problem about hinged subarrays.
It includes an efficient C++ solution, a brute-force implementation, test cases,
and three candidate solutions with common mistakes.

## Running the solution

Compile the solution with g++:

```bash
g++ -std=c++17 -O2 -pipe -static -s solution.cpp -o solution
```

Then provide an input file:

```bash
./solution < test_cases/4.in
```

## Testing

The `9.in` test case is large and designed to catch quadratic solutions.
Use `solution_bf.cpp` only for small randomized or brute-force comparisons.

## Important Qwen requirement

The assessment requires real Qwen3-235B-A22B-2507 shared conversation links
with thinking disabled. This package does not create or fabricate those links.
After running Qwen, add the three real shared links to `qwen/conversations.md`.
