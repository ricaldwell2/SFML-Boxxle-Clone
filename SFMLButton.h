#pragma once

#include "SFMLFont.h"
#include "SFMLObject.h"

class SFMLButton : public SFMLObject
{
public:
		SFMLButton(float x, 
				   float y, 
				   const std::string& spriteResource, 
				   void (*callback)(),
				   const std::string& text,
				   sf::Color off_color,
				   sf::Color on_color,
				   const std::string& fontResource = "basic_font");

		virtual ~SFMLButton();

		virtual void Step() override;
		virtual void Draw() override;

protected:
	void (*Callback)(); 

	SFMLFont* Font;
	std::string Text;

	sf::Color OnColor;
	sf::Color OffColor;
};