#pragma once

#include <type_traits>

namespace ft {
	template<class Iterator>
	class reverse_iterator {
		protected:
			Iterator	_rIt;

		public:
			typedef	Iterator iterator_type;
			typedef	typename iterator_traits<Iterator>::iterator_category iterator_category;
			typedef	typename iterator_traits<Iterator>::value_type value_type;
			typedef	typename iterator_traits<Iterator>::difference_typ difference_type;
			typedef	typename iterator_traits<Iterator>::pointer pointer;
			typedef	typename iterator_traits<Iterator>::reference reference;

		public:
			reverse_iterator() : _rIt(NULL) {};
			explicit reverse_iterator(iterator_type it) : _rIt(it) {};
			template <class Iter>
			reverse_iterator	(const reverse_iterator<Iterator>& rev_it) {
				*this = rev_it;
			};

			reverse_iterator &operator=(const reverse_iterator<Iterator>& rev_it) {
				this->_rIt = rev_it._rIt;
				return (*this);
			};

			iterator_type base() const { return _rIt; };
		};
};
