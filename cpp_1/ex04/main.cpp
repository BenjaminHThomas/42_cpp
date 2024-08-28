/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:01:14 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/28 13:20:45 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int	main(int argc, char **argv) {
	if (argc != 4)
		return (1);
	std::string	fname = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	replaceStrs(fname, s1, s2);
	return (0);
}