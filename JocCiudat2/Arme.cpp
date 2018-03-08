#include "Arme.h"
using namespace std;

Arme::Arme(int Ammo, int Mag, float Damage, int FireRate, int PutereAruncare, int ReloadTime, float Precizie, float ReculMax, float CooldownRecul)
{
	damage = Damage;
	reloadTime = ReloadTime;
	ammo = Ammo;
	mag =magCapacity= Mag;
	putereAruncare = PutereAruncare;
	fireRate = FireRate;
	timer = 0;
	reloading = 0;
	precizie = Precizie;
	reculMax = ReculMax;
	cooldownRecul=CooldownRecul;

}

float Distanta(float x, float y, float X, float Y)
{
	return sqrt((x - X)*(x - X) + (y - Y)*(y - Y));
}

void Arme::foc(sf::Vector2f sursa, sf::Vector2f target)
{
	float inprecizieX,inprecizieY;
	if (rand() % 2 == 0)
		inprecizieX = ((float)rand() / (float)RAND_MAX) * (precizie + recul / 5);
	else
		inprecizieX = -((float)rand() / (float)RAND_MAX) * (precizie + recul / 5);
	if (rand() % 2 == 0)
		inprecizieY = ((float)rand() / (float)RAND_MAX) * (precizie / 2 + recul / 5);
	else

		inprecizieY = -((float)rand() / (float)RAND_MAX) * (precizie/2+recul/5);



		float adaugareX = (sursa.x - target.x) / 40, adaugareY = (sursa.y - target.y) / 40;

		while (Distanta(sursa.x, sursa.y, target.x, target.y) < putereAruncare - 10 || Distanta(sursa.x, sursa.y, target.x, target.y) > putereAruncare + 10)
		{
			if (Distanta(sursa.x, sursa.y, target.x, target.y) > putereAruncare + 10)
			{
				target.x = target.x + adaugareX;
				target.y = target.y + adaugareY;
			}
			else
			{
				target.x = target.x - adaugareX;
				target.y = target.y - adaugareY;
			}

		}
		target.x = target.x + inprecizieX;
		target.y = target.y + inprecizieY-recul;
		float vitX = -(sursa.x - target.x) / (10);
		float vitY = -(sursa.y - target.y) / (10);


		gloante.push_back(new Glont(sursa.x, sursa.y, vitX, vitY, 1));
		mag--;
		recul = recul + reculMax / 10;
}

void Arme::draw(sf::RenderWindow *window)
{
	for (int i = 0; i < gloante.size(); i++)
	{
		gloante[i]->draw(window);
	}
}

vector<int> Arme::update(Teren teren, vector<pair<sf::Vector2f, sf::Vector2f>> figuri)
{
	vector<int> damageDat;
	if (timer != 0)
	{
		timer = (timer + 1) % fireRate;
	}
	for (int i = gloante.size()-1; i >=0; i--)
	{

		gloante[i]->update();
		sf::Vector2f pozitie = gloante[i]->getPos();
		if (pozitie.x<0 || pozitie.x>Latime || pozitie.y>Inaltime || pozitie.y <0 || teren.coliziunePunct(pozitie))
			gloante.erase(gloante.begin() + i);
		else
		{
			for (int j = 0; j < figuri.size();j++)
			{
				if (gloante[i]->coliziuneFigura(figuri[j].first, figuri[j].second))
				{
					damageDat.push_back(j);
					gloante.erase(gloante.begin() + i);
					break;
				}
			}
		}
	}

	if (recul > 0)
		recul = recul - cooldownRecul;

	if (mag == 0)
		reload();
	if (reloading>0)
	reloading--;
	return damageDat;
}

void Arme::reload()
{
	if (!reloading)
	{
		reloading = reloadTime;
		ammo = ammo + mag;
		if (magCapacity > ammo)
		{
			mag = ammo;
			ammo = 0;
		}
		else
		{
			mag = magCapacity;
			ammo = ammo - magCapacity;
		}

	}
}

float Arme::getDamage()
{
	return damage;
}