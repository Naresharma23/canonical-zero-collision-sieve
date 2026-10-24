#include <iostream>
#include <vector>
#include <chrono>

int main() {
    const int X = 20000000;
    std::vector<int> min_factor(X + 1, 0);
    std::vector<int> primes;
    primes.reserve(1300000);

    long long total_factorizations = 0;
    long long collisions = 0;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 2; i <= X; ++i) {
        if (min_factor[i] == 0) {
            min_factor[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > min_factor[i] || (long long)i * p > X) {
                break;
            }
            int composite = i * p;
            if (min_factor[composite] != 0) {
                collisions++;
            }
            min_factor[composite] = p;
            total_factorizations++;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "--- Canonical Sieve Verification ---" << std::endl;
    std::cout << "Range (X): " << X << std::endl;
    std::cout << "Factorizations: " << total_factorizations << std::endl;
    std::cout << "Write Collisions: " << collisions << " (0.00%)" << std::endl;
    std::cout << "Execution Time: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
