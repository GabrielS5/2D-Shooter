#pragma once
#include "Biblioteci.h"
class Teren
{
private:
	sf::RectangleShape *teren[20][20];
	int AuxTeren[20][20];
public:
	Teren(int auxTeren[20][20]);
	void draw(sf::RenderWindow* window);
	void modificaTeren(int auxTeren[20][20]);
	void adaugaTeren(sf::Vector2i pereche);
	bool coliziunePunct(sf::Vector2f punct);
	float coliziuneFigura(int x, int y, int l, int L);
};

