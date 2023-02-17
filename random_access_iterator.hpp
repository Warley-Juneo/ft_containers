#pragma once

#include <cstddef>
#include "iterator_traits.hpp"

namespace ft {
  template <class T>
  class random_access_iterator : public iterator<std::random_access_iterator_tag, T>{

  public:
    typedef T                                               iterator_type;
    typedef typename iterator_traits<T>::value_type         value_type; 
    typedef typename iterator_traits<T>::difference_type    difference_type;
    typedef typename iterator_traits<T>::pointer            pointer;
    typedef typename iterator_traits<T>::reference          reference;

  public:
    explicit random_access_iterator() : _it(NULL) {};
    explicit random_access_iterator(T it) : _it(it){};
    ~random_access_iterator(){};


    /////////////////// Dereference operator ///////////////////
    reference operator*() const {
      return *_it;
    };
    /////////////////////////////////////////////////////////

    T* getIterator() const {
      return (_it);
    };
    /////////////////// Increment / Decrement ///////////////////
    random_access_iterator operator+(const difference_type& n) const {
      return (random_access_iterator(_it + n)); 
    };

    random_access_iterator operator-(const difference_type& n) const {
      return (random_access_iterator(_it - n));
    };
    
    random_access_iterator &operator++() {
      ++_it;
      return *this;
    };

    random_access_iterator operator++(int) {
      return (random_access_iterator(_it++));
    };

    // random_access_iterator &operator--() {
    //   --_it;
    //   return *this;
    // };

    // random_access_iterator operator--(int) {
    //   T temp;

    //   temp = this->_it;
    //   this->_it--;
    //   return temp;
    // };
    /////////////////////////////////////////////////////////

    /////////////////// Equivalence operators ///////////////////
    bool operator!=(const random_access_iterator &other) const {
      return _it != other._it;
    };
    // bool operator==(const random_access_iterator &other) const {
    //   return _it == other._it;
    // };
    /////////////////////////////////////////////////////////

    /////////////////// Relational Operators ///////////////////
    // bool operator<(const random_access_iterator &other) const {
    //   return _it < other._it;
    // };
    // bool operator>(const random_access_iterator &other) const {
    //   return _it > other._it;
    // };
    bool operator<=(const random_access_iterator &other) const {
      return _it <= other._it;
    };
    // bool operator>=(const random_access_iterator &other) const {
    //   return _it >= other._it;
    // };
    /////////////////////////////////////////////////////////

    /////////////////// Assignment Operations ///////////////////
    // random_access_iterator &operator+=(const int &n) {
    //   _it += n;
    //   return *this;
    // };
    // random_access_iterator &operator-=(const int &n) {
    //   _it -= n;
    //   return *this;
    // }
    /////////////////////////////////////////////////////////
  protected:
    iterator_type   _it;
  };
}
