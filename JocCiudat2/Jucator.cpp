#include "Jucator.h"

using namespace std;

Jucator::Jucator(vector<sf::Texture> *texturi)
{
	textura =new TextureManagerPlayer( texturi);
	interzis = 0;
	contact = 0;
	pePodea = 0;
	langaPerete = 0;
	x = Latime / 2;
	y = 0;
	vitX = vitY = 0;
	corp = new sf::RectangleShape();
	corp->setFillColor(sf::Color::Blue);
	corp->setPosition({ x, y });
	corp->setSize({ 40, 70 });

	crouch = 0;

	arme[1] = new SemiAuto(36, 12,1,12, 120, 70,3,10,0.3);
	arme[2] = new Auto(10000, 1000,201, 1, 150, 120,20,0,0.4);
	arme[3] = new Shotgun(35, 7,100, 50, 120, 120,20,2,1,12);
	arme[4] = new AutoShotgun(35, 7,1, 15, 120, 120, 10, 2, 1, 7);
	schimbaArma(1);

}
void Jucator::update(Teren teren,vector<Inamici*> inamici,int cX)
{
	if (cooldownSchimbare > 0)
		cooldownSchimbare--;
	vector<pair<sf::Vector2f, sf::Vector2f>> figuri;
	
	for (int i = 0; i < inamici.size(); i++)
	{
		if (coliziuneInamic(inamici[i]))
		{

		}
		figuri.push_back(pair<sf::Vector2f,sf::Vector2f>(inamici[i]->getPosition(), inamici[i]->getSize()));
	}
	
	
	for (int i = 1; i <= nrArme; i++)
	{
		vector<int> damageDat;
		damageDat=arme[i]->update(teren, figuri);
		for (int j = 0; j < damageDat.size(); j++)
		{
			inamici[damageDat[j]]->damageLuat(arme[i]->getDamage());
		}
	}
	if (vitY < 9)
		vitY = vitY + Gravitatie;
	if (vitX>1)
		vitX = vitX - Frictiune;
	else
		if (vitX < -1)
			vitX = vitX + Frictiune;
		else
			vitX = 0;
	coliziune(teren);
	x = x + vitX;
	y = y + vitY;
	
	contact--;
	interzisC--;
	if (interzisC == 0)
		interzis = -1;

	corp->setPosition({ x, y });
	textura->update(x, y, vitX, vitY, crouch, cX, 100);

}

bool Jucator::coliziuneInamic(Inamici* inamic)
{
	if (!(inamic->getPosition().y>y + getSize().y) && !(inamic->getPosition().y + inamic->getSize().y<y))
		if (!(inamic->getPosition().x>x + getSize().x) && !(inamic->getPosition().x + inamic->getSize().x<x))
		{
			return 1;
		}
	return 0;
}

void Jucator::draw(sf::RenderWindow *window)
{
	for (int i = 1; i <= nrArme;i++)
	arme[i]->draw(window);
	textura->draw(*window);
	//window->draw(*corp);
}

void Jucator::modVitX(float vit)
{
	if (!crouch)
		vitX = vit;
	else
		vitX = vit / 3;
}
void Jucator::modVitY(float vit)
{
	vitY = vit;
}


sf::Vector2f Jucator::getPosition()
{
	return corp->getPosition();
}
sf::Vector2f Jucator::getSize()
{
	return corp->getSize();
}

int Jucator::coliziune(Teren teren)
{
	float coeficient;
	if (coeficient=teren.coliziuneFigura(x+vitX, y+vitY, getSize().y, getSize().x))
	{
		coeficient++;
		if (teren.coliziuneFigura(x+vitX, y, getSize().y, getSize().x))
		{
			if (coeficient != interzis)
			{
				contact = 10;
				interzisC = 100;
				interzis = coeficient;
			}
			vitX = 0;
		}
		if (teren.coliziuneFigura(x, y+vitY, getSize().y, getSize().x))
		{
			if (coeficient != interzis)
			{
				contact = 10;
				interzisC = 100;
				interzis = coeficient;
			}
					vitY = 0;
		}
	}
	return 1;
}


void Jucator::salt(float val)
{
	if (crouch)
		val = val / 2;
	if (vitY == 0 || (contact > 0 && vitY < 2) )
		vitY = -val;
	

}

void Jucator::Foc(sf::Vector2f target)
{
	if (!cooldownSchimbare)
	arma->foc({ x, y },target);
}

void Jucator::reload()
{
	arma->reload();
}


void Jucator::schimbaArma(int Q)
{
	arma = arme[Q];
	cooldownSchimbare = 90;
}

void Jucator::crunch()
{
	if (!crouch)
	{
		corp->setSize({ 40, 40 });
		y = y + 30;
		corp->setPosition({ x, y });
		crouch = 1;
	}
	}
void Jucator::unCrunch()
{
	corp->setSize({ 40, 70 });
	y = y - 30;
	corp->setPosition({ x, y });
	crouch = 0;
}