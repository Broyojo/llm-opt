# Changelog

## v0.0.1
Initial baseline implementation.
Score: 243.8
Simple, straightforward version with no optimizations.

## v0.0.2
Score: 129.8
Cached limb values in registers and enabled aggressive optimization flags (O3/fast-math, frame-pointer and unwind table removal) to reduce load traffic and overhead in the unrolled modular multiplication.
