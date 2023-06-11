#include "SFMLFadeIn.h"
#include "SFMLGame.h"

SFMLFadeIn::SFMLFadeIn()
	: SFMLObject(0, 0, "_1x1_black")
{
	GetSprite()->setScale(SFMLGame::GetInstance()->GetWindowResolution().x,
						  SFMLGame::GetInstance()->GetWindowResolution().y);

	SetDepth(100);
}

void SFMLFadeIn::Step()
{
	sf::Color color = GetSprite()->getColor();
	if (color.a >= 10)
	{
		color.a -= 10;
	}
	else
	{
		color.a = 0;
	}
	GetSprite()->setColor(color);
}