
#include "Biblioteci.h"
#include"Teren.h"
#include"Jucator.h"
#include"Inamici.h"
#include"SemiAuto.h"
#include"Isis.h"
using namespace std;
int main(){
	int h = -4;
	h = h % 5;
	cout << h;
	vector<pair<sf::Vector2f, sf::Vector2f>> da;
	int blah = 0;
	srand(time(NULL));
	int auxTeren[20][20] = { 0 };
	for (int i = 0; i < Latime / 50; i++)
		auxTeren[9][i] = 1;
	auxTeren[6][8] = 1;
	auxTeren[6][9] = 1;
	auxTeren[6][10] = 1;
	auxTeren[6][11] = 1;
	auxTeren[6][12] = 1;
	int optiune=1;


	vector<sf::Texture> texturi;
	sf::Texture t;
	t.loadFromFile("Texturi\\isis1.png");
	texturi.push_back(t);
	t.loadFromFile("Texturi\\isis1rev.png");
	texturi.push_back(t);
	t.loadFromFile("Texturi\\isis1JUMP.png");
	texturi.push_back(t);
	t.loadFromFile("Texturi\\isis1JUMPrev.png");
	texturi.push_back(t);
	t.loadFromFile("Texturi\\isis2.png");
	texturi.push_back(t);
	t.loadFromFile("Texturi\\isis2rev.png");
	texturi.push_back(t);
	t.loadFromFile("Texturi\\isis2JUMP.png");
	texturi.push_back(t);
	t.loadFromFile("Texturi\\isis2JUMPrev.png");
	texturi.push_back(t);
	t.loadFromFile("Texturi\\isis3.png");
	texturi.push_back(t);
	t.loadFromFile("Texturi\\isis3rev.png");
	texturi.push_back(t);
	t.loadFromFile("Texturi\\isis3JUMP.png");
	texturi.push_back(t);
	t.loadFromFile("Texturi\\isis3JUMPrev.png");
	texturi.push_back(t);

	vector<sf::Texture> texturiP;
	t.loadFromFile("Texturi\\ctrlstanga.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\ctrldreapta.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\jumpdreapta.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\jumpdreapta2.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\jumpstanga.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\jumpstanga2.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\fata.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\profilstanga.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\profildreapta.png");
	texturiP.push_back(t);

	t.loadFromFile("Texturi\\dreapta1.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\dreapta2.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\dreapta3.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\dreapta4.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\dreapta5.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\dreapta6.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\dreapta7.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\dreapta8.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\dreapta9.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\stanga1.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\stanga2.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\stanga3.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\stanga4.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\stanga5.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\stanga6.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\stanga7.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\stanga8.png");
	texturiP.push_back(t);
	t.loadFromFile("Texturi\\stanga9.png");
	texturiP.push_back(t);

	Jucator jucator(&texturiP);
	cout << texturi.size();
	vector<Inamici*> inamici;
	for (int i = 0; i < 20; i++)
	{
		inamici.push_back(new Isis(-(rand() % 1000), rand() % Inaltime, 200, { 50, 50 }, new Auto(36, 12, 1, 12, 120, 70, 3, 10, 0.3), 4 + 2.5 * ((float)rand() / (float)RAND_MAX), 7 + 2 * ((float)rand() / (float)RAND_MAX), 90+rand()%20, &texturi));
	}
	
	Teren teren(auxTeren);
	sf::RenderWindow window(sf::VideoMode( Latime, Inaltime), "JocCiudat2");
	window.setFramerateLimit(60);

	while (window.isOpen()){

		sf::Event event;
		while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed)
				window.close();
			if (optiune == 1)
			{
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Right)
					{
						optiune = 0;
					}
					else
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							teren.adaugaTeren({ event.mouseButton.x / 50, event.mouseButton.y / 50 });
						}
				}
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::R)
					jucator.reload();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Num1)
					jucator.schimbaArma(1);
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Num2)
					jucator.schimbaArma(2);
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Num3)
					jucator.schimbaArma(3);
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Num4)
					jucator.schimbaArma(4);
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::LControl)
			{
				jucator.crunch();
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::LControl)
			{
				jucator.unCrunch();
			}



		}

		if (!optiune)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				jucator.modVitX(-5);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				jucator.modVitX(5);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				jucator.salt(6);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				float x, y;
				x=sf::Mouse::getPosition(window).x;
				y=sf::Mouse::getPosition(window).y;
				jucator.Foc({x,y});
			}
		}
		jucator.update(teren, inamici, sf::Mouse::getPosition(window).x);
		window.clear(sf::Color(100,100,100));
		if(blah<200)
		inamici.push_back(new Isis(-(rand() % 1000), rand() % Inaltime, 200, { 50, 50 }, new Auto(36, 12, 1, 12, 120, 70, 3, 10, 0.3), 4 + 2.5 * ((float)rand() / (float)RAND_MAX), 7 + 2 * ((float)rand() / (float)RAND_MAX), 90 + rand() % 20, &texturi));
		blah++;
		for (int i = inamici.size() - 1; i >= 0; i--)
		{
			if(inamici[i]->getHp()<=0)
				inamici.erase(inamici.begin() + i);
			}
		for (int i = 0; i < inamici.size(); i++)
		{
			inamici[i]->update(teren,jucator.getPosition(),jucator.getSize());
			inamici[i]->draw(&window);
		}
		jucator.draw(&window);
		teren.draw(&window);
		window.display();
	}
	cout << inamici.size();
}
