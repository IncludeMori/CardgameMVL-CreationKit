#include "FileList.hpp"
#include "eCardData.hpp"

extern SDL_Renderer *gRenderer;

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

using std::unique_ptr;

#include "gMouse.hpp"
#include "ValidEntry.hpp"
#include <iostream>

#define CURRENT_MENU_INT static_cast<int>(mCurrentMenu)

FileList::FileList(const std::string &path, std::vector<std::string> &list)
{
	//how to use-info
	Dev_Comment[0].loadFromRenderedText(16,"ESC - RESET CURRENT FIELD || CANCEL");
	Dev_Comment[1].loadFromRenderedText(16,"ENTER - SAVE CURRENT FIELD");

	Dev_Comment[0].setPos(320, 0);
	Dev_Comment[1].setPos(320, 20);

	//
	FileArrow.loadFromFile("Data/List/file_arrow.png");

	mImagePath = "C:/Users/MoritzV/Desktop/Card_Game/CardGame_Walnut/Data/";

	int x = 20;
	int y = 165;

	mFilePath = path;
	std::cout << "Path:" << path << std::endl;

	mFileName = list;
	activeFile = -1;
	activeField = -1;

	mSaveBtn.loadFromFile("Data/Static/SaveBtn.png");
	mSaveBtn.setPos(SCREEN_WIDTH/2-mSaveBtn.getWidth()/2-75,SCREEN_HEIGHT-mSaveBtn.getHeight()-30);

	initInputLabel();

	initUserInput();

	initDropDownMenu();

	initInputField();

	//Load & Init Files
	for (int i = 0; i < mFileName.size(); i++)
	{
		CardData.push_back(std::unique_ptr<CardInfo>(new CardInfo(path, mFileName[i])));
		CardData[i]->setPos(x, y + i * 50);
	}
}


FileList::~FileList()
{
}

void FileList::update(SDL_Event &e)
{
	gMouse.update();

	if (mCurrentMenu != Menu_Index::ERROR)
	{
		if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		{
			reset();
			mCurrentMenu = Menu_Index::ERROR;
		}
		//if (EventH.isMouseEvent(e))
		//	mCurrentMenu = Menu_Index::ERROR;

		DropMenu.update(e);
		if (DropMenu.getChoice() != -1)
		{
			if (e.type == SDL_MOUSEBUTTONUP)
			{
				std::cout << "UPPPPPPPPP!";
				//mDropOtions[CURRENT_MENU_INT]->free();
				Drop_InputField[CURRENT_MENU_INT]->free();
				std::cout << CURRENT_MENU_INT << "---" << std::endl;
				//mDropOtions[CURRENT_MENU_INT]->loadFromRenderedText(DropMenu.getAsString());
				//mDropOtions[CURRENT_MENU_INT]->setPos(500+5, 310-5);
				Drop_InputField[CURRENT_MENU_INT]->loadFromRenderedText(DropMenu.getAsString());
				Drop_InputField[CURRENT_MENU_INT]->setPos(505, 305);
				if (CURRENT_MENU_INT + 5 == EFFECT_TYPE)
					Drop_InputField[CURRENT_MENU_INT]->setPos(500+5, 360 - 5);

				Drop_InputField[CURRENT_MENU_INT]->setPos(User_InputField[CURRENT_MENU_INT + 5].x, User_InputField[CURRENT_MENU_INT + 5].y);
					//mDropOtions[CURRENT_MENU_INT]->setPos(500 + 5, 360 - 5);
		

				Drop_InputField[CURRENT_MENU_INT]->setRect(User_InputField[CURRENT_MENU_INT + 5]);

				ValidEntry test;

				test.Validate(Drop_InputField,DropMenu);
				reset();
				
				DropMenu.setActive(Menu_Index::ERROR);
				std::cout << "reset" << std::endl;
				SDL_FlushEvent(SDL_MOUSEBUTTONUP);
				SDL_FlushEvent(SDL_MOUSEBUTTONDOWN);
			}
		}
	}
	else
	{
		if (gMouse.getX() < 300)
		{
			if (EventH.isMouseEvent(e))
			{
				for (int i = 0; i < CardData.size(); i++)
				{
					if (gMouse.isAbove(CardData[i]->getData()))
					{
						reset();
						CardData[i]->setActive();

						if (activeFile != i)
						{
							if (activeFile != -1)
								CardData[activeFile]->setInactive();

							std::string path = CardData[i]->getPath();
							std::cout << "Path=" << path;

							CurrentData[FILENAME].initText(path.substr(path.find_last_of("/") + 1, path.find_last_of(".")));
							CurrentData[NAME].initText(CardData[i]->getName());
							CurrentData[HEALTH].initText(CardData[i]->getHealth());
							CurrentData[ATTACK].initText(CardData[i]->getAttack());
							CurrentData[COST].initText(CardData[i]->getCost());

							Drop_InputField[0]->loadFromRenderedText(CardData[i]->get(EFFECT));
							Drop_InputField[1]->loadFromRenderedText(CardData[i]->get(EFFECT_TYPE));
							Drop_InputField[2]->loadFromRenderedText(CardData[i]->get(TARGET));
							Drop_InputField[3]->loadFromRenderedText(CardData[i]->get(TARGET_SPEC));
							Drop_InputField[4]->loadFromRenderedText(CardData[i]->get(STAT));

							Drop_InputField[0]->setRect(User_InputField[5]);
							Drop_InputField[1]->setRect(User_InputField[6]);
							Drop_InputField[2]->setRect(User_InputField[7]);
							Drop_InputField[3]->setRect(User_InputField[8]);
							Drop_InputField[4]->setRect(User_InputField[9]);

							//mDropOtions[EFFECT-5]->loadFromRenderedText(CardData[i]->get(EFFECT));
							//mDropOtions[EFFECT_TYPE-5]->loadFromRenderedText(CardData[i]->get(EFFECT_TYPE));

				
							//mDropOtions[EFFECT-5]->setPos(500, 310);
							//mDropOtions[EFFECT_TYPE-5]->setPos(500, 360);
							Drop_InputField[0]->setPos(500, 300);
							Drop_InputField[1]->setPos(500, 350);
							Drop_InputField[2]->setPos(500, 400);
							Drop_InputField[3]->setPos(500, 450);
							Drop_InputField[4]->setPos(880, 400);

							//set fields inactive/active
							ValidEntry test;

							test.Validate(Drop_InputField,DropMenu);

						}
						activeFile = i;
					}
				}
			}
		}
		else
		{
			if (activeFile != -1)
				CardData[activeFile]->update(e);

			//if (activeField == -1)
			//{
			if (EventH.isMouseEvent(e))
			{
				for (int i = 0; i < 11; i++)
					if (gMouse.isAbove(User_InputField[i]))
					{
						reset();
						if (i < 5)
							Keyboard_Input = true;
						else
							Keyboard_Input = false;

						activeField = i;
						FileArrow.setPos(mInputLabel[activeField]->getX() - 50, mInputLabel[activeField]->getY());
						oldData = CardData[activeFile]->get(i); //use enum to get specific data
						oldData = oldData.substr(oldData.find_last_of("/") + 1, oldData.find_last_of("."));

						if (activeField > 4 && !Keyboard_Input)
						{
							if (Drop_InputField[i - 5]->isActive())
							{
								mCurrentMenu = static_cast<Menu_Index>(activeField - 5);
								DropMenu.setPos(mCurrentMenu, (User_InputField[activeField].x) + 80, User_InputField[activeField].y);
								DropMenu.setActive(mCurrentMenu);
								std::cout << "set Active:" << activeField - 5 << std::endl;
						
							}
							else
								activeField = -1;
							
						}

					}
			}
			//}
		}


		if (activeField != -1 && Keyboard_Input)
		{
			//DropMenu.setPos(activeField,CardData[activeFile]->get)


			int Scancode = e.key.keysym.scancode;
			if (Scancode == 40) //enter,save
			{
				modFileData = IHandler.getMod();

				//necessary to reload texture?
				if (activeField == FILENAME)
				{
					if (!CardData[activeFile]->reloadImg(mImagePath + modFileData)) //reload new image
					{
						std::cout << "ERROR, Image could not be loaded" << std::endl;
						//Reset
						CurrentData[activeField].initText(oldData);
					}
					else
						CardData.at(activeFile)->set(FILENAME, modFileData);
				}
				else
				{

				}

				activeField = -1;
				IHandler.reset();
			}
			else if (Scancode == SDL_SCANCODE_ESCAPE)
			{
				CurrentData[activeField].initText(oldData); //reset text
				activeField = -1;
				IHandler.reset();
			}
			else
			{
				if (IHandler.update(e)) //if true, update rendered text
				{
					modFileData = IHandler.getMod();
					CurrentData[activeField].initText(modFileData);
				}//todo


			}
		}


	}




}
void FileList::render()
{
	Dev_Comment[0].render();
	Dev_Comment[1].render();

	if (activeFile != -1)
	{
		//mDropOtions[EFFECT-5]->render();
		//mDropOtions[EFFECT_TYPE-5]->render();
		Drop_InputField[0]->render();
		Drop_InputField[1]->render();
		Drop_InputField[2]->render();
		Drop_InputField[3]->render();
		Drop_InputField[4]->render();

		for (int i = 0; i < 5; i++)
			CurrentData[i].renderText();
		mSaveBtn.render();
	}


	for (int i = 0; i < mInputLabel.size(); i++)
		mInputLabel[i]->render();

	
	if (activeField != -1)
		FileArrow.render();

	for (int i = 0; i < CardData.size(); i++)
		CardData[i]->render();


	

	if (activeField > 4)
	{
		//if (mCurrentMenu != Menu_Index::ERROR)
		if (Drop_InputField[activeField-5]->isActive())
		     DropMenu.render();
	}
	
	


	SDL_SetRenderDrawColor(gRenderer, 100, 100, 100, 100);


	for (int i = 0; i<11; i++)
		SDL_RenderDrawRect(gRenderer, &User_InputField[i]);

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

void FileList::reset()
{
	if (activeField != -1 && activeField < 5)
		CurrentData[activeField].initText(oldData);
	modFileData = "";
	activeField = -1;
	oldData = "";
	mCurrentMenu = Menu_Index::ERROR;

}




void FileList::initUserInput()
{
	CurrentData[FILENAME].setPos(500, 110);
	CurrentData[NAME].setPos(500, 160);
	CurrentData[HEALTH].setPos(500, 210);
	CurrentData[ATTACK].setPos(500, 260);
	CurrentData[COST].setPos(880, 210);

	//CurrentData[AMOUNT].setPos(880, 360);
}

void FileList::initDropDownMenu()
{
	Drop_InputField.push_back(std::unique_ptr<InputField>(new InputField(User_InputField[EFFECT])));
	Drop_InputField.push_back(std::unique_ptr<InputField>(new InputField(User_InputField[EFFECT_TYPE])));
	Drop_InputField.push_back(std::unique_ptr<InputField>(new InputField(User_InputField[TARGET])));
	Drop_InputField.push_back(std::unique_ptr<InputField>(new InputField(User_InputField[TARGET_SPEC])));
	Drop_InputField.push_back(std::unique_ptr<InputField>(new InputField(User_InputField[STAT])));
}

void FileList::initInputLabel()
{
	mInputLabel.push_back(unique_ptr<TTF_Text>(new TTF_Text("Filename:")));
	mInputLabel.push_back(unique_ptr<TTF_Text>(new TTF_Text("Name:")));
	mInputLabel.push_back(unique_ptr<TTF_Text>(new TTF_Text("Health:")));
	mInputLabel.push_back(unique_ptr<TTF_Text>(new TTF_Text("Attack:")));
	mInputLabel.push_back(unique_ptr<TTF_Text>(new TTF_Text("Cost:")));
	mInputLabel.push_back(unique_ptr<TTF_Text>(new TTF_Text("Effect:")));;
	mInputLabel.push_back(unique_ptr<TTF_Text>(new TTF_Text("Effect Type:")));

	mInputLabel.push_back(unique_ptr<TTF_Text>(new TTF_Text("Target:")));
	mInputLabel.push_back(unique_ptr<TTF_Text>(new TTF_Text("Target Spec:")));
	mInputLabel.push_back(unique_ptr<TTF_Text>(new TTF_Text("Stat:")));
	mInputLabel.push_back(unique_ptr<TTF_Text>(new TTF_Text("Amount:")));

	mInputLabel[FILENAME]->setPos(350, 100);
	mInputLabel[NAME]->setPos(350, 150);
	mInputLabel[HEALTH]->setPos(350, 200);
	mInputLabel[ATTACK]->setPos(350, 250);
	mInputLabel[COST]->setPos(780, 200);
	mInputLabel[EFFECT]->setPos(350, 300);
	mInputLabel[EFFECT_TYPE]->setPos(350, 350);

	mInputLabel[TARGET]->setPos(350, 400);
	mInputLabel[TARGET_SPEC]->setPos(350, 450);
	mInputLabel[STAT]->setPos(780, 400);
	mInputLabel[AMOUNT]->setPos(770, 450);
}

void FileList::initInputField()
{
	User_InputField[FILENAME] = { 500,100,650,50 };
	User_InputField[NAME] = { 500,150,650,50 };
	User_InputField[HEALTH] = { 500,200,650 / 3,50 };
	User_InputField[ATTACK] = { 500,250,650 / 3,50 };
	User_InputField[COST] = { 880,200,650 / 3,50 };
	User_InputField[EFFECT] = { 500,300,650 / 3,50 };
	User_InputField[EFFECT_TYPE] = { 500,350,650 / 3,50 };

	User_InputField[TARGET] = { 500,400,650 / 3,50 };
	User_InputField[TARGET_SPEC] = { 500,450,650 / 3,50 };
	User_InputField[STAT] = { 880,400,650 / 3,50 };
	User_InputField[AMOUNT] = { 880,450,650 / 3,50 };
}