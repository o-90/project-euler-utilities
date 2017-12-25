/*
 * optimized version of Sieve of Eratosthenes
 * see http://primesieve.org/segmented_sieve.html
 */

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdint.h>

const int L1D_CACHE_SIZE = 32768;


std::vector<int> segmented_sieve(int64_t limit) {
  int sqrt = (int) std::sqrt(limit);
  int segment_size = std::max(sqrt, L1D_CACHE_SIZE);

  int64_t count = (limit < 2) ? 0 : 1;
  int64_t s = 3;
  int64_t n = 3;

  // generate small primes <= sqrt
  std::vector<char> is_prime(sqrt + 1, 1);
  for (int i = 2; i * i <= sqrt; i++)
    if (is_prime[i])
      for (int j = i * i; j <= sqrt; j += i)
        is_prime[j] = 0;

  // vector used for sieving
  std::vector<int> v;
  std::vector<char> sieve(segment_size);
  std::vector<int> primes;
  std::vector<int> next;

  for (int64_t low = 0; low <= limit; low += segment_size) {
    std::fill(sieve.begin(), sieve.end(), 1);

    // current segment = interval [low, high]
    int64_t high = std::min(low + segment_size - 1, limit);

    // add new sieving primes <= sqrt(high)
    for (; s * s <= high; s += 2) {
      if (is_prime[s]) {
        primes.push_back((int) s);
          next.push_back((int)(s * s - low));
      }
    }

    // sieve the current segment
    for (std::size_t i = 0; i < primes.size(); i++) {
      int j = next[i];
      for (int k = primes[i] * 2; j < segment_size; j += k)
        sieve[j] = 0;
      next[i] = j - segment_size;
    }

    for (; n <= high; n += 2)
      if (sieve[n - low]) { // n is a prime
        v.push_back(n);
        count++;
      }
  }
  // std::cout << count << " primes found." << std::endl;
  return v;
}

// Usage: ./sieve n
// @param n  Sieve the primes up to n.
int main() {
  int64_t n;
  std::vector<int> p;
  std::cin >> n;
  p = segmented_sieve(n);
  for (int i=0; i<p.size(); i++) {
    std::cout << p[i] << ", ";
  }
  std::cout << '\n';
  return 0;
}

