/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:13:08 by jchartie          #+#    #+#             */
/*   Updated: 2026/08/26 18:18:19 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

void replaceLine(const std::string &buffer, std::ofstream &newFile, const std::string &s1, const std::string &s2)
{
	size_t pos = 0;

	pos = buffer.find(s1);
	if (pos == std::string::npos)
	{
		newFile << buffer;
		return ;
	}
	newFile << buffer.substr(0, pos);
	newFile << s2;
	pos += s1.length();
	replaceLine(buffer.substr(pos, buffer.length() - pos), newFile, s1, s2);
}

int ft_error(std::string str)
{
	std::cerr << str << std::endl;
	return 1; 
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return ft_error("Wrong number of arguments");

	std::string buffer;
	std::string fileIn = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string fileOut = fileIn + ".replace";
	
	std::ifstream oldFile(fileIn.c_str());
	std::ofstream newFile(fileOut.c_str());
	if (!oldFile || !newFile)
		return ft_error(strerror(errno));
	if (s1.empty() || s2.empty())
		return ft_error("Error: Empty string");

	while (std::getline(oldFile, buffer))
	{
		replaceLine(buffer, newFile, s1, s2);
		newFile << "\n";
	}
	return 0;
}