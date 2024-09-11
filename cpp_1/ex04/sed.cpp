/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:44:27 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/11 10:48:07 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

void	replaceWord(std::string& replacement,
					std::string s1, std::string s2, std::string::size_type& i) {
	replacement += s2;
	i += (std::string::size_type)s1.size() - 1;
}

bool	isS1(std::string line, std::string s1, std::string::size_type i) {
	return (line.substr(i, s1.size()) == s1);
}

void	replaceStrs(std::string fname, std::string s1, std::string s2) {
	std::string	replacement;
	std::string	line;
	std::ifstream inFile(fname);

	if (!inFile) {
		std::cerr << "Error: could not open file '" << fname << "'.\n";
		return ;
	}
	while (std::getline(inFile, line)) {
		for (std::string::size_type i = 0; i < line.size(); ++i) {
			if (isS1(line, s1, i)) {
				replaceWord(replacement, s1, s2, i);
			}
			else {
				replacement += line[i];
			}
		}
		replacement += "\n";
	}
	inFile.close();
	std::ofstream outFile(fname + ".replace");
	outFile << replacement;
	outFile.close();
}