#pragma once
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;

class Character {
protected:
	int x;
	int y;
	int dx;
	int dy;
	int width;
	int height;
	int idx; // color a cambiar o tipo o equipo
	int idy;
	bool  visible;

	int ranking;
	float anchoWZoom;
	float altoWZoom;
public:
	Character(int width, int height) {
		this->width = width;
		this->height = height;
		idx = idy = 0;
		visible = true;
	}
	~Character() {

	}

	void draw(Graphics^ g, Bitmap^ bmp) {
		//Pen^ p = gcnew Pen(Color::Red, 3);
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
		//g->DrawRectangle(p, x, y, width, height);
	}

	virtual void move() {}

	Rectangle getRectangle() {
		return Rectangle(x, y, width * 1.0, height * 1.0);
	}

	Rectangle getRectangleChoque(int x, int y) {
		return Rectangle(x, y, width * 1.0, height * 1.0);
	}

	int getX() { return this->x; }
	int getY() { return this->y; }
	int getDx() { return this->dx; }
	int getDy() { return this->dy; }
	int getAncho() { return this->width; }
	int getAlto() { return this->height; }
	int getIndiceX() { return this->idx; }
	int getIndiceY() { return this->idy; }
	int getRanking() { return this->ranking; }
	bool getVisible() { return visible; }

	void setVisible(bool visible) { this->visible = visible; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setDx(int dx) { this->dx = dx; }
	void setAncho(int ancho) { this->width = ancho; }
	void setAlto(int alto) { this->height = alto; }
	void setIndiceX(int indiceX) { this->idx = indiceX; }
	void setIndiceY(int indiceY) { this->idy = indiceY; }
	void setRanking(int ranking) { this->ranking = ranking; }

};
