#include "Shotgun.h"

using namespace std;

Shotgun::Shotgun(int Ammo, int Mag, float Damage, int FireRate, int PutereAruncare, int ReloadTime, float precizie, float reculMax, float CooldownRecul, int NrAlice)
	:Arme(Ammo, Mag, Damage, FireRate, PutereAruncare, ReloadTime, precizie, reculMax, CooldownRecul)
{
	nrAlice = NrAlice;
	semiAuto = true;
	trageri = frame = 0;
	liber = 1;
}



void Shotgun::foc(sf::Vector2f sursa, sf::Vector2f target)
{
	trageri = (trageri + 1) % 100;
	if (timer%fireRate == 0 && liber && !reloading)
	{
		
		liber = 0;
		timer = 1;
		
		for (int i = 0; i < nrAlice; i++)
		{
			Arme::foc(sursa, { target.x, target.y + i });
		}
		mag = mag + nrAlice - 1;
	}
	cout << mag << "/" << ammo << endl;
}


vector<int> Shotgun::update(Teren teren, vector<pair<sf::Vector2f, sf::Vector2f>> figuri)
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



