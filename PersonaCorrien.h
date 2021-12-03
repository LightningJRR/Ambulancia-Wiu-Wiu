#pragma once
#include "Character.h"

class PersonaCorri : public Character {
private:
	int type;
public:
	PersonaCorri(int width, int height) : Character(width, height) {
		x = rand() % 300 + 1;
		y = rand() % 30 * 10;
		dx = dy = 15;
	}
	~PersonaCorri() {}

	void move(Graphics^ g) {
		if (x + dx <0 || x + dx + width * 1.0 > g->VisibleClipBounds.Width) {
			idy = 1;
			dx *= -1;
		}
		if (y + dy < 0 || y + dy + height * 1.0 > g->VisibleClipBounds.Height) {
			dy *= -1;
		}
		x += dx;
		y += dy;
		if (dx > 0) {
			idy = 0;
		}
		else {
			idy = 1;
		}
		idx++;
		if (idx > 6)idx = 0;
	}
};




