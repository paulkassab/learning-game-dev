#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class hammer
{
public:
	bool left;
	bool right;
	bool up;
	bool down;
	int check = 0, spacepressednum;
	Vector2f hposition;
	RectangleShape hammershape;

	float downspeed, sidespeed;


	hammer();
	

	void movingleft();

	void movingright();
	
	void smashing();
	
	void returning();
	

	void updatehammer();
	

	void smash();

	void goleft();

	void goright();


};