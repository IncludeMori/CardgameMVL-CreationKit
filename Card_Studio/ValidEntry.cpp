#include "ValidEntry.hpp"

#include "eCardData.hpp"
#include <iostream>

using std::string;

#define CHANGE_LATER Field
//field:
//return field ,cast to int and deactivatge field in FileList (same index)
//specific option:
//FUCK

ValidEntry::ValidEntry()
{
	/*
	//Effects
	vector<CHANGE_LATER> Battlecry = {   };
	vector<CHANGE_LATER> Deathwish = {   };

	vector<vector<CHANGE_LATER>> Effect = { Battlecry,Deathwish };
	NotValidEntries.push_back(Effect);

	//EffectSpec
	vector<CHANGE_LATER> Boost = {};

	vector<vector<CHANGE_LATER>> EffectSpec = { Boost };
	NotValidEntries.push_back(EffectSpec);

	//Target
	vector<CHANGE_LATER> Self = {Field::TARGET_SPEC};
	vector<CHANGE_LATER> Deck = {};
	vector<CHANGE_LATER> GameField= {};
	vector<CHANGE_LATER> Hand = {};

	vector<vector<CHANGE_LATER>> Target = {Self,Deck,GameField,Hand};
	NotValidEntries.push_back(Target);

	//Target Spec
	vector<CHANGE_LATER> Random = {};
	vector<CHANGE_LATER> All = {};
	vector<CHANGE_LATER> ChoseTarget = {};

	vector<vector<CHANGE_LATER>> TargetSpec = { Random,All,ChoseTarget };
	NotValidEntries.push_back(TargetSpec);
	*/
}


ValidEntry::~ValidEntry()
{
}
//string übergeben, Methode toString schreiben, vergleichen, nach Bedarf Feld deactivieren bzw String entfernen
//ODER string anstatt feld benutzen


void ValidEntry::Validate(const std::vector<std::unique_ptr<InputField>>& fields, DropDownMenu &menu)
{
	ValidateFields(fields);
	ValidateMenu(fields,menu);
}

void ValidEntry::ValidateMenu(const std::vector<std::unique_ptr<InputField>> &fields,DropDownMenu & menu)
{
	if (fields.at(TARGET - 5)->AsString() != "Field")
	{
		//remove "Target" from DropDownMenu
		menu.deactivateOption(Menu_Index::TARGET_SPEC, "Target");
	}
	else
		menu.deactivateOption(Menu_Index::EFFECT, "");
}

void ValidEntry::ValidateFields(const std::vector<std::unique_ptr<InputField>>& fields)
{
	//set all active / reset
	for (int i = 1; i < 5; i++)
		fields[i]->set(true);

	//effect
	if (fields.at(EFFECT - 5)->AsString() == "No Effect")
	{
		for (int i = 1; i < 5; i++)
			fields[i]->set(false);
	}


	//effect type

	//target
	if (fields.at(TARGET - 5)->AsString() == "Self")
		fields.at(TARGET_SPEC - 5)->set(false);
}

