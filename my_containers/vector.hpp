#pragma once

#include <memory>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <new>


#include "../random_access_iterator.hpp"
#include "../iterator_utils.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/is_integral.hpp"
#include "../reverse_iterator.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {

		public:
			typedef T																															value_type;
			typedef Allocator																											allocator_type;
			typedef typename Allocator::reference         												reference;
			typedef typename Allocator::pointer																		pointer;
			typedef typename Allocator::const_pointer         										const_pointer;
			typedef typename Allocator::const_reference   												const_reference;
			typedef typename ft::random_access_iterator<pointer>									iterator;
			typedef typename ft::random_access_iterator<const_pointer> 						const_iterator;
			typedef typename ft::random_access_iterator<iterator>									reverse_iterator;
			typedef typename ft::random_access_iterator<const_iterator>						const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type				difference_type;
			typedef size_t																												size_type;

		/////////////////////////// Construtores ///////////////////////////
			explicit vector(const allocator_type &alloc = allocator_type()) {
				_alloc = alloc;
				_sizeT = 0;
				_capacityT = 0;
				_data = NULL;
			};

			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type& alloc = allocator_type()) {
				_sizeT = n;
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
			vector(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0, const allocator_type &alloc = allocator_type()) {
				size_type n = ft::distance(first, last);
				_sizeT = n;
				_capacityT = n;
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
			};

			vector(const vector &src) {
				_sizeT = 0;
				_alloc = src._alloc;
				_capacityT = 0;
				_data = NULL;

				*this = src;
			};

			vector &operator=(const vector& src) {
				if (this == &src) {
					return *this;
				}
				_sizeT = src._sizeT;
				_alloc = src._alloc;
				_capacityT = src._valueT;
				_data = _alloc.allocate(_sizeT);

				for (size_type it = 0; it < _sizeT; it++) {
					_alloc.construct(_data + it, src._data[it]);
				}
				return *this;
			};

			///////////////////////// Iterators /////////////////////////
			iterator begin() {
				return iterator(_data);
			};

			const_iterator begin() const {
				return const_iterator(_data);
			};

			iterator end() {
				return iterator(_data + _sizeT);
			};

			const_iterator end() const {
				return const_iterator(_data + _sizeT);
			};

			reverse_iterator rbegin() {
				return reverse_iterator(end());
			};

			reverse_iterator	rend() {
				return reverse_iterator(begin());
			};

			//////////////////////////// Capacity /////////////////////////
			size_type size() const {
				return _sizeT;
			};

			size_type max_size() const {
				return _capacityT;
			};


			void resize (size_type n, value_type val = value_type()) {
				if (n < _sizeT) {
					for (size_type i = n; i < _sizeT; i++) {
						_alloc.destroy(_data + i);
					}
					_sizeT = n;
				}
				else if (n > _sizeT) {
					if (n > _capacityT) {
						reserve(n);
					}
					for (size_type i = _sizeT; i < n; i++) {
						_alloc.construct(_data +i, val);
					}
					_sizeT = n;
				}
			};

			bool empty() const {
				return this->_sizeT == 0;
			};

			void reserve(size_type n) {
				value_type* newData = allocator.allocate(n);
				for (size_type i = 0; i < _sizeT; ++i) {
					allocator.construct(newData + i, _data[i]);
					allocator.destroy(_data + i);
				}
				allocator.deallocate(_data, _capacityT);
				_data = newData;
				_capacityT = n;
			};

			/////////////////////////// Element Access /////////////////////
			T &operator[](size_type idx) {
				return _data[idx];
			};

			reference at (size_type n) {
				if ( n < 0 || n >= _sizeT) {
					throw std::out_of_range("Index out of range");
				}
				return _data[n];
			};

			const_reference at(size_type n) const {
				if (n < 0 || n >= _sizeT) {
					throw std::out_of_range("index out of range");
				}
				return _data[n];
			};

			reference front() {
				return _data[0];
			};

			const_reference front() const {
				return _data[0];
			};

			reference back() {
				return _data[_sizeT - 1];
			};

			const_reference back() const {
				return _data[_sizeT - 1];
			};

			~vector() {
				for (size_t current_pos = _sizeT; current_pos != 0; current_pos--) {
					_alloc.destroy(_data + _sizeT - 1);
				}
				_alloc.deallocate(_data, _capacityT);
				_sizeT = 0;
				_capacityT = 0;
			};

		protected:
			std::allocator<T> 		_alloc;
			size_type							_sizeT;
			size_type							_capacityT;
			pointer								_data;
	};
}

