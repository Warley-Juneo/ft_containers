#pragma once
namespace ft {
  template<typename T>
  struct is_integral {
    static const bool value = false;
  };
  template<>
  struct is_integral<bool> {
    static const bool value = true;
  };
  template<>
  struct is_integral<char> {
    static const bool value = true;
  };
  template<>
  struct is_integral<unsigned char> {
    static const bool value = true;
  };
  template<>
  struct is_integral<int> {
    static const bool value = true;
  };
  template<>
  struct is_integral<const int> {
    static const bool value = true;
  };
  template<>
  struct is_integral<const long int> {
    static const bool value = true;
  };
  template<>
  struct is_integral<unsigned long int> {
    static const bool value = true;
  };
  template<>
  struct is_integral<const unsigned long int> {
    static const bool value = true;
  };
}