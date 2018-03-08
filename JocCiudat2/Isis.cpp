#include "Isis.h"


Isis::Isis(float X, float Y, int Hp, sf::Vector2f size, Arme* Arma, float VitezaX, float VitezaY, float IntervalSalt, vector<sf::Texture>* Texturi) :
Inamici(X,Y,Hp,size,Arma)
{
	textura = new TextureManagerIsis(Texturi);
	vitezaX = VitezaX;
	vitezaY = VitezaY;
	intervalSalt = IntervalSalt;
	interval = 0;
}

void Isis::Comportament(sf::Vector2f poz, sf::Vector2f size)
{
	if (vitY == 0)
	{
		if (x < poz.x)
			vitX = 1;
		else
			vitX = -1;
	}
	
	if (vitX>0)
		vitX =vitX+ Frictiune;
	else
		if (vitX<0)
	vitX =vitX -Frictiune;
	
	interval++;

	if (interval == intervalSalt && vitY<1)
	{
		salt(vitezaY);
		if (x < poz.x)
			vitX = vitezaX;
		else
			vitX = -vitezaX;
		interval = 0;
	}
	//if (y>0 && x>100)
	//arma->foc({ x, y }, poz);
}

int Isis::update(Teren teren, sf::Vector2f poz, sf::Vector2f size)
{
	
	Comportament(poz,size);
	textura->update(x, y, vitX, vitY);
	return Inamici::update(teren,poz,size);
	
}

void Isis::draw(sf::RenderWindow *window)
{
	textura->draw(*window);
	Inamici::draw(window);
}
