#pragma once
#include "pch.h"
#include "hammer.h"
#include "nail.h"
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <cstring>

using namespace sf;

class engine
{
public:
	RenderWindow gamewindow;
	Vector2f resolution;
	Sprite backgrndS;
	Texture backgrndT;
	hammer* b=NULL;
	nail* a=NULL ;
	bool nailexists=false;
	Text score, speed, accuracy, scorev, speedv, accuracyv, pause;
	bool paused;
	Font scorefont;

	std::string scorestring;
	int scorevalue;

	std::string speedstring;
	int speedvalue;

	std::string accuracystring;
	int accuracyvalue;

	
	Clock timer;

	

	engine();


	void start();
	




	void input();



	void update();

	void draw();
};