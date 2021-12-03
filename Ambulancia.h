#pragma once
#include "Character.h"

class Ambulancia : public Character {

public:
	Ambulancia(int width, int height) : Character(width, height) {
		x = 100;
		y = 400;
		dx = dy = 15;
	}

	~Ambulancia() {}

	void move(Graphics^ g, char i) {
		switch (i)
		{
		case 'A':
			if (x > 0) {
				x -= dx;
				idy = 1;
				idx = 0;
			}
			break;

		case 'D':
			if (x + width * 1.0 < g->VisibleClipBounds.Width) {
				x += dx;
				idy = 2;
				idx = 0;
			}
			break;

		case 'W':
			if (y > 0) {
				y -= dy;
				idy = 0;
				idx = 0;
			}
			break;

		case 'S':
			if (y + height * 1.0 < g->VisibleClipBounds.Height) {
				y += dy;
				idy = 3;
				idx = 0;
			}
			break;
		}
	}
};
