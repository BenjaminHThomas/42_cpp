/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:01:14 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/10 11:04:32 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"
#include "cassert"

// // Only used for testing
// bool compareFiles(const std::string& file1, const std::string& file2) {
//     std::ifstream f1(file1.c_str()), f2(file2.c_str());
//     return f1 && f2 && std::equal(std::istreambuf_iterator<char>(f1), std::istreambuf_iterator<char>(), std::istreambuf_iterator<char>(f2));
// }

// // Only used for testing
// void testReplace(const std::string& inFile, const std::string& s1, const std::string& s2) {
// 	std::ifstream in(inFile.c_str());
// 	std::ofstream out("testOut.txt");
// 	std::string line;
// 	while (std::getline(in, line)) {
// 		size_t pos = 0;
// 		while ((pos = line.find(s1, pos)) != std::string::npos) {
// 			line.replace(pos, s1.length(), s2);
// 			pos += s2.length();
// 		}
// 		out << line << '\n';
// 	}
// }

int	main(int argc, char **argv) {
	if (argc != 4)
		return (1);
	std::string	fname = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// testReplace(fname, s1, s2);
	replaceStrs(fname, s1, s2);
	// bool result = compareFiles(fname, "testOut.txt");
	std::remove("testOut.txt");
	return (0);
}