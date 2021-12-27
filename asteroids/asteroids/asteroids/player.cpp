#include "player.h"
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"

const int W = VideoMode::getDesktopMode().width;
const int H = VideoMode::getDesktopMode().height;

player::player()
{
	s_p = new Sprite;
	t_p = new Texture;
	t_p->loadFromFile("images/game/spaceship/ship.png");
	t_p->setSmooth(true);
	s_p->setTexture(*t_p);
	s_p->setTextureRect(IntRect(76, 0, 80, 78));
	s_p->setPosition(W / 2, H / 2);
	s_p->setScale(0.8, 0.8);

	this->movementSpeed = 15;
	this->degtorad = 0.017453f;
	angle = 0;
	dx = 0;
	dy = 0;
	x = 0;
	y = 0;
	life = true;
	isMove = false;
	flag_1 = false;
	flag_2 = false;
	flag_3 = false;
	check = true;
}

player::~player()
{
	delete t_p;  //desturctor

	t_p = NULL;  //garbage collect

	delete s_p;

	s_p = NULL;

}

void player::Movement(float dt, RenderWindow* w1, int c)
{
	x = s_p->getPosition().x;
	y = s_p->getPosition().y;

	if (check)
	{
		if (c == 1)
		{
			t_p->loadFromFile("images/game/spaceship/ship.png");
			t_p->setSmooth(true);
			s_p->setTexture(*t_p);
			s_p->setTextureRect(IntRect(76, 0, 80, 78));
			s_p->setPosition(W / 2, H / 2);
			s_p->setScale(0.8, 0.8);
		}

		if (c == 2)
		{
			t_p->loadFromFile("images/game/spaceship/pointer.png");
			s_p->setTexture(*t_p);
			s_p->setTextureRect(IntRect(0, 0, 256, 256));
			s_p->setScale(0.25, 0.25);
		}

		if (c == 3)
		{
			t_p->loadFromFile("images/game/spaceship/ship_1.png");
			s_p->setTexture(*t_p);
			s_p->setTextureRect(IntRect(0, 0, 531, 854));
			s_p->setScale(0.15, 0.10);
		}

		if (c == 4)
		{
			t_p->loadFromFile("images/game/spaceship/ship_2.png");
			s_p->setTexture(*t_p);
			s_p->setTextureRect(IntRect(0, 0, 713, 935));
			s_p->setScale(0.1, 0.1);
		}

		check = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
	{
		dx += cos(angle * degtorad) * dt * 10;
		dy += sin(angle * degtorad) * dt * 10;
		isMove = true;
		flag_1 = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
	{
		angle += 3;
		dx *= 0.99;
		dy *= 0.99;
		isMove = true;
		flag_2 = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
	{
		angle -= 3;
		dx *= 0.99;
		dy *= 0.99;
		isMove = true;
		flag_3 = true;
	}

	float speed = sqrt(dx * dx + dy * dy);
	if (speed > movementSpeed)
	{
		dx *= movementSpeed / speed;
		dy *= movementSpeed / speed;
	}
	x += dx;
	y += dy;

	if (x > W)
	{
		x = 0;
	}
	if (x < 0)
	{
		x = W;
	}

	if (y > H)
	{
		y = 0;
	}
	if (y < 0)
	{
		y = H;
	}

	s_p->setPosition(x, y);
	s_p->setRotation(angle + 90);

	if (c == 1)
	{
		if (flag_1 && flag_3)
		{
			s_p->setTextureRect(IntRect(157, 80, 78, 86));
		}
		else if (flag_1 && flag_2)
		{
			s_p->setTextureRect(IntRect(0, 80, 78, 86));
		}
		else if (flag_1)
		{
			s_p->setTextureRect(IntRect(80, 80, 80, 86));
		}
		else if (flag_3)
		{
			s_p->setTextureRect(IntRect(155, 0, 78, 78));
		}
		else if (flag_2)
		{
			s_p->setTextureRect(IntRect(0, 0, 78, 78));
		}
		else
		{
			s_p->setTextureRect(IntRect(76, 0, 80, 78));
		}
	}

	if (c == 3 && flag_1)
	{
		s_p->setTextureRect(IntRect(531, 0, 531, 854));
	}

	else if (c == 3 && !flag_1)
	{
		s_p->setTextureRect(IntRect(0, 0, 531, 854));
	}

	if (c == 4 && flag_1)
	{
		s_p->setTextureRect(IntRect(713, 0, 713, 935));
	}

	else if (c == 4 && !flag_1)
	{
		s_p->setTextureRect(IntRect(0, 0, 713, 935));
	}

	flag_1 = false;
	flag_2 = false;
	flag_3 = false;
}

void player::setX(int x)
{
	s_p->setPosition(x, s_p->getPosition().y);
}

void player::setY(int y)
{
	s_p->setPosition(s_p->getPosition().x, y);
}

int player::getX()
{
	return s_p->getPosition().x;
}

int player::getY()
{
	return s_p->getPosition().y;
}

void player::init()
{
	this->movementSpeed = 15;
	this->degtorad = 0.017453f;
	angle = 0;
	dx = 0;
	dy = 0;
	x = 0;
	y = 0;
	life = true;
	isMove = false;
	flag_1 = false;
	flag_2 = false;
	flag_3 = false;
	check = true;
}
