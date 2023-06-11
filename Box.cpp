#include "Box.h"
#include "SFMLGame.h"

Box::Box(float x, float y)
	: SolidObject(x, y, "box")
{
	SetDepth(2);
}

void Box::OnAlarm(int alarm)
{
	SetSpeed(0);
}