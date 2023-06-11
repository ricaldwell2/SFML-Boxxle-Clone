#include <fstream>
#include "MainMenuButton.h"

MainMenuButton::MainMenuButton(float x, float y, const std::string& spriteResource, void (*callback)(), const std::string& text, int levelNumber)
	: SFMLButton(x, y, "main_menu_button", callback, text, sf::Color::Yellow, sf::Color(0, 0, 0)),
	  BestScore(99999)
{
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
		if (level == levelNumber)
		{
			BestScore = score;
			break;
		}
	}
	
	file.close();
}

void MainMenuButton::Draw()
{
	SFMLButton::Draw();

	if (BestScore < 2000)
	{
		sf::Color DrawColor = (ImageIndex() == 0) ? OffColor : OnColor;
		Font->Print(X() + 250, Y() + 128, "BEST SCORE: " + std::to_string(BestScore), DrawColor, 1, 1);
	}
}