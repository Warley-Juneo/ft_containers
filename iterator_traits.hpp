#pragma once

#include "iterator.hpp"
#include <cstddef>

namespace ft {
	template <class Iter>
	struct iterator_traits {
		typedef typename difference_type 			Iter::difference_type;
		typedef typename value_type 					Iter::value_type;
		typedef typename pointer 							Iter::pointer;
		typedef typename reference 						Iter::reference;
		typedef typename iterator_category 		Iter::iterator_category;
	};

	template <class T>
	struct iterator_traits<T*> {
		typedef typename difference_type 				std::ptrdiff_t;
		typedef typename value_type 						T;
		typedef typename pointer 								const T *;
		typedef typename reference 							const T &;
		// typedef typename iterator_category   ft::random_access_iterator_tag;
		// typedef typename iterator_concept    ft::contiguous_iterator_tag;
	};

	template <class T>
	struct iterator_traits<const T*> {
		typedef typename difference_type 				std::ptrdiff_t;
		typedef typename difference_type 				T;
		typedef typename pointer const 					T*;
		typedef typename reference const 				T&;
		// typedef typename iterator_category   std::random_access_iterator_tag;
	};
}