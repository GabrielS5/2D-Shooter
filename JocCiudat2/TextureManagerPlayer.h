#pragma once
#include"Biblioteci.h"
using namespace std;
class TextureManagerPlayer
{
public:
	int mersDreapta, mersStanga,okMersStanga,okMersDreapta;
	sf::Sprite *sprite;
	TextureManagerPlayer(vector<sf::Texture>* Texturi);
	void update(float x, float y, float vitX, float vitY,bool crouch,float cX,float cY);
	vector<sf::Texture>* texturi;
	void draw(sf::RenderWindow &window);
};

