#pragma once
#include "Teren.h"
#include"Arme.h"
#include "SemiAuto.h"
#include"Auto.h"
#include"Shotgun.h"
#include"AutoShotgun.h"
#include"Inamici.h"
#include"TextureManagerPlayer.h"
class Jucator 
{
private:
	TextureManagerPlayer* textura;
	sf::RectangleShape *corp;
	bool crouch;
	int hp,contact,interzisC,optiuneArma,cooldownSchimbare;
	bool pePodea,langaPerete;
	float vitX, vitY, x, y, interzis;
	Arme* arma;
	Arme* arme[10];
public:
	Jucator(vector<sf::Texture>* Texturi);
	void update(Teren teren, vector<Inamici*> inamici,int cX);
	 void draw(sf::RenderWindow *window) ;
	 void modVitX(float vit);
	 void modVitY(float vit);
	 sf::Vector2f getPosition();
	 sf::Vector2f getSize();
	 int coliziune(Teren teren);
	 void salt(float val);
	 void Foc(sf::Vector2f target);
	 void reload();
	 void schimbaArma(int Q);
	 bool coliziuneInamic(Inamici* inamic);
	 void crunch();
	 void unCrunch();
	 };

