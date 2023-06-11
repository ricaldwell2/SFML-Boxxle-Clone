#include "SFMLFadeOutAndChangeRoom.h"
#include "SFMLGame.h"

SFMLFadeOutAndChangeRoom::SFMLFadeOutAndChangeRoom(SFMLRoom* room)
	: SFMLObject(0, 0, "_1x1_black", 1, 1),
	  NextRoom(room)
{
	GetSprite()->setScale(SFMLGame::GetInstance()->GetWindowResolution().x,
		                  SFMLGame::GetInstance()->GetWindowResolution().y);

	SetDepth(100);
	sf::Color color = GetSprite()->getColor();
	color.a = 0;
	GetSprite()->setColor(color);
}

void SFMLFadeOutAndChangeRoom::Step()
{
	sf::Color color = GetSprite()->getColor();
	color.a += 5;	// Fade out is still a bit slow but the current room was reloading for some reason?
	if (color.a >= 253)
	{
		SFMLGame::GetInstance()->ChangeRoom(NextRoom);
	}
	GetSprite()->setColor(color);
}