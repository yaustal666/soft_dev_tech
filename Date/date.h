class Date {
 public:
  explicit Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;

    this->leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
  }

  bool IsLeap() const { return this->leap; }

  std::string ToString() const {
    return (this->day < 10 ? "0" : "") + std::to_string(this->day) + "." +
           (this->month < 10 ? "0" : "") + std::to_string(this->month) + "." +
           (this->year < 10     ? "000"
            : this->year < 100  ? "00"
            : this->year < 1000 ? "0"
                                : "") +
           std::to_string(this->year);
  }

  Date DaysLater(int days) const {
    int jdn = JDN(*this) + days;

    return JDN_to_date(jdn);
  }

  int DaysLeft(const Date& date) const {
    int jdn1 = JDN(*this);
    int jdn2 = JDN(date);

    return jdn2 - jdn1;
  }

 private:
  int year, month, day;
  bool leap;

  int JDN(const Date& dt) const {
    int a = std::floor((14 - dt.month) / 12);
    int y = dt.year + 4800 - a;
    int m = dt.month + 12 * a - 3;

    int JDN = dt.day + std::floor((153 * m + 2) / 5) + 365 * y +
              std::floor(y / 4) - std::floor(y / 100) + std::floor(y / 400) -
              32045;

    return JDN;
  }

  Date JDN_to_date(int jdn) const {
    int a = jdn + 32044;
    int b = std::floor((4 * a + 3) / 146097);
    int c = a - std::floor(146097 * b / 4);
    int d = std::floor((4 * c + 3) / 1461);
    int e = c - std::floor(1461 * d / 4);
    int m = std::floor((5 * e + 2) / 153);

    int year = 100 * b + d - 4800 + std::floor(m / 10);
    int month = m + 3 - 12 * std::floor(m / 10);
    int day = e - std::floor((153 * m + 2) / 5) + 1;

    return Date(year, month, day);
  }
};