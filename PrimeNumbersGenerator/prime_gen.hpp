class PrimeNumberGenerator {
 public:
  explicit PrimeNumberGenerator(int start) { this->start = start; }

  int GetNextPrime() {
    int tmp = this->start;

    if (tmp <= 2) {
      this->start = 3;

      return 2;
    }

    if (isPrime(tmp)) {
      this->start = tmp + 2;

      return tmp;
    }

    if (tmp % 2 == 0) tmp++;

    while (!isPrime(tmp)) {
      tmp += 2;
    }

    this->start = tmp + 2;

    return tmp;
  }

 private:
  int start;

  bool isPrime(int n) {
    if (n <= 1) return false;

    if (n == 2) return true;

    if (n % 2 == 0) return false;

    int limit = sqrt(n);

    for (int i = 3; i <= limit; i += 2) {
      if (n % i == 0) return false;
    }

    return true;
  }
};
