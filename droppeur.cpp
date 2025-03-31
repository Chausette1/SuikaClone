#include "include.h"

droppeur::droppeur() : y(120)
{
	x = 400;
}

void droppeur::updateX()
{
	int MouseX = GetMouseX();
	if (MouseX > 190 && MouseX < 620)
	{
		x = MouseX;
	}
	else if (MouseX <= 190)
	{
		x = 190;
	}
	else if (MouseX >= 620)
	{
		x = 620;
	}
}

void droppeur::draw()
{
	DrawCircle(x, y, 20, RED);
}