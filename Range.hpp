#include <iterator>

class Range {
  int _start = 0;
  int _end;
  int _step = 1;

public:
  explicit Range(int end) : _end(end) {}
  Range(int start, int end) : _start(start), _end(end) {
    if (start > end) {
      _step = -1;
      _end--;
    }
  }
  Range(int start, int end, int step) : _start(start), _end(end), _step(step) {}

  class Iterator {
    using iterator_category = std::forward_iterator_tag;
    using value_type = int;

    int _num;
    int _step;

  public:
    Iterator(int num, int step) : _num(num), _step(step) {}

    Iterator &operator++() {
      _num += _step;
      return *this;
    }

    Iterator operator++(int) { return {_num += _step, _step}; }

    Iterator &operator--() {
      --_num;
      return *this;
    }

    Iterator operator--(int) { return {_num -= _step, _step}; }

    bool operator==(const Iterator &other) const { return other._num == this->_num; }

    bool operator!=(const Iterator &other) const { return !(other == *this); }

    value_type operator*() const { return _num; }
  };

  Iterator begin() { return {_start, _step}; };
  Iterator end() {
    int last = _end + (_end - _start) % _step;
    return {last, _step};
  };
};
