#pragma once

#include "SFMLObject.h"
#include "SFMLRoom.h"

class SFMLFadeOutAndChangeRoom : public SFMLObject
{
public:
	SFMLFadeOutAndChangeRoom(SFMLRoom* room);

	// NO DESTRUCTOR NEEDED!

	virtual void Step() override;

private:
	SFMLRoom* NextRoom;
};