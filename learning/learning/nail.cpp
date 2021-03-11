#include"pch.h"
#include"nail.h"





	Vector2f nposition;
	RectangleShape nailshape;


	nail::nail()
	{

		nposition.x = rand() % (VideoMode::getDesktopMode().width - 100);
		nposition.y = VideoMode::getDesktopMode().height - 40;
		nailshape.setSize(Vector2f(20, 80));
		nailshape.setPosition(nposition);
		nailshape.setFillColor(Color(0, 255, 0));

	}



