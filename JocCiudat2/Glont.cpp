#include "Glont.h"
using namespace std;

Glont::Glont(int X, int Y, float VitX, float VitY, float size)
{
	x = X;
	y = Y;
	vitX = VitX;
	vitY = VitY;
	glont = new sf::CircleShape();
	glont->setFillColor(sf::Color::Yellow);
	glont->setRadius(size);
	glont->setPosition({ x, y });
}
void Glont::update()
{
	x = x + vitX;
	y = y + vitY;
	glont->setPosition({ x, y });

}
sf::Vector2f Glont::getPos()
{
	return { x, y };
}

void Glont::draw(sf::RenderWindow *window)
{
	window->draw(*glont);
}

bool Glont::coliziuneFigura(sf::Vector2f poz, sf::Vector2f size)
{
	
	if (!(x<poz.x || x>poz.x + size.x || y<poz.y || y>poz.y + size.y))
		return 1;
	return 0;

}