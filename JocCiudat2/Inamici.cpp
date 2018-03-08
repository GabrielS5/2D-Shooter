#include "Inamici.h"


Inamici::Inamici(float X, float Y, int Hp,sf::Vector2f size,Arme* Arma)
{
	arma = Arma;
	x = X;
	y = Y;
	hp = Hp;
	vitX = vitY = 0;
	inamic = new sf::RectangleShape();
	sf::Texture texture;
	//texture.loadFromFile("Texturi\\crab1jos.png");
	//inamic->setTexture(&texture);
	//inamic->setFillColor(sf::Color::Green);
	inamic->setPosition({ x, y });
	inamic->setSize({ size.x, size.y });
}


int Inamici::update(Teren teren, sf::Vector2f poz , sf::Vector2f size)
{
	
	if (vitY < 9)
		vitY = vitY + Gravitatie;
	if (vitX>1)
		vitX = vitX - Frictiune;
	else
		if (vitX < -1)
			vitX = vitX + Frictiune;
		else
			vitX = 0;
	coliziune(teren);
	x = x + vitX;
	y = y + vitY;
	inamic->setPosition({ x, y });
	vector<pair<sf::Vector2f, sf::Vector2f>> jucator;
	jucator.push_back(pair<sf::Vector2f, sf::Vector2f>(poz, size));
	return arma->update(teren, jucator).size()*arma->getDamage();

}
sf::Vector2f Inamici::getPosition()
{
	return inamic->getPosition();
}
sf::Vector2f Inamici::getSize()
{
	return inamic->getSize();
}

int Inamici::coliziune(Teren teren)
{
	if (teren.coliziuneFigura(x + vitX, y + vitY, getSize().y, getSize().x))
	{
	
		if (teren.coliziuneFigura(x + vitX, y, getSize().y, getSize().x))
		{
			vitX = 0;
		}
		if (teren.coliziuneFigura(x, y + vitY, getSize().y, getSize().x))
		{
			vitY = 0;
		}
	}
	return 1;
}


void Inamici::salt(float val)
{
		vitY = -val;

}

void Inamici::Foc(sf::Vector2f target)
{
		arma->foc({ x, y }, target);
}

void Inamici::draw(sf::RenderWindow *window)
{
	arma->draw(window);
	//window->draw(*inamic);
}

void Inamici::modVitX(float vit)
{
	vitX = vit;
}
void Inamici::modVitY(float vit)
{
	vitY = vit;
}

void Inamici::damageLuat(float Damage)
{
	hp = hp - Damage;
}

float Inamici::getHp()
{
	return hp;
}