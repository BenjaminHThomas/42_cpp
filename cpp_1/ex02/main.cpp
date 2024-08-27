/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:47:23 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/27 15:04:16 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void) {
	std::string	msg = "HI THIS IS BRAIN";
	std::string* ptr = &msg;
	std::string& ref = msg;

	std::cout
	<< "msg address: " << &msg << std::endl
	<< "ptr address: " << &ptr << std::endl
	<< "ref address: " << &ref << std::endl
	<< std::endl
	<< "msg val: " << msg << std::endl
	<< "ptr val: " << *ptr << std::endl
	<< "ref val: " << ref << std::endl;
	return (0);
}