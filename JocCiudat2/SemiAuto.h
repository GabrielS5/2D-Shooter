#pragma once
#include "Arme.h"
class SemiAuto :
	public Arme
{
private:
	int trageri, frame, liber;
	bool semiAuto;
public:
	SemiAuto(int Ammo, int Mag, float Damage, int FireRate, int PutereAruncare, int ReloadTime, float precizie, float reculMax, float CooldownRecul);
	virtual void foc(sf::Vector2f sursa, sf::Vector2f target);
	vector<int> update(Teren teren, vector<pair<sf::Vector2f, sf::Vector2f>> figuri);
};

