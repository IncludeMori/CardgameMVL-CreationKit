#pragma once

#include <vector>
#include <string>
#include <memory>
#include "CardInfo.hpp"
#include "EventHandler.hpp"
#include "TTF_Text.hpp"
#include "InputHandler.hpp"

#include "DropDownMenu.hpp"
#include "EffectOptions.hpp"

#include "ActiveFields.hpp"

#include "InputField.hpp"

using std::vector;
using std::string;

#define DROP_DOWN_DATA std::vector<std::unique_ptr<TTF_Text>>
#define INFO_TEXT TTF_Text

class FileList
{
public:
	FileList(const string &path, vector<std::string> &list);
	~FileList();

	void update(SDL_Event &e);

	void render();

	void reset();

private:
	INFO_TEXT Dev_Comment[2];

	EventHandler EventH;

	string mFilePath, mImagePath;

	vector<std::string> mFileName; //File names
	vector<std::unique_ptr<CardInfo>> CardData; //actual card data
	int activeFile; //current file

	vector<std::unique_ptr<TTF_Text>> mInputLabel; //Input labels

	std::vector<std::unique_ptr<InputField>> Drop_InputField;

	DropDownMenu DropMenu; 
	Menu_Index mCurrentMenu = Menu_Index::ERROR;

	Text CurrentData[6]; //user changeable data with dynamic Text rendering

	SDL_Rect User_InputField[20]; //Input field data
	
	int activeField; //current active field
	DefaultTexture FileArrow; //points towards current used field
	bool Keyboard_Input = false; //Keyboard input needed?
	string modFileData = ""; //new,modified data
	string oldData = ""; //backup
	InputHandler IHandler; //

	DefaultTexture mSaveBtn;

	//functions
	void initUserInput();
	void initDropDownMenu();

	void initInputLabel();
	void initInputField();
	
};

