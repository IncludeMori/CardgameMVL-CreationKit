#include "OpenFile.hpp"

#include <iostream>
#include <fstream>
#include <string>

std::vector<std::string> OpenFile::getFile(const std::string &name)
{
	std::ifstream file;
	file.open(name);
	
	std::cout << "Open File: " << name << std::endl;

	std::vector<std::string> lines;

	char X[30];

	if (file.is_open())
	{
		while (!file.eof())
		{
			file.getline(X, 30);
			std::string Y(X);
			lines.push_back(Y);
		}
	}
	file.close();
	
		return lines;
}