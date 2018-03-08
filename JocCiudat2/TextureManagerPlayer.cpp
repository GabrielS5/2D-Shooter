#include "TextureManagerPlayer.h"


TextureManagerPlayer::TextureManagerPlayer(vector<sf::Texture>* Texturi)
{
	texturi = Texturi;
	okMersStanga = okMersDreapta = 3;
}
void TextureManagerPlayer::update(float x, float y, float vitX, float vitY, bool crouch, float cX, float cY)
{

	if (crouch == 1)
	{
		if (cX<x)
			sprite = new sf::Sprite(texturi->at(0));
		else
			sprite = new sf::Sprite(texturi->at(1));
		sprite->setPosition(x, y);
		return;
		okMersDreapta = okMersStanga = 3;
	}

	if (vitY > 0)
	{
		if (vitX < 0)
		{
			if (cX<x)
				sprite = new sf::Sprite(texturi->at(5));
			else
				sprite = new sf::Sprite(texturi->at(3));
		}
		if (vitX > 0)
		{
			if (cX<x)
				sprite = new sf::Sprite(texturi->at(5));
			else
				sprite = new sf::Sprite(texturi->at(3));
     }
		okMersDreapta = okMersStanga = 3;
	}

	if (vitY < 0)
	{
		if (vitX < 0)
		{
			if (cX<x)
				sprite = new sf::Sprite(texturi->at(4));
			else
				sprite = new sf::Sprite(texturi->at(3));
		}
		if (vitX > 0)
		{
			if (cX<x)
				sprite = new sf::Sprite(texturi->at(5));
			else
				sprite = new sf::Sprite(texturi->at(2));
		}
		okMersDreapta = okMersStanga = 3;
	}

	if (vitY != 0 && vitX == 0)
	{
		sprite = new sf::Sprite(texturi->at(6));
	}

	if (vitX == 0 && vitY == 0)
	{
		if (cX<x)
			sprite = new sf::Sprite(texturi->at(7));
		else
			sprite = new sf::Sprite(texturi->at(8));
	}

	if (vitY ==0 && vitX > 0)
	{
		if (cX > x)
		{
			if (okMersDreapta == 3)
			{
				mersDreapta = (mersDreapta + 1) % 9;
				sprite = new sf::Sprite(texturi->at(9 + mersDreapta));
				mersStanga = 0;
				okMersDreapta = 0;
				okMersStanga = 3;
			}
			else
				okMersDreapta++;
		}
		if (cX < x)
		{
			if (okMersStanga==3)
			{
				mersStanga = (mersStanga - 1);
			if (mersStanga == -1)
				mersStanga = 8;
			sprite = new sf::Sprite(texturi->at(18 + mersStanga));
			mersDreapta = 0;
			okMersDreapta = 3;
			okMersStanga = 0;
		}
		else
			okMersStanga++;
		}
	}
	if (vitY ==0 && vitX < 0)
	{
		if (cX > x)
		{
			if (okMersDreapta == 3)
			{
				mersDreapta = (mersDreapta - 1) % 9;
				if (mersDreapta == -1)
					mersDreapta = 8;
				sprite = new sf::Sprite(texturi->at(9 + mersDreapta));
				mersStanga = 0;
				okMersDreapta = 0;
				okMersStanga = 3;
			}
			else
			{
				okMersDreapta++;
			}
		}
		if (cX < x)
		{
			if (okMersStanga == 3)
			{
			mersStanga = (mersStanga + 1) % 9;
			sprite = new sf::Sprite(texturi->at(18 + mersStanga));
			mersDreapta = 0;
			okMersDreapta = 3;
			okMersStanga = 0;
			}
			else
				okMersStanga++;
		}
	}

	sprite->setPosition(x, y);


}

void TextureManagerPlayer::draw(sf::RenderWindow &window)
{
	
	window.draw(*sprite);
	
}
