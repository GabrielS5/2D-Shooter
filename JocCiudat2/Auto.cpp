#include "Auto.h"



Auto::Auto(int Ammo, int Mag, float Damage, int FireRate, int PutereAruncare, int ReloadTime, float precizie, float reculMax, float CooldownRecul)
	:Arme(Ammo, Mag,Damage, FireRate, PutereAruncare, ReloadTime, precizie, reculMax, CooldownRecul)
{

}



void Auto::foc(sf::Vector2f sursa, sf::Vector2f target)
{
	if (timer%fireRate == 0  && !reloading)
	{
		timer = 1;
		Arme::foc(sursa, target);
	}
	
}


vector<int> Auto::update(Teren teren, vector<pair<sf::Vector2f, sf::Vector2f>> figuri)
{
	vector<int> damageDat;
	damageDat=Arme::update(teren, figuri);
	return damageDat;

}
