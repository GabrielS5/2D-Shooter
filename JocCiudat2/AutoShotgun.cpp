#include "AutoShotgun.h"

using namespace std;

AutoShotgun::AutoShotgun(int Ammo, int Mag, float Damage, int FireRate, int PutereAruncare, int ReloadTime, float precizie, float reculMax, float CooldownRecul, int NrAlice)
	:Arme(Ammo, Mag,Damage, FireRate, PutereAruncare, ReloadTime, precizie, reculMax, CooldownRecul)
{
	nrAlice = NrAlice;
}



void AutoShotgun::foc(sf::Vector2f sursa, sf::Vector2f target)
{
	if (timer%fireRate == 0 && !reloading)
	{

		timer = 1;

		for (int i = 0; i < nrAlice; i++)
		{
			Arme::foc(sursa, { target.x, target.y + i });
		}
		mag = mag + nrAlice - 1;
	}
	cout << mag << "/" << ammo << endl;
}




