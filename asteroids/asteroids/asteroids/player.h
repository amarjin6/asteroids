#pragma once

#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
using namespace sf;

class player
{
public:
	player();
	~player();
	void Movement(float dt, RenderWindow* w1, int c);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void init();
	bool isMove;
	Sprite* s_p;

private:
	Texture* t_p;
	float degtorad, angle, dx, dy, x, y;
	bool flag_1, flag_2, flag_3, check;
	float movementSpeed;
	bool life;
};

