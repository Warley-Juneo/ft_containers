#pragma once

#include "iterator_traits.hpp"

namespace ft {
  template <class InputIt>
  typename ft::iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last) {
    return last - first;
  };
}