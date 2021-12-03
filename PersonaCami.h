#pragma once
#include "Character.h"

class PersonaCami : public Character {
private:
	int type;
public:
	PersonaCami(int width, int height) : Character(width, height) {
		x = rand() % 300 + 1;
		y = rand() % 30 * 10;
		dx = dy = -5;
	}
	~PersonaCami() {}

	void move(Graphics^ g) {
		if (x + dx <0 || x + dx + width * 1.0 > g->VisibleClipBounds.Width) {
			idy = 0;
			dx *= -1; 
		}
		if (y + dy < 0 || y + dy + height * 1.0 > g->VisibleClipBounds.Height) {
			dy *= -1;
		}
		if (dx > 0) {
			idy = 1;
		}
		else {
			idy = 0;
		}

		x += dx;
		y += dy;
		idx++;
		if (idx > 3)idx = 0;
	}
};



