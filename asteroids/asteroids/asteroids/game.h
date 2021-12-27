#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "player.h"
#include "menu.h"
#include "bullet.h"

using namespace sf;

class game
{
public:
	bool pause;
	game();
	~game();
	void update(float dt, RenderWindow* w1, player* players, menu* menus, bullet* bullets, Event event, int b, int c);

private:
	bool flag, lose, win;
	float frame, frame_1, frame_2;
	float degtorad, angle, dx, dy, x, y;
	int coin_count;
	int rock_count;
	int life_count;
	int snowflake_count;
	int rock_destroy;
	int coin_collect;
	int k, boost, size, boom;
	int rock, location;
	Texture* t1, * t2, * t3, * t, * t4, * t5, * t_pause, * t_play, * t_exit, * t_rock, * t_life, * t_rock1, * t_boom1, * t_boom2, * t_boom3, * t_win, * t_lose, * t_collect, * t_snowflake, * t_fog, * t_satelite, * t_satelite1, * t_fog1, * t_fog2;
	std::vector<sf::Sprite> coins;
	std::vector<sf::Sprite> rocks;
	std::vector<sf::Sprite> lifes;
	std::vector<sf::Sprite> snowflakes;
	std::vector<sf::Sprite> satelites;
	std::vector<sf::Sprite> fogs;
	std::vector<int> speed;
	Sprite* s1, * s2, * s3, * s, * s_pause, * s_play, * s_exit, * s_boom1, * s_boom2, * s_boom3, * s_win, * s_lose, * s_collect, * s_fog, * s_satelite;
	Font* font;
	Text* tx1, * tx2;
	SoundBuffer buffer, buffer_1, buffer_2, buffer_3, buffer_4;
	Sound sound, sound_1, sound_2, sound_3, sound_4;

	void coinAnimate(float dt, RenderWindow* w1);
	void rockAnimate(float dt, RenderWindow* w1);
	void snowflakeAnimate(float dt, RenderWindow* w1);
	void fogAnimate(float dt, RenderWindow* w1);
	void sateliteAnimate(float dt, RenderWindow* w1);
	void pauseMode(RenderWindow* w1, menu* menus, player* players, bullet* bullets);
	void rockMovement(float dt, RenderWindow* w1);
	void drawLife(RenderWindow* w1);
	void difficulty(float dt, RenderWindow* w1);
	void boomAnimate(float dt, RenderWindow* w1, Sprite* s, int kol, int boost, int size);
	void collectAnimate(float dt, RenderWindow* w1, Sprite s);
	void collision(player* players, RenderWindow* w1, float dt, bullet* bullets);
	void getBackround(int b, RenderWindow* w1);
};

