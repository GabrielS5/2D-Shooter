#pragma once
#include "Inamici.h"
#include"TextureManagerIsis.h"
class Isis :
	public Inamici
{
public:
	TextureManagerIsis* textura;
	float vitezaX, vitezaY, intervalSalt;
	int interval;
	Isis(float X, float Y, int Hp, sf::Vector2f size, Arme* Arma,float VitezaX,float VitezaY,float IntervalSalt,vector<sf::Texture>* Texturi);
	int update(Teren teren, sf::Vector2f poz, sf::Vector2f size);
	void Comportament(sf::Vector2f poz, sf::Vector2f size);
	void draw(sf::RenderWindow *window);


};

