#include "ActiveFields.hpp"



ActiveFields::ActiveFields()
{
}


ActiveFields::~ActiveFields()
{
}

std::vector<Field> ActiveFields::getFields(Effect effect,Effect_Type effect_type, Target target)
{
	std::vector<Field> myFields;

	switch (effect)
	{
	case(Effect::BATTLECRY):
		myFields.push_back(Field::TARGET);
		myFields.push_back(Field::TARGET_SPEC);
		myFields.push_back(Field::STAT);
		myFields.push_back(Field::AMOUNT);
		break;
	}
	return myFields;
}
