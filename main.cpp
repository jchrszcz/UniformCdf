#include <iostream>

#include "UniformCdf.h"

int main () {

  const size_t TESTS = 3;
  const size_t N = 10000;
  UniformCdf cdf;
  cdf.seed();
  std::vector<double> probabilities = {0.2, 0.1, 0.7};
  cdf.setProbabilities(probabilities);

  for (size_t tests = 0; tests < TESTS; tests++) {
    std::cout << "Tests: " << tests+1 << std::endl;

    std::vector<double> bucket(probabilities.size(),0);

    for (size_t i = 0; i < N; i++) {
      bucket[cdf.getChoice()]++;
    }

    for (size_t i = 0; i < bucket.size(); i++) {
      std::cout << "Bucket " << i << ": " << bucket[i] << std::endl;
    }

    std::cout << std::endl;
  }

  return 0;
}
