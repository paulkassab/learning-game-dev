#include "pch.h"
#include "engine.h"



	
	engine::engine()
	{
		srand(time(0));
		Clock timer;
		resolution.x = VideoMode::getDesktopMode().width;
		resolution.y = VideoMode::getDesktopMode().height;
		scorevalue = 0;
		speedvalue = 10;
		accuracyvalue = 0;
		scorestring = std::to_string(scorevalue);
		speedstring = std::to_string(speedvalue);
		accuracystring = std::to_string(accuracyvalue);
		paused = false;
		gamewindow.create(VideoMode(resolution.x - 50, resolution.y - 150), "Game Window", Style::Fullscreen);
		//gamewindow.setFramerateLimit(60);
		gamewindow.setVerticalSyncEnabled(true);
		scorefont.loadFromFile("Famirids.ttf");
		score.setFont(scorefont);
		score.setCharacterSize(75);
		score.setFillColor(Color(255, 0, 0));
		score.setString("Score: ");
		//////////////////////////////////////////////////
		scorev.setFont(scorefont);
		scorev.setCharacterSize(75);
		scorev.setFillColor(Color(255, 0, 0));
		scorev.setString(scorestring);
		scorev.setPosition(score.getPosition().x + 300, 0);
		///////////////////////////////////////////////////
		speedv.setFont(scorefont);
		speedv.setCharacterSize(75);
		speedv.setFillColor(Color(255, 0, 0));
		speedv.setString(speedstring);
		speedv.setPosition(score.getPosition().x + 800, 0);
		////////////////////////////////////////////////////
		/*accuracyv.setFont(scorefont);
		accuracyv.setCharacterSize(75);
		accuracyv.setFillColor(Color(255, 0, 0));
		accuracyv.setString(accuracystring);
		accuracyv.setPosition(score.getPosition().x + 1200, 0);*/

		pause.setFont(scorefont);
		pause.setCharacterSize(100);
		pause.setPosition(Vector2f(resolution.x / 4, resolution.y / 2));
		pause.setFillColor(Color::White);
		pause.setString("GAME PAUSED");
		/////////////////////////////////////////////////

		speed.setFont(scorefont);
		speed.setCharacterSize(75);
		speed.setFillColor(Color(255, 0, 0));
		speed.setString("Speed: ");
		speed.setPosition(Vector2f(resolution.x / 2 - 200, 0));
		accuracy.setFont(scorefont);
		accuracy.setCharacterSize(75);
		accuracy.setFillColor(Color(255, 0, 0));
		accuracy.setString("Accuracy: ");
		accuracy.setPosition(Vector2f(resolution.x - 400, 0));
		backgrndT.loadFromFile("background.jpg");
		backgrndS.setTexture(backgrndT);
		b = new hammer();
		a = new nail();
		nailexists = true;
	}


	void engine:: start()
	{
		while (gamewindow.isOpen())
		{
			engine::input();
			engine::update();
			engine::draw();
		}
	}




	void  engine::input()
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			gamewindow.close();
		}


		if (Keyboard::isKeyPressed(Keyboard::P))
		{
			if (paused == false)
			{
				paused = true;
			}
			if (paused == true)
			{
				paused = false;
			}
		}

		b->smash();
		b->goleft();
		b->goright();
	}


	void engine::update()
	{
		
		if (paused == false)
		{
			b->updatehammer();

			if (a->nailshape.getGlobalBounds().intersects(b->hammershape.getGlobalBounds()))
			{
				delete a;
				nailexists = false;



			}

			if (nailexists == false)
			{
				//
				a = new nail();
				nailexists = true;
				scorevalue += 1;
				speedvalue += 2;
				b->sidespeed += 1;
			}

			//accuracyvalue = scorevalue / b->spacepressednum * 100;

			scorestring = std::to_string(scorevalue);
			scorev.setString(scorestring);
			speedstring = std::to_string(speedvalue);
			speedv.setString(speedstring);
			//accuracystring = std::to_string(accuracyvalue);
			//accuracyv.setString(accuracystring);
		}
	}

	void engine:: draw()
	{
		gamewindow.clear(Color::Black);
		if (paused == false)
		{
			gamewindow.draw(backgrndS);
			gamewindow.draw(score);
			gamewindow.draw(scorev);
			gamewindow.draw(speedv);
			//gamewindow.draw(accuracyv);
			gamewindow.draw(speed);
			//gamewindow.draw(accuracy);
			gamewindow.draw(a->nailshape);
			gamewindow.draw(b->hammershape);
		}
		else if (paused==true)
		{
			gamewindow.draw(pause);
		}
		gamewindow.display();
	}
