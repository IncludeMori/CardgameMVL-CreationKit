#pragma once

#include <string>
#include <vector>
#include <memory>

#include "sol\sol.hpp"

#include "StaticOptions.hpp"

#include "InputField.hpp"
#include "DropDownMenu.hpp"

using std::vector;

class ValidEntry
{
public:
	ValidEntry();
	~ValidEntry();

	vector<vector<Field>> InvalidFields(Effect effect);
	void Validate(const std::vector<std::unique_ptr<InputField>> &fields,  DropDownMenu &menu);


private:
	void ValidateMenu(const std::vector<std::unique_ptr<InputField>> &fields,  DropDownMenu &menu);
	void ValidateFields(const std::vector<std::unique_ptr<InputField>> &fields);

};

