Your task is to optimize the function implemented in `src/yours.c`. The goal is to reduce the score reported by `src/run.sh` (lower is better) while preserving correctness.

### Requirements

1. **Correctness**
   
   Your implementation must remain functionally equivalent to the reference implementation `src/impl.c` as checked by `src/tester.c`.
   
   Your code must terminate and must not rely on undefined behavior.

   IMPORTANT: Your yours.c must not contain any for, while, do-while, or goto statements.

2. **What you may modify**
   - `src/yours.c`
   - The `CFLAGS` variable in `src/run.sh`
   
   You may not change `src/tester.c`, `src/impl.c`, or any other part of the evaluation environment.

3. **How scoring works**
   
   Run `bash run.sh`.
   This script will:
   - compile using clang in the expected mode
   - test correctness
   - run llvm-mca with Zen2 settings
   - print the reciprocal throughput score used for comparison

4. **Changelog**
   
   When you reach a final version, update `README.md` with:
   - a version tag
   - your final score from `run.sh`
   - a short 1-3 sentence summary of the optimizations you applied

### Branches

This repository contains multiple branches maintained by different people, each representing its own optimization lineage and explorations. You may read those branches, adopt ideas, or merge code/rebase from them if that helps. Evaluation is based solely on your final state in your own branch.
