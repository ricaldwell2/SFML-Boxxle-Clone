#pragma once

#include "SFMLButton.h"

class MainMenuButton : public SFMLButton
{
public:
	MainMenuButton(float x,
		float y,
		const std::string& spriteResource,
		void (*callback)(),
		const std::string& text,
		int levelNumber);

	virtual void Draw() override;

private:
	int BestScore;
};