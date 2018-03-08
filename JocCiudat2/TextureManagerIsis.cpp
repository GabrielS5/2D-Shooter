#include "TextureManagerIsis.h"


TextureManagerIsis::TextureManagerIsis(vector<sf::Texture>* Texturi)
{
	texturi = Texturi;
	sprite = new sf::Sprite(texturi->at(3));
	nr = rand() % 3;
}
void TextureManagerIsis::update(float x, float y, float vitX, float vitY)
{
	
	if (vitY != 0)
	{
		if (vitX<0)
			sprite = new sf::Sprite(texturi->at(nr * 4+3));
		else
			sprite = new sf::Sprite(texturi->at(nr * 4+2));
	}
	else
	{
		if (vitX<0)
			sprite = new sf::Sprite(texturi->at(nr*4+1));
		else
			sprite = new sf::Sprite(texturi->at(nr*4+0));
	}
	sprite->setPosition(x, y);
	

}

void TextureManagerIsis::draw(sf::RenderWindow &window)
{

	window.draw(*sprite);
}