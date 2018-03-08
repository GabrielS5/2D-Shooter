#pragma once
#include"Biblioteci.h"
#include"Teren.h"
#include"Arme.h"
class Inamici
{
public:
	sf::RectangleShape *inamic;
	bool pePodea, langaPerete;
	Arme* arma;
	float vitX, vitY, x, y,hp;
	Inamici(float X, float Y, int Hp, sf::Vector2f size,Arme* Arma);
	virtual int update(Teren teren, sf::Vector2f poz, sf::Vector2f size);
	virtual void draw(sf::RenderWindow *window);
	virtual void modVitX(float vit);
	virtual void modVitY(float vit);
	virtual sf::Vector2f getPosition() ;
	virtual sf::Vector2f getSize();
	virtual int coliziune(Teren teren);
	virtual void salt(float val);
	virtual void Foc(sf::Vector2f target);
	virtual void damageLuat(float Damage);
	virtual float getHp();
};

