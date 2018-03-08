#pragma once
#include"Biblioteci.h"
class Glont
{
private:
	sf::CircleShape *glont;
	float x, y, vitX, vitY;
public:
	Glont(int X, int Y,float VitX,float VitY,float size);
	void update();
	sf::Vector2f getPos();
	void draw(sf::RenderWindow *window);
	bool coliziuneFigura(sf::Vector2f poz, sf::Vector2f size);
};

