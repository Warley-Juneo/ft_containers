#pragma once

#include <memory>
#include <cstddef>
#include <exception>

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		typedef T						value_type;
		typedef size_t			size_type;
		typedef Allocator		allocator_type;

		public:
			explicit vector(const allocator_type &alloc = allocator_type()) {
				_size = 0;
				_alloc = alloc;
			};

			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) {
				_size = n;
				_valueT = val;
				_alloc = alloc;

				for (int i = 0; n < i; i--) {
					_vector[i] = val;
				}
			};

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());

			vector(const vector &src);

		protected:
			std::allocator<T> _alloc;
			size_type					_size;
			value_type				_valueT;
			T									_vector;
	};
}

