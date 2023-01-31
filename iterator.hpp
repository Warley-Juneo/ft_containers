#pragma once

#include "vector.hpp"

template <typename T>
class iterator {
	public:
		iterator(ft::vector<T>::iterator it) : _it(it) {};
		~iterator() {};

		T &operator*() const {
			return *_it;
		};

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

		bool operator!=(const iterator &other) const {
			return _it != other._it;
		};

		bool operator==(const iterator &other) const {
			return _it == other._it;
		};

		iterator begin() {
			return iterator(_data.begin());
		};
	protected:
		std::vector<T>::iterator _it;
		std::vector<T>					_data;
};
