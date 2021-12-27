#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"

using namespace sf;

class enter
{
public:
	int k = 0;
	enter();
	~enter();
	void update(RenderWindow* w1, float dt);

private:
	int kol;
	float frame;
	Texture* t1, * t2, * t3;
	Font* font;
	Text* text;
	Sprite* s1, * s2, * s3;
	SoundBuffer buffer;
	Sound sound;
	void press(RenderWindow* w1, float dt);
	void draw(RenderWindow* w1);
};


