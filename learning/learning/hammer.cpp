#include "pch.h"
#include "hammer.h"





	hammer::hammer()
	{
		spacepressednum = 0;
		downspeed = 35;
		sidespeed = 12.5;
		left = true;
		right = up = down = false;
		hposition.x = VideoMode::getDesktopMode().width / 2;
		hposition.y = VideoMode::getDesktopMode().height / 4;

		hammershape.setSize(Vector2f(100, 50));
		hammershape.setFillColor(Color(150, 0, 150));
		hammershape.setPosition(hposition);

	}

	void hammer::movingleft()
	{
		up = false;
		down = false;
		right = false;
		left = true;
	}
	void hammer::movingright()
	{
		up = false;
		down = false;
		left = false;
		right = true;
	}
	void hammer::smashing()
	{
		up = false;
		left = false;
		right = false;
		down = true;
	}
	void hammer::returning()
	{
		down = false;
		up = true;
		left = false;
		right = false;
		
	}

	void hammer::updatehammer()
	{
		if (hposition.x < 0)
		{
			left = false;
			movingright();
		}
		if (hposition.x > VideoMode::getDesktopMode().width - 50)
		{
			right = false;
			movingleft();
		}
		if (hposition.y > VideoMode::getDesktopMode().height)
		{
			returning();
		}

		if (down == true)
		{
			hposition.y += downspeed;
		}
		if (up == true)
		{
			hposition.y -= 12.5;
		}
		if (left == true)
		{
			hposition.x -= sidespeed;
		}
		if (right == true)
		{
			hposition.x += sidespeed;
		}
		if (hposition.y < VideoMode::getDesktopMode().height / 4)
		{
			up = false;
			if (check == 1)
			{
				movingleft();
				check = 0;
			}
			if (check == 2)
			{
				movingright();
				check = 0;
			}
		}
		hammershape.setPosition(hposition);
	}

	void hammer::smash()
	{
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			if (left == true)
			{
				check = 1;
				smashing();
			}
			else if (right == true)
			{
				check = 2;
				smashing();
			}
			//spacepressednum += 1;

			
		}


	}

	void hammer::goleft()
	{
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			hammer::movingleft();
		}
	}

	void hammer::goright()
	{
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			hammer::movingright();
		}
	}

