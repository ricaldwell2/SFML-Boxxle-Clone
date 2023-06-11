#include "BoxxleGameLevelRoom.h"
#include "MainMenuBackground.h"
#include "MainMenuRoom.h"
#include "MainMenuButton.h"
#include "SFMLFadeIn.h"
#include "SFMLFadeOutAndChangeRoom.h"
#include "SFMLGame.h"

void QuitGame()
{
	SFMLGame::GetInstance()->QuitGame();
}

void PlayLevel001()
{
	SFMLGame::GetInstance()->GetCurrentRoom()
		->InstanceCreate(new SFMLFadeOutAndChangeRoom(new BoxxleGameLevelRoom("Level_001_SFMLPort.txt", 1)));
}

void PlayLevel002()
{
	SFMLGame::GetInstance()->GetCurrentRoom()
		->InstanceCreate(new SFMLFadeOutAndChangeRoom(new BoxxleGameLevelRoom("Level_002_SFMLPort.txt", 2)));
}

void PlayLevel003()
{
	SFMLGame::GetInstance()->GetCurrentRoom()
		->InstanceCreate(new SFMLFadeOutAndChangeRoom(new BoxxleGameLevelRoom("Level_003_SFMLPort.txt", 3)));
}

MainMenuRoom::MainMenuRoom()
	: SFMLRoom()
{
	InstanceCreate(new MainMenuBackground(0, 0));
	
	InstanceCreate(new SFMLButton(720, 510, "main_menu_button", QuitGame, "QUIT GAME", sf::Color::Yellow, sf::Color(0, 0, 0)));	//QUIT GAME
	InstanceCreate(new MainMenuButton(60, 190, "main_menu_button", PlayLevel001, "LEVEL 1", 1));	//LEVEL 1
	InstanceCreate(new MainMenuButton(60, 350, "main_menu_button", PlayLevel002, "LEVEL 2", 2));	//LEVEL 2
	InstanceCreate(new MainMenuButton(60, 510, "main_menu_button", PlayLevel003, "LEVEL 3", 3));	//LEVEL 3

	InstanceCreate(new SFMLFadeIn());
}
