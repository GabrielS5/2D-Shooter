#include "Teren.h"

using namespace std;
Teren::Teren(int auxTeren[20][20])
{
	for (int i = 0; i < Inaltime / 50; i++)
	{
		for (int j = 0; j < Latime / 50; j++)
		{
			AuxTeren[i][j] = auxTeren[i][j];
		}
	}
	modificaTeren(auxTeren);

}


void Teren::draw(sf::RenderWindow* window)
{

	for (int i = 0; i < Inaltime / 50; i++)
	{
		for (int j = 0; j < Latime / 50; j++)
		{
			if (teren[i][j] != NULL)
				window->draw(*teren[i][j]);
			
		}

	}


}

void Teren::modificaTeren(int auxTeren[20][20])
{

	for (int i = 0; i < Inaltime / 50; i++)
	{
		for (int j = 0; j < Latime / 50; j++)
		{
			if (auxTeren[i][j] == 1)
			{
				teren[i][j] = new sf::RectangleShape();
				teren[i][j]->setFillColor(sf::Color::Red);
				teren[i][j]->setSize({ 50, 50 });
				teren[i][j]->setPosition(j * 50, i * 50);
				teren[i][j]->setOutlineThickness(-1);
				teren[i][j]->setOutlineColor(sf::Color::Yellow);

			}
			else
				teren[i][j] = NULL;

		}

	}

}

void Teren::adaugaTeren(sf::Vector2i pereche)
{
	AuxTeren[pereche.y][pereche.x] = (AuxTeren[pereche.y][pereche.x] + 1) % TipuriTeren;
	modificaTeren(AuxTeren);

}


bool Teren::coliziunePunct(sf::Vector2f punct)
{
	if (AuxTeren[(int)punct.y/50][(int)punct.x/50] != 0)
		return 1;
	return 0;
}
float Teren::coliziuneFigura(int x, int y,int l, int L)
{
	if (y <= 0)
		return 0;
	if (y >= Inaltime-l-50)
		return 1;
	if (x<-L || y<-l || x>Latime )
	{
		return 0;
	}
	int X = x / 50, Y = y / 50,X2=X+3,Y2=Y+3;
	if (X2>Latime / 50)
		X2 = Latime / 50;
	if (Y2 > Inaltime / 50)
		Y2 = Inaltime / 50;
	
	for (int i = Y; i < Y2; i++)
	{
		for (int j = X; j < X2; j++)
		{
			if (teren[i][j] != NULL)

			{
				if (!(y>teren[i][j]->getPosition().y + 50) && !(y + l<teren[i][j]->getPosition().y))
					if (!(x>teren[i][j]->getPosition().x + 50) && !(x + L < teren[i][j]->getPosition().x))
					{
						return teren[i][j]->getPosition().x+1;
					}
			}
			}
	}
	return 0;
}