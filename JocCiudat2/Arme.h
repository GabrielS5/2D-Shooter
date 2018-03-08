#pragma once
#include"Biblioteci.h"
#include"Glont.h"
#include"Teren.h"
using namespace std;

class Arme
{
public:
	Arme(int Ammo, int Mag,float Damage, int FireRate, int PutereAruncare, int ReloadTime, float Precizie, float ReculMax, float CooldownRecul);
	int reloadTime, ammo, mag, putereAruncare, fireRate, timer, magCapacity, reloading,damage;
	float precizie, reculMax, recul,cooldownRecul;
	vector<Glont*> gloante;
	virtual void reload();
	virtual void foc(sf::Vector2f sursa, sf::Vector2f target);
	 void draw(sf::RenderWindow *window);
	 virtual vector<int> update(Teren teren, vector<pair<sf::Vector2f, sf::Vector2f>> figuri);
	 float getDamage();

};

