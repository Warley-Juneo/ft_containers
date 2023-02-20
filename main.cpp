/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:46:55 by wjuneo-f          #+#    #+#             */
/*   Updated: 2023/01/31 12:36:58 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./my_containers/vector.hpp"
#include <iostream>
#include "utils/equal.hpp"
#include "utils/pair.hpp"

	// the iterator constructor can also be used to construct from arrays:
	// int myints[] = {5, 9, 16, 19};
	// ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int));
	// for (ft::vector<int>::iterator it = fifth.begin(); it !=  fifth.end(); ++it) {
	// 	std::cout << ' ' << *it;
	// }
	// std::cout << '\n';
	// std::cout << '\n';
	// return 0;

	////////////////////////////////////////////////////////////////////////////////
	// bool mypredicate (int i, int j) {
  // return (i==j);

	// int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
  // ft::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

  // // using default comparison:
  // if ( ft::equal (myvector.begin(), myvector.end(), myints) )
  //   std::cout << "The contents of both sequences are equal.\n";
  // else
  //   std::cout << "The contents of both sequences differ.\n";

  // myvector[3]= 81;                                 // myvector: 20 40 60 81 100

  // // using predicate comparison:
  // if ( ft::equal (myvector.begin(), myvector.end(), myints, &mypredicate) )
  //   std::cout << "The contents of both sequences are equal.\n";
  // else
  //   std::cout << "The contents of both sequences differ.\n";

  // return 0;

int main () {
	return (0);
}
