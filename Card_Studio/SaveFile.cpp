#include "SaveFile.hpp"

#include <fstream>
#include <iostream>

bool SaveFile::save(const std::string &name, std::vector<std::string> &lines)
{
	std::ofstream file;
	file.open(name);

	std::cout << "Save File: " << name << std::endl;

	for (size_t i = 0; i < lines.size(); i++)
		file << lines[i];

	file.close();
	return true;
}