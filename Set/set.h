#include <algorithm>
#include <vector>

class Set {
 public:
  Set() { this->data.resize(0); }

  explicit Set(const std::vector<int64_t>& other) {
    this->data.assign(other.begin(), other.end());

    std::sort(this->data.begin(), this->data.end());

    auto itr = std::unique(this->data.begin(), this->data.end());

    this->data.resize(std::distance(this->data.begin(), itr));

    this->len = this->data.size();
  }

  Set Union(const Set& other) const {
    std::vector<int64_t> union_set;

    std::set_union(this->data.begin(), this->data.end(), other.data.begin(),
                   other.data.end(), std::back_inserter(union_set));

    return Set(union_set);
  }

  Set Intersection(const Set& other) const {
    std::vector<int64_t> intersection_set;

    std::set_intersection(this->data.begin(), this->data.end(),
                          other.data.begin(), other.data.end(),
                          std::back_inserter(intersection_set));

    return Set(intersection_set);
  }

  Set Difference(const Set& other) const {
    std::vector<int64_t> difference_set;

    std::set_difference(this->data.begin(), this->data.end(),
                        other.data.begin(), other.data.end(),
                        std::back_inserter(difference_set));

    return Set(difference_set);
  }

  Set SymmetricDifference(const Set& other) const {
    std::vector<int64_t> symmetric_difference_set;

    std::set_symmetric_difference(this->data.begin(), this->data.end(),
                                  other.data.begin(), other.data.end(),
                                  std::back_inserter(symmetric_difference_set));

    return Set(symmetric_difference_set);
  }

  void Add(int64_t digit) {
    if (!Contains(digit)) {
      this->data.push_back(digit);

      std::sort(this->data.begin(), this->data.end());

      this->len++;
    }
  }

  void Remove(int64_t digit) {
    if (Contains(digit)) {
      this->data.erase(std::find(data.begin(), data.end(), digit));
    }
  }

  bool Contains(int64_t digit) const {
    auto it = std::find(this->data.begin(), this->data.end(), digit);

    if (it != this->data.end()) {
      return true;
    } else {
      return false;
    }
  }

  std::vector<int64_t> Data() const { return this->data; }

  void show() {
    for (int64_t i : this->data) std::cout << i << " ~";
  }

 private:
  std::vector<int64_t> data;
  int len;
};
