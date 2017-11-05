#ifndef CDF_H
#define CDF_H

#include <random>
#include <vector>
#include <chrono>

class UniformCdf {
public:
  UniformCdf() : _eng(), _dist(0L, 1L) {};
  UniformCdf(const unsigned & s) : _eng(s), _dist(0L, 1L) {};

  void seed() {
    unsigned seed1 =
      std::chrono::system_clock::
        now().time_since_epoch().count();
    _eng.seed(seed1);
  };

  void seed(const unsigned & s) {
    _eng.seed(s);
  };

  void setProbabilities(const std::vector<double> p) {
    _probabilities = p;
    calcCdf();
  };

  const std::vector<double> & getCdf() { return _cdf; };

  size_t getChoice() {
    double rv = _dist(_eng);
    for (size_t i = 0; i < _cdf.size(); i++) {
      if (rv <= _cdf[i]) {
        return i;
      }
    }
    exit(1);
  };

private:
  std::default_random_engine _eng;
  std::uniform_real_distribution<double> _dist;
  std::vector<double> _probabilities;
  std::vector<double> _cdf;

  void calcCdf () {
    _cdf.resize(_probabilities.size());
    double cumul = 0;
    for (size_t i = 0; i < _probabilities.size(); i++) {
      cumul += _probabilities[i];
      _cdf[i] = cumul;
    }
    for (size_t i = 0; i < _cdf.size(); i++) {
      _cdf[i] /= cumul;
    }
  };

};


#endif // CDF_H
