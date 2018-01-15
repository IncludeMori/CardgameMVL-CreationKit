#pragma once

#include <vector>
#include <string>

class SaveFile
{
public:
	bool save(const std::string &name, std::vector<std::string> &lines);
};

