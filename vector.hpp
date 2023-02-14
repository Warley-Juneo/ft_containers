#pragma once

#include <memory>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <new>


#include "iterator.hpp"
#include "iterator_utils.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		typedef T																								value_type;
		typedef typename Allocator::pointer											pointer;
		typedef typename Allocator::const_pointer         			const_pointer;
    typedef typename Allocator::reference         					reference;
    typedef typename Allocator::const_reference   					const_reference;
		typedef size_t																					size_type;
		typedef Allocator																				allocator_type;
		typedef typename ft::iterator<pointer>									iterator;

		public:
			explicit vector(const allocator_type &alloc = allocator_type()) {
				_alloc = alloc;
				_sizeT = 0;
				_valueT = 0;
				_data = NULL;
			};

			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type& alloc = allocator_type()) {
				_sizeT = n;
				_valueT = val;
				_alloc = alloc;

				try {
					if (_sizeT > _alloc.max_size()) {
						throw std::bad_alloc();
					}
					_data = _alloc.allocate(n);
					for (size_type it = 0; it < n; it++) {
						_alloc.construct(_data + it, val);
					}
				}
				catch (std::bad_alloc& e) {
					std::cerr << "Error: Memory allocation failure: " << e.what() << std::endl;
				}
			};
			
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()) {
				size_type n = ft::distance(first, last);
				_sizeT = n;
				_alloc = alloc;

				try {
					if (_sizeT > _alloc.max_size()) {
						throw std::bad_alloc();
					}
					_data = _alloc.allocate(n);
					for (size_type it = 0; it < n; it++, ++first) {
						_alloc.construct(_data + it, *first);
					}
				} catch (std::bad_alloc& e) {
					std::cerr << "Error: Memory allocation failure: " << e.what() << std::endl;
				}
			}

			// vector(const vector &src);


			T &operator[](size_type idx) {
				return _data[idx];
			};

			size_type size() const {
				return _sizeT;
			};

			iterator begin() {
				return iterator(_data);
			};

			iterator end() {
				return iterator(_data + _sizeT);
			};

		~vector() {
			for (size_t current_pos = _sizeT; current_pos != 0; current_pos--) {
				_alloc.destroy(_data + _sizeT - 1);
			}
			_alloc.deallocate(_data, _sizeT);
			_sizeT = 0;
			_valueT = 0;
		}
		protected:
			std::allocator<T> 		_alloc;
			size_type							_sizeT;
			value_type						_valueT;
			pointer								_data;

	};
}

