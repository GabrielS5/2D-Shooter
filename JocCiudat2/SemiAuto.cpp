#include "SemiAuto.h"


SemiAuto::SemiAuto(int Ammo, int Mag, float Damage, int FireRate, int PutereAruncare, int ReloadTime, float precizie, float reculMax, float CooldownRecul)
	:Arme(Ammo, Mag,Damage, FireRate, PutereAruncare, ReloadTime, precizie, reculMax, CooldownRecul)
{

	semiAuto = true;
	trageri = frame = 0;
	liber = 1;
}



void SemiAuto::foc(sf::Vector2f sursa, sf::Vector2f target)
{
	trageri = (trageri + 1) % 100;
	if (timer%fireRate == 0 && liber && !reloading)
	{
		liber = 0;
		timer = 1;
		Arme::foc(sursa, target);
	}
	cout << mag << "/" << ammo << endl;
}


vector<int> SemiAuto::update(Teren teren, vector<pair<sf::Vector2f, sf::Vector2f>> figuri)
{
	vector<int> damageDat;
	frame = (frame + 1) % 100;
	if (frame != trageri)
	{
		liber = 1;
		frame = trageri = 0;
	}
	damageDat=Arme::update(teren,figuri);
	return damageDat;

}
