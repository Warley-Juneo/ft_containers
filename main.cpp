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

#include "vector.hpp"
#include <iostream>

int main() {
	ft::vector<int> first;
	ft::vector<int> second(4, 100);
	for (size_t i = 0; i < second.size(); i++) {
		std::cout << second[i] << " ";
	}
	std::cout << std::endl;
	// ft::vector<int> third(second.begin(), second.end());
	// ft::vector<int> fourth (third);

	// the iterator constructor can also be used to construct from arrays:
	// int myints[] = {5, 9, 16, 19};
	// ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	// std::cout << "The contents of fifth are:";
	// for (ft::vector<int>::iterator it = fifth.begin(); it !=  fifth.end(); ++i);
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	return 0;
}
