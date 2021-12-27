#pragma once

#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "player.h"

using namespace sf;

class bullet
{
public:
	bullet();
	~bullet();
	std::vector<sf::Sprite> bullets;
	void bulletAnimate(RenderWindow* w1, float dt, player* players, Event event);
	void init();

private:
	SoundBuffer buffer;
	Sound sound;
	Texture* t_b;
	Sprite* s_b;
	std::vector<float> frames;
	bool flag;
	int speed;
	float degtorad;
	void add(player* players, Event event, float dt);
	void draw(RenderWindow* w1);
	void animate(float dt);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	void move(float dt);
};

