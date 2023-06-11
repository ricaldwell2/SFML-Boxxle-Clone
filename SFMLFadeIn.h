#pragma once

#include "SFMLObject.h"

class SFMLFadeIn : public SFMLObject
{
public:
	SFMLFadeIn();
	
	virtual void Step() override;
};