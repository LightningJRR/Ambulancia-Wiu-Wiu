#pragma once
#include "Ambulancia.h"
#include "PersonaCami.h"
#include "PersonaCorrien.h"
#include <vector>


class Controller {
private:
	Ambulancia* ambu;
	vector<PersonaCami*>pca;
	vector<PersonaCorri*>pco;
	int contP;
public:
	Controller(Bitmap^ am, Bitmap^ pcami, Bitmap^ pcor) {
		ambu = new Ambulancia(am->Width, am->Height/4);
		for (int i = 0;i < 1;i++) {
			agregarPca(pcami);
		}
		for (int i = 0;i < 1;i++) {
			agregarPco(pcor);
		}
		contP = 0;
	}

	Ambulancia* getambu() { return ambu; }
	int getcontP() { return contP; }

	void agregarPca(Bitmap^ pcami) {
		pca.push_back(new PersonaCami(31.98, pcami->Height / 2));
	}

	void agregarPco(Bitmap^ pcor) {
		pco.push_back(new PersonaCorri(30.42, pcor->Height / 2));
	}

	void dibujartodo(Graphics^ g, Bitmap^ am, Bitmap^ pcami, Bitmap^ pcor) {
		ambu->draw(g, am);
		for (int i = 0;i < pca.size();i++) {
			pca.at(i)->draw(g, pcami);
		}
		for (int i = 0;i < pco.size();i++) {
			pco.at(i)->draw(g, pcor);
		}
	}

	void movertodo(Graphics^ g) {
		for (int i = 0;i < pca.size();i++) {
			pca.at(i)->move(g);
		}
		for (int i = 0;i < pco.size();i++) {
			pco.at(i)->move(g);
		}
	}

	void colision() {
		for (int i = 0;i < pca.size();i++) {
			if (ambu->getRectangle().IntersectsWith(pca.at(i)->getRectangle())) {
				pca.at(i)->setVisible(false);
			}
		}
		for (int i = 0;i < pco.size();i++) {
			if (ambu->getRectangle().IntersectsWith(pco.at(i)->getRectangle())) {
				pco.at(i)->setVisible(false);
			}
		}

		for (int i = 0;i < pca.size();i++) {
			if (pca.at(i)->getVisible() == false) {
				pca.erase(pca.begin() + i);
				contP += 50;
			}
		}
		for (int i = 0;i < pco.size();i++) {
			if (pco.at(i)->getVisible() == false) {
				pco.erase(pco.begin() + i);
				contP += 50;
			}
		}
	}

};