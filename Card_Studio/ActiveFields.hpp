#pragma once

#include <vector>

#include "StaticOptions.hpp"

class ActiveFields
{
public:
	ActiveFields();
	~ActiveFields();

	std::vector<Field> getFields(Effect effect, Effect_Type effect_type, Target target);
};

