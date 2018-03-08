#pragma once
#include "Arme.h"
class AutoShotgun :
	public Arme
{
private:
	int nrAlice;
public:
	AutoShotgun(int Ammo, int Mag, float Damage, int FireRate, int PutereAruncare, int ReloadTime, float precizie, float reculMax, float CooldownRecul, int NrAlice);
	virtual void foc(sf::Vector2f sursa, sf::Vector2f target);
};

