#pragma once

#include <string>

enum class Field : int {
	EFFECT = 0,
	EFFECT_TYPE = 1,
	TARGET = 2,
	TARGET_SPEC = 3,
	STAT = 4,
	AMOUNT = 5
};


enum class Menu_Index :int {
	ERROR = -1,
	EFFECT = 0,
	EFFECT_TYPE = 1,
	TARGET = 2,
	TARGET_SPEC = 3,
	STAT = 4,
	AMOUNT = 5

};

enum class Effect : int {
	BATTLECRY = 0,
	DEATHWISH = 1
};
enum class Effect_Type :int {
	BOOST = 0
};
enum class Target : int {
	SELF = 0,
	DECK = 1,
	FIELD = 2,
	HAND = 3
};
enum class TargetSpec :int {
	RANDOM = 0,
	ALL = 1,
	TARGET = 2
};