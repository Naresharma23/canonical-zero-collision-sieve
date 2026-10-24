# Canonical Sieve: Zero-Collision Disjoint Factorization

A high-performance C++ implementation and mathematical framework eliminating write collisions in integer factorization pipelines via minimal prime factor partitioning.

## Theoretical Basis & Preprint
* **Preprint Title:** Canonical Sieve Framework: Minimal Factor Partitioning
* **Zenodo Record ID:** [23590897](https://zenodo.org/records/23590897)
* **Author:** Naresh Sharma

## Empirical Verification ($X = 20,000,000$)
Classical sieves produce ~52.28% redundant memory writes due to shared composite factors. By strictly mapping composite traversal to minimal prime factors $p_{\min}(n)$, this framework guarantees strictly disjoint memory write pathways.

| Metric | Classical Sieve | Canonical Sieve |
| :--- | :--- | :--- |
| **Write Collision Redundancy** | ~52.28% | **0.00%** |
| **Total Factorizations Tested** | 8.7M Operations | **8.7M Operations** |
| **Memory Footprint** | Overlapping Rewrites | **Strictly Disjoint Writes** |

## Fast Verification (C++)
```bash
g++ -O3 -std=c++17 benchmark.cpp -o benchmark
./benchmark
