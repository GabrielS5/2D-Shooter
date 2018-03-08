#pragma once
#include"Biblioteci.h"
using namespace std;
class TextureManagerIsis
{
public:
	sf::Sprite *sprite;
	int nr;
	TextureManagerIsis(vector<sf::Texture>* Texturi);
	void update(float x, float y, float vitX, float vitY);
	vector<sf::Texture>* texturi;
void draw(sf::RenderWindow &window);
};

