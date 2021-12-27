#include "bullet.h"
#include <iostream>
#include "player.h"
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include <cstdlib>
#include <ctime>

const int W = VideoMode::getDesktopMode().width;
const int H = VideoMode::getDesktopMode().height;

using namespace std;

bullet::bullet()
{
	s_b = new Sprite;

	t_b = new Texture;
	srand(time(0));
	string s[] = { "navy","purple","green", "blue", "orange", "red" };
	int i = rand() % (s->size() + 2);
	t_b->loadFromFile("images/game/fire/" + s[i] + ".png");
	t_b->setSmooth(true);
	s_b->setTexture(*t_b);
	speed = 10;
	this->degtorad = 0.017453f;
	flag = true;

	if (!buffer.loadFromFile("music/fire.wav"))
	{
		std::cout << "error";
	}
	sound.setBuffer(buffer);
}

bullet::~bullet()
{
	delete t_b; //destructor
	delete s_b;

	t_b = NULL;  //garbage collect
	s_b = NULL;
}

void bullet::animate(float dt)
{
	int kol = 16;

	for (int i = 0; i < bullets.size(); i++)
	{
		if (frames[i] <= kol)
		{
			frames[i] += dt * 15;
			bullets[i].setTextureRect(IntRect(0, int(frames[i]) * 32, 64, 32));
		}
		else if (frames[i] > kol)
		{
			bullets.erase(bullets.begin() + i);
			frames.erase(frames.begin() + i);
		}
	}
}

void bullet::setX(int x)
{
	s_b->setPosition(x, s_b->getPosition().y);
}

void bullet::setY(int y)
{
	s_b->setPosition(s_b->getPosition().x, y);
}

int bullet::getX()
{
	return s_b->getPosition().x;
}

int bullet::getY()
{
	return s_b->getPosition().y;
}

void bullet::move(float dt)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		int x = bullets[i].getPosition().x;
		int y = bullets[i].getPosition().y;
		float dx = 0;
		float dy = 0;
		float angle = bullets[i].getRotation();
		dx += cos(angle * degtorad) * dt * 350;
		dy += sin(angle * degtorad) * dt * 350;

		float speeds = sqrt(dx * dx + dy * dy);
		if (speeds > speed)
		{
			dx *= speed / speeds;
			dy *= speed / speeds;
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
		bullets[i].setPosition(x, y);
	}
}

void bullet::add(player* players, Event event, float dt)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (players->s_p->getRotation() == (bullets[i].getRotation() + 90))
		{
			flag = false;
			break;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Space) && flag)
	{
		if (event.KeyPressed)
		{
			sound.play();
			setX(players->getX());
			setY(players->getY());
			s_b->setRotation(players->s_p->getRotation() - 90);
			bullets.push_back(*s_b);
			frames.push_back(0);
		}
	}

	flag = true;
}

void bullet::draw(RenderWindow* w1)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		w1->draw(bullets[i]);
	}
}

void bullet::bulletAnimate(RenderWindow* w1, float dt, player* players, Event event)
{
	add(players, event, dt);
	animate(dt);
	move(dt);
	draw(w1);
}

void bullet::init()
{
	string s[] = { "navy","purple","green", "blue", "orange", "red" };
	int i = rand() % (s->size() + 2);
	t_b->loadFromFile("images/game/fire/" + s[i] + ".png");
	t_b->setSmooth(true);
	s_b->setTexture(*t_b);
	speed = 10;
	this->degtorad = 0.017453f;
	flag = true;
}
