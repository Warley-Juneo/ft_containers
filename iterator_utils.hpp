#pragma once

#include "iterator_traits.hpp"

namespace ft {
  template <class InputIt>
  typename ft::iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last) {
    typename ft::iterator_traits<InputIt>::difference_type  result = 0;
    while (first <= last) {
      result++;
      first++;
    }
    return result;
  };
}