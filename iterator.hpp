#pragma once

#include <cstddef>

// talvez essa seja a iterator;

namespace ft {
  template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
  class iterator {

  typedef typename iterator_category      Category;
  typedef typename value_type             T;
  typedef typename difference_type        Distance;
  typedef typename pointer                Pointer;
  typedef typename reference              Reference;
  
  public:
    explicit iterator(T *it) : _it(it){};
    ~iterator(){};

    /////////////////// Dereference operator ///////////////////
    T &operator*() const {
      return *_it;
    };
    /////////////////////////////////////////////////////////

    /////////////////// Increment / Decrement ///////////////////
    iterator &operator++() {
      ++_it;
      return *this;
    };

    iterator operator++(int) {
      T temp;

      temp = this->_it;
      this->_it++;
      return temp;
    };

    iterator &operator--() {
      --_it;
      return *this;
    };

    iterator operator--(int) {
      T temp;

      temp = this->_it;
      this->_it--;
      return temp;
    };
    /////////////////////////////////////////////////////////

    /////////////////// Equivalence operators ///////////////////
    bool operator!=(const iterator &other) const {
      return _it != other._it;
    };
    bool operator==(const iterator &other) const {
      return _it == other._it;
    };
    /////////////////////////////////////////////////////////

    /////////////////// Relational Operators ///////////////////
    bool operator<(const iterator &other) const {
      return _it < other._it;
    };
    bool operator>(const iterator &other) const {
      return _it > other._it;
    };
    bool operator<=(const iterator &other) const {
      return _it <= other._it;
    };
    bool operator>=(const iterator &other) const {
      return _it >= other._it;
    };
    /////////////////////////////////////////////////////////

    /////////////////// Assignment Operations ///////////////////
    iterator &operator+=(const int &n) {
      _it += n;
      return *this;
    };
    iterator &operator-=(const int &n) {
      _it -= n;
      return *this;
    }
    /////////////////////////////////////////////////////////
  private:
    T *_it;
  };
}
