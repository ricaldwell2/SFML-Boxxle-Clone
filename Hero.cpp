#include <fstream>
#include "Box.h"
#include "Hero.h"
#include "Goal.h"
#include "MainMenuRoom.h"
#include "SFMLFadeOutAndChangeRoom.h"
#include "SFMLGame.h"
#include "SFMLKeyboard.h"
#include "SFMLTextureManager.h"
#include "SolidObject.h"


Hero::Hero(float x, float y, int levelNumber)
	: SFMLObject(x, y, "hero_down", 4, 1), //last 2 nums...4 frames horizontally 1 vertically
	  Steps(0),
	  Font(new SFMLFont()),
	  LevelNumber(levelNumber),
	  BestScore(GetBestScoreForLevelFromFile()),
	  WonGame(false)
{
	//What should the character do when you start the level?
	SetDepth(3);	
}

Hero::~Hero()
{
	delete Font;
}

void Hero::Step()
{
	SFMLObject::Step();		//Calling parent function plus the override stuff for the hero sprite

	if (WonGame == true)
	{
		return;
	}
	
	if (SFMLKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Escape))//TODO: Get rid of this later???
	{
		SFMLGame::GetInstance()->GetCurrentRoom()->ChangeRoom(new MainMenuRoom()); //use this principle to reset main menu room
	}
	
	if (SFMLKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Right) && (Alarm(0) < 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X() + SpriteWidth(), Y());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.9f);
			SetSpeed(15);
			SetDirection(0);
			SetAlarm(0, 4);
			GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("hero_right"));
		}
		else
		{
			std::vector<Box*> boxes = GetAllGameObjectsAtPosition<Box*>(X() + SpriteWidth(), Y());
			if (boxes.size() == 1)
			{
				std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X() + (SpriteWidth() << 1), Y());
				if (solids.size() == 0)
				{
					SetImageSpeed(0.9f);
					SetSpeed(5);
					SetDirection(0);
					SetAlarm(0, 12);		//have to lower alarm and the SetSpeed() function to lessen the speed
					GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("hero_right"));
					boxes[0]->SetImageSpeed(0.9f);
					boxes[0]->SetSpeed(5);
					boxes[0]->SetDirection(0);
					boxes[0]->SetAlarm(0, 12);
				}
			}
		}
	}

	if (SFMLKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Left) && (Alarm(0) < 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X() - SpriteWidth(), Y());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.9f);
			SetSpeed(15);
			SetDirection(180);
			SetAlarm(0, 4);
			GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("hero_left"));
		}
		else
		{
			std::vector<Box*> boxes = GetAllGameObjectsAtPosition<Box*>(X() - SpriteWidth(), Y());
			if (boxes.size() == 1)
			{
				std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X() - (SpriteWidth() << 1), Y());
				if (solids.size() == 0)
				{
					SetImageSpeed(0.9f);
					SetSpeed(5);
					SetDirection(180);
		 			SetAlarm(0, 12);		//have to lower alarm and the SetSpeed() function to lessen the speed
					GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("hero_left"));
					boxes[0]->SetImageSpeed(0.9f);
					boxes[0]->SetSpeed(5);
					boxes[0]->SetDirection(180);
					boxes[0]->SetAlarm(0, 12);
				}
			}
		}
	}

	if (SFMLKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Up) && (Alarm(0) < 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X(), Y() - SpriteHeight());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.9f);
			SetSpeed(15);
			SetDirection(90);
			SetAlarm(0, 4);
			GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("hero_up"));
		}
		else
		{
			std::vector<Box*> boxes = GetAllGameObjectsAtPosition<Box*>(X(), Y() - SpriteHeight());
			if (boxes.size() == 1)
			{
				std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X(), Y() - (SpriteHeight() << 1));
				if (solids.size() == 0)
				{
					SetImageSpeed(0.9f);
					SetSpeed(5);
					SetDirection(90);
					SetAlarm(0, 12);		//have to lower alarm and the SetSpeed() function to lessen the speed
					GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("hero_up"));
					boxes[0]->SetImageSpeed(0.9f);
					boxes[0]->SetSpeed(5);
					boxes[0]->SetDirection(90);
					boxes[0]->SetAlarm(0, 12);
				}
			}
		}
	}

	if (SFMLKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Down) && (Alarm(0) < 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X(), Y() + SpriteHeight());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.9f);
			SetSpeed(15);
			SetDirection(270);
			SetAlarm(0, 4);
			GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("hero_down"));
		}
		else
		{
			std::vector<Box*> boxes = GetAllGameObjectsAtPosition<Box*>(X(), Y() + SpriteHeight());
			if (boxes.size() == 1)
			{
				std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X(), Y() + (SpriteHeight() << 1));
				if (solids.size() == 0)
				{
					SetImageSpeed(0.9f);
					SetSpeed(5);
					SetDirection(270);
					SetAlarm(0, 12);		//have to lower alarm and the SetSpeed() function to lessen the speed
					GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("hero_down"));
					boxes[0]->SetImageSpeed(0.9f);
					boxes[0]->SetSpeed(5);
					boxes[0]->SetDirection(270);
					boxes[0]->SetAlarm(0, 12);
				}
			}
		}
	}
}

void Hero::OnAlarm(int alarm)
{
	if (alarm == 0)
	{
		++Steps;
		SetImageSpeed(0);
		SetSpeed(0);

		bool won = true;
		std::vector<Goal*> goals = GetAllGameObjectsOfType<Goal*>();
		for (Goal* g : goals)
		{
			std::vector<Box*> boxes = GetAllGameObjectsAtPosition<Box*>(g->X(), g->Y());
			if (boxes.size() != 1)
			{
				won = false;
				break;
			}
		}

		WonGame |= won;
		if (WonGame && Alarm(1) < 0)
		{
			SetAlarm(1, 120);
		}
	}
	
	if (alarm == 1)
	{
		SFMLGame::GetInstance()->GetCurrentRoom()
			->InstanceCreate(new SFMLFadeOutAndChangeRoom(new MainMenuRoom()));
	}
}


void Hero::Draw()
{
	SFMLObject::Draw();
	Font->Print(5, 5, "CURRENT STEPS TAKEN: " + std::to_string(Steps));
	if (BestScore < 2000)
	{
		Font->Print(5, 35, "BEST STEPS TAKEN:    " + std::to_string(BestScore));
	}

	if (WonGame == true)
	{
		Font->Print(360, 312, "LEVEL COMPLETE!", sf::Color::Yellow, 2.0f, 2.0f);
		if (Steps < BestScore)
		{
			Font->Print(430, 357, "NEW RECORD!", sf::Color::Yellow, 2.0f, 2.0f);
			SetNewBestScoreForLevelInFile();
		}
	}
}

int Hero::GetBestScoreForLevelFromFile()
{
	std::ifstream file("data.txt");
	if (file.fail() == true)
	{
		return 999999;
	}

	while (file.eof() == false)
	{
		int level;
		int score;
		file >> level >> score;
		if (level == LevelNumber)
		{
			file.close();
			return score;
		}
	}
	
	file.close();
	return 999999;
}

void Hero::SetNewBestScoreForLevelInFile()
{
	std::vector<int> scores;

	std::ifstream file("data.txt");
	if (file.fail() == true)
	{
		return;
	}

	while (file.eof() == false)
	{
		int level;
		int score;
		file >> level >> score;

		if (level == LevelNumber)
		{
			if (Steps < BestScore)
			{
				scores.push_back(Steps);
			}
			else
			{
				scores.push_back(score);
			}
		}
		else
		{
			scores.push_back(score);
		}
	}

	file.close();

	std::ofstream out("data.txt");

	for (int i = 0; i < scores.size(); ++i)
	{
		out << " " << (i + 1) << " " << scores[i];
	}

	file.close();
}