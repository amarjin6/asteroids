#include "game.h"
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include <SFML/System.hpp>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
using namespace sf;

const int W = VideoMode::getDesktopMode().width;
const int H = VideoMode::getDesktopMode().height;

game::game()
{
	srand(time(0));

	s1 = new Sprite;
	s2 = new Sprite;
	s3 = new Sprite;
	s = new Sprite;
	s_pause = new Sprite;
	s_play = new Sprite;
	s_exit = new Sprite;
	s_boom1 = new Sprite;
	s_boom2 = new Sprite;
	s_boom3 = new Sprite;
	s_win = new Sprite;
	s_lose = new Sprite;
	s_collect = new Sprite;
	s_fog = new Sprite;
	s_satelite = new Sprite;

	tx1 = new Text;
	tx2 = new Text;

	font = new Font;

	t2 = new Texture;
	t3 = new Texture;
	t = new Texture;
	t4 = new Texture;
	t5 = new Texture;
	t_pause = new Texture;
	t_play = new Texture;
	t_exit = new Texture;
	t_rock = new Texture;
	t_life = new Texture;
	t_rock1 = new Texture;
	t_boom1 = new Texture;
	t_boom2 = new Texture;
	t_boom3 = new Texture;
	t_win = new Texture;
	t_lose = new Texture;
	t_collect = new Texture;
	t_snowflake = new Texture;
	t_fog = new Texture;
	t_satelite = new Texture;
	t_satelite1 = new Texture;
	t_fog1 = new Texture;
	t_fog2 = new Texture;

	t->loadFromFile("images/game/coin/pause.png");
	t->setSmooth(true);
	s->setTexture(*t);
	s->setScale(0.15, 0.15);
	s->setPosition(W / 2 - 37, 10);
	s->setColor(Color(255, 255, 255, 85));

	t2->loadFromFile("images/game/coin/score.png");
	t2->setSmooth(true);
	s2->setTexture(*t2);
	s2->setScale(0.09, 0.09);
	s2->setPosition(10, 10);
	s2->setColor(Color(255, 255, 255, 180));

	t3->loadFromFile("images/game/coin/wallet.png");
	t3->setSmooth(true);
	s3->setTexture(*t3);
	s3->setPosition(10, 60);
	s3->setScale(0.1, 0.1);
	s3->setColor(Color(255, 255, 255, 180));

	font->loadFromFile("fonts/eng.ttf");

	tx1->setFont(*font);
	tx1->setString("");
	tx1->setCharacterSize(30);
	tx1->setFillColor(Color(255, 255, 255, 200));
	tx1->setStyle(Text::Bold);
	tx1->setPosition(70, 15);

	tx2->setFont(*font);
	tx2->setString("");
	tx2->setCharacterSize(30);
	tx2->setFillColor(Color(255, 255, 255, 200));
	tx2->setStyle(Text::Bold);
	tx2->setPosition(70, 70);

	flag = true;
	lose = false;
	win = false;

	t4->loadFromFile("images/game/coin/coin.png");
	t4->setSmooth(true);

	t5->loadFromFile("images/game/coin/coin1.png");
	t5->setSmooth(true);

	t_rock->loadFromFile("images/game/rock/rock.png");
	t_rock->setSmooth(true);

	t_rock1->loadFromFile("images/game/rock/rock_small.png");
	t_rock1->setSmooth(true);

	t_life->loadFromFile("images/game/coin/life.png");
	t_life->setSmooth(true);

	t_boom1->loadFromFile("images/game/explosions/boom_1.png");
	t_boom1->setSmooth(true);
	s_boom1->setTexture(*t_boom1);

	t_boom2->loadFromFile("images/game/explosions/boom_2.png");
	t_boom2->setSmooth(true);
	s_boom2->setTexture(*t_boom2);

	t_boom3->loadFromFile("images/game/explosions/boom_3.png");
	t_boom3->setSmooth(true);
	s_boom3->setTexture(*t_boom3);

	t_lose->loadFromFile("images/game/coin/game_over.jpg");
	t_lose->setSmooth(true);
	s_lose->setTexture(*t_lose);
	s_lose->setScale(1.36, 1.226);
	s_lose->setPosition(W / 3.5, H / 4);

	t_collect->loadFromFile("images/game/coin/collect.png");
	t_collect->setSmooth(true);
	s_collect->setTexture(*t_collect);

	t_win->loadFromFile("images/game/coin/you_win.jpg");
	t_win->setSmooth(true);
	s_win->setTexture(*t_win);
	s_win->setScale(1.327, 1.199);
	s_win->setPosition(W / 3.5, H / 4);

	t_satelite->loadFromFile("images/game/difficulty/satelite2.png");
	t_satelite->setSmooth(true);

	t_satelite1->loadFromFile("images/game/difficulty/satelite1.png");
	t_satelite1->setSmooth(true);

	t_snowflake->loadFromFile("images/game/difficulty/snowflake.png");
	t_snowflake->setSmooth(true);

	snowflake_count = rand() % 3 + 1;

	// Create a vector of c sprites initialised with the texture above
	for (int i = 0; i < snowflake_count; i++)
	{
		snowflakes.push_back(sf::Sprite(*t_snowflake));
	}

	for (int i = 0; i < snowflakes.size(); i++) {
		int x = (rand() % (W - 180)) + 100;
		int y = ((rand() % (H - 180)) + 100);
		snowflakes[i].setPosition(x, y);
		snowflakes[i].setTextureRect({ 0,0,209,215 });
	}

	coin_count = rand() % 21 + 10;

	// Create a vector of c sprites initialised with the texture above
	for (int i = 0; i < coin_count; i++)
	{
		if (i < coin_count / 2)
		{
			coins.push_back(sf::Sprite(*t4));
		}
		if (i >= coin_count / 2)
		{
			coins.push_back(sf::Sprite(*t5));
		}
	}

	for (int i = 0; i < coins.size(); i++) {
		int x = (rand() % (W - 180)) + 100;
		int y = ((rand() % (H - 180)) + 100);
		coins[i].setPosition(x, y);
		coins[i].setTextureRect({ 0,0,135,138 });
	}

	frame = 0;
	frame_1 = 0;
	frame_2 = 0;
	rock_count = rand() % 35 + 20;
	// Create a vector of c sprites initialised with the texture above
	for (int i = 0; i < rock_count; i++)
	{
		if (i < rock_count / 2)
		{
			rocks.push_back(sf::Sprite(*t_rock));
		}

		if (i >= rock_count / 2)
		{
			rocks.push_back(sf::Sprite(*t_rock1));
		}
		speed.push_back(rand() % 10 + 5);
	}

	for (int i = 0; i < rocks.size(); i++) {
		int x = (rand() % (W - 50));
		int y = (rand() % (H - 20));
		rocks[i].setPosition(x, y);
		rocks[i].setTextureRect({ 0,0,64,64 });
		rocks[i].setRotation(rand() % 360);
	}

	t_pause->loadFromFile("images/game/coin/pause_msg.png");
	t_pause->setSmooth(true);
	s_pause->setTexture(*t_pause);
	s_pause->setPosition(W / 3.5, H / 4);
	s_pause->setColor(Color(255, 255, 255, 255));

	t_play->loadFromFile("images/background/play.png");
	t_play->setSmooth(true);
	s_play->setTexture(*t_play);
	s_play->setPosition(W / 2.19, H / 3.1);
	s_play->setScale(0.7, 0.7);
	s_play->setColor(Color(255, 255, 255, 85));

	t_exit->loadFromFile("images/game/coin/exit.png");
	t_exit->setSmooth(true);
	s_exit->setTexture(*t_exit);
	s_exit->setPosition(W / 1.48, H / 1.57);
	s_exit->setScale(0.15, 0.15);
	s_exit->setColor(Color(255, 255, 255, 85));

	t_fog->loadFromFile("images/game/difficulty/particle_dust.png");
	t_fog->setSmooth(true);

	s_fog->setTexture(*t_fog);

	t_fog1->loadFromFile("images/game/difficulty/particle_smoke.png");
	t_fog1->setSmooth(true);

	t_fog2->loadFromFile("images/game/difficulty/particle_smoke2.png");
	t_fog2->setSmooth(true);

	x = 0;
	y = 0;
	dx = 0;
	dy = 0;
	this->degtorad = 0.017453f;
	angle = 0;
	pause = false;
	life_count = rand() % 3 + 3;
	rock_destroy = 0;
	coin_collect = 0;
	k = 0;
	size = 0;
	boost = 0;
	boom = 0;
	rock = -1;
	location = 0;
	// Create a vector of c sprites initialised with the texture above
	for (int i = 0; i < life_count; i++)
	{
		lifes.push_back(sf::Sprite(*t_life));
	}

	for (int i = 0; i < lifes.size(); i++) {
		int pos = W - life_count * 40;
		lifes[i].setPosition(pos + i * 40, 15);
		lifes[i].setScale(0.15, 0.15);
	}

	string s = to_string(rock_destroy) + " / " + to_string(rock_count);
	tx1->setString(s);
	s = to_string(coin_collect) + " / " + to_string(coin_count);
	tx2->setString(s);

	if (!buffer.loadFromFile("music/click_3.wav"))
	{
		std::cout << "error";
	}
	sound.setBuffer(buffer);

	if (!buffer_1.loadFromFile("music/click_2.wav"))
	{
		std::cout << "error";
	}
	sound_1.setBuffer(buffer_1);

	if (!buffer_2.loadFromFile("music/collect.wav"))
	{
		std::cout << "error";
	}
	sound_2.setBuffer(buffer_2);

	if (!buffer_3.loadFromFile("music/collide_1.wav"))
	{
		std::cout << "error";
	}
	sound_3.setBuffer(buffer_3);

	if (!buffer_4.loadFromFile("music/dead.wav"))
	{
		std::cout << "error";
	}
	sound_4.setBuffer(buffer_4);
}

game::~game()
{
	delete t1;  //desturctor
	delete t2;
	delete t3;
	delete t4;
	delete t;
	delete t5;
	delete t_pause;
	delete t_play;
	delete t_exit;
	delete t_rock;
	delete t_life;
	delete t_rock1;
	delete t_boom1;
	delete t_boom2;
	delete t_boom3;
	delete t_win;
	delete t_lose;
	delete t_collect;
	delete t_snowflake;
	delete t_fog;
	delete t_satelite1;
	delete t_satelite;
	delete t_fog1;
	delete t_fog2;

	t1 = NULL;  //garbage collect
	t2 = NULL;
	t3 = NULL;
	t4 = NULL;
	t = NULL;
	t5 = NULL;
	t_pause = NULL;
	t_play = NULL;
	t_exit = NULL;
	t_rock = NULL;
	t_life = NULL;
	t_rock1 = NULL;
	t_boom1 = NULL;
	t_boom2 = NULL;
	t_boom3 = NULL;
	t_win = NULL;
	t_lose = NULL;
	t_collect = NULL;
	t_snowflake = NULL;
	t_fog = NULL;
	t_satelite1 = NULL;
	t_satelite = NULL;
	t_fog1 = NULL;
	t_fog2 = NULL;

	delete s1;
	delete s2;
	delete s3;
	delete s;
	delete s_pause;
	delete s_play;
	delete s_exit;
	delete s_boom1;
	delete s_boom2;
	delete s_boom3;
	delete s_win;
	delete s_lose;
	delete s_collect;
	delete s_fog;
	delete s_satelite;

	s1 = NULL;
	s2 = NULL;
	s3 = NULL;
	s = NULL;
	s_pause = NULL;
	s_play = NULL;
	s_exit = NULL;
	s_boom1 = NULL;
	s_boom2 = NULL;
	s_boom3 = NULL;
	s_win = NULL;
	s_lose = NULL;
	s_collect = NULL;
	s_fog = NULL;
	s_satelite = NULL;

	delete tx1;
	delete tx2;
	delete font;

	tx1 = NULL;
	tx2 = NULL;
	font = NULL;
}

void game::getBackround(int b, RenderWindow* w1)
{
	if (flag)
	{
		if (b == 1)
		{
			t1 = new Texture;
			t1->loadFromFile("images/background/b1.jpg");
			t1->setSmooth(true);
		}
		if (b == 2)
		{
			t1 = new Texture;
			t1->loadFromFile("images/background/b2.jpg");
			t1->setSmooth(true);
		}
		if (b == 3)
		{
			t1 = new Texture;
			t1->loadFromFile("images/background/b3.jpg");
			t1->setSmooth(true);
		}
		if (b == 4)
		{
			t1 = new Texture;
			t1->loadFromFile("images/background/b4.jpg");
			t1->setSmooth(true);
		}
		if (b == 5)
		{
			t1 = new Texture;
			t1->loadFromFile("images/background/b5.jpg");
			t1->setSmooth(true);
		}
		if (b == 6)
		{
			t1 = new Texture;
			t1->loadFromFile("images/background/b6.jpg");
			t1->setSmooth(true);
		}
		if (b == 7)
		{
			t1 = new Texture;
			t1->loadFromFile("images/background/b7.jpg");
			t1->setSmooth(true);
		}
		if (b == 8)
		{
			t1 = new Texture;
			t1->loadFromFile("images/background/b8.jpg");
			t1->setSmooth(true);
		}
		if (b == 9)
		{
			t1 = new Texture;
			t1->loadFromFile("images/background/b9.jpg");
			t1->setSmooth(true);
		}
		if (b == 10)
		{
			t1 = new Texture;
			t1->loadFromFile("images/background/b10.jpg");
			t1->setSmooth(true);
		}
		if (b == 11)
		{
			t1 = new Texture;
			t1->loadFromFile("images/background/b11.jpg");
			t1->setSmooth(true);
		}
		if (b == 12)
		{
			t1 = new Texture;
			t1->loadFromFile("images/background/b12.jpg");
			t1->setSmooth(true);
		}
		if (b == 13)
		{
			t1 = new Texture;
			t1->loadFromFile("images/background/b13.jpg");
			t1->setSmooth(true);
		}
		if (b == 14)
		{
			t1 = new Texture;
			t1->loadFromFile("images/background/b14.jpg");
			t1->setSmooth(true);
		}

		s1->setTexture(*t1);
		s1->setTextureRect(sf::IntRect(0, 0, W, H));

		flag = false;
	}

	w1->draw(*s1);
	w1->draw(*s2);
	w1->draw(*s3);
	w1->draw(*tx1);
	w1->draw(*tx2);
	w1->draw(*s);
	drawLife(w1);

	auto mouse_pos = Mouse::getPosition(*w1);
	auto translated_pos = w1->mapPixelToCoords(mouse_pos);

	if (s->getGlobalBounds().contains(translated_pos))
	{
		if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
		{
			pause = true;
			sound_1.play();
			sleep(milliseconds(150));
		}
		s->setColor(Color(255, 255, 255));
	}

	if (!s->getGlobalBounds().contains(translated_pos))
	{
		s->setColor(Color(255, 255, 255, 85));
	}
}

void game::coinAnimate(float dt, RenderWindow* w1)
{
	int kol = 10;
	frame += dt * 10;

	if (frame > kol)
	{
		frame -= kol;
	}

	for (int i = 0; i < coins.size(); i++)
	{
		coins[i].setTextureRect(IntRect(int(frame) * 135, 0, 135, 138));
		coins[i].setScale(0.4, 0.4);
	}

	for (int i = 0; i < coins.size(); i++)
	{
		w1->draw(coins[i]);
	}
}

void game::rockAnimate(float dt, RenderWindow* w1)
{
	int kol = 16;
	frame_1 += dt * 10;

	if (frame_1 > kol)
	{
		frame_1 -= kol;
	}

	for (int i = 0; i < rocks.size(); i++)
	{
		rocks[i].setTextureRect(IntRect(int(frame_1) * 64, 0, 64, 64));
	}

	for (int i = 0; i < rocks.size(); i++)
	{
		w1->draw(rocks[i]);
	}
}

void game::snowflakeAnimate(float dt, RenderWindow* w1)
{
	int kol = 7;
	frame += dt;

	if (frame > kol)
	{
		frame -= kol;
	}

	for (int i = 0; i < snowflakes.size(); i++)
	{
		snowflakes[i].setTextureRect(IntRect(int(frame) * 209, 0, 209, 215));
		snowflakes[i].setScale(0.4, 0.4);
	}

	for (int i = 0; i < snowflakes.size(); i++)
	{
		w1->draw(snowflakes[i]);
	}
}

void game::fogAnimate(float dt, RenderWindow* w1)
{
	for (int i = 0; i < fogs.size(); i++)
	{
		int s = 12;
		x = fogs[i].getPosition().x;
		y = fogs[i].getPosition().y;
		dx = 0;
		dy = 0;
		angle = fogs[i].getRotation();
		dx += cos(angle * degtorad) * dt * 100;
		dy += sin(angle * degtorad) * dt * 100;

		float speeds = sqrt(dx * dx + dy * dy);
		if (speeds > s)
		{
			dx *= s / speeds;
			dy *= s / speeds;
		}

		x += dx;
		y += dy;

		fogs[i].setPosition(x, y);
		w1->draw(fogs[i]);

		if (x > W)
		{
			fogs.erase(fogs.begin() + i);
		}
		if (x < 0)
		{
			fogs.erase(fogs.begin() + i);
		}

		if (y > H)
		{
			fogs.erase(fogs.begin() + i);
		}
		if (y < 0)
		{
			fogs.erase(fogs.begin() + i);
		}
	}
}

void game::sateliteAnimate(float dt, RenderWindow* w1)
{
	for (int i = 0; i < satelites.size(); i++)
	{
		int s = 12;
		x = satelites[i].getPosition().x;
		y = satelites[i].getPosition().y;
		dx = 0;
		dy = 0;
		angle = satelites[i].getRotation();
		dx += dt * 75;
		dy += sin(angle * degtorad) * dt * 50;

		float speeds = sqrt(dx * dx + dy * dy);
		if (speeds > s)
		{
			dx *= s / speeds;
			dy *= s / speeds;
		}

		x += dx;
		y += dy;

		satelites[i].setPosition(x, y);
		satelites[i].setRotation(angle + 3);
		w1->draw(satelites[i]);

		if (x > W)
		{
			satelites.erase(satelites.begin() + i);
		}
		if (x < 0)
		{
			satelites.erase(satelites.begin() + i);
		}

		if (y > H)
		{
			satelites.erase(satelites.begin() + i);
		}
		if (y < 0)
		{
			satelites.erase(satelites.begin() + i);
		}
	}
}

void game::pauseMode(RenderWindow* w1, menu* menus, player* players, bullet* bullets)
{
	w1->draw(*s_pause);
	w1->draw(*s_play);
	w1->draw(*s_exit);

	auto mouse_pos = Mouse::getPosition(*w1);
	auto translated_pos = (*w1).mapPixelToCoords(mouse_pos);

	if (life_count == 0 && !lose && !win)
	{
		w1->draw(*s_lose);
		if (s_lose->getGlobalBounds().contains(translated_pos))
		{
			if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
			{
				lose = true;
				sound.play();
				sleep(milliseconds(150));
			}
		}
	}

	if (s_play->getGlobalBounds().contains(translated_pos))
	{
		if (Mouse::isButtonPressed(sf::Mouse::Left) == true && life_count > 0)
		{
			pause = false;
			sound.play();
		}
		s_play->setColor(Color(255, 255, 255));
	}

	if (!s_play->getGlobalBounds().contains(translated_pos))
	{
		s_play->setColor(Color(255, 255, 255, 85));
	}

	if (!win && life_count > 0 && coin_collect == coin_count && rock_destroy == rock_count)
	{
		w1->draw(*s_win);
		pause = true;
		if (s_win->getGlobalBounds().contains(translated_pos))
		{
			if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
			{
				win = true;
				sound.play();
				std::ofstream f("levels.txt", ios::app);
				f << "OK" << endl;
				f.close();
				sleep(milliseconds(150));
			}
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::C))
	{
		pause = false;
		sound.play();
	}

	if (s_exit->getGlobalBounds().contains(translated_pos))
	{
		if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
		{
			menus->k = 0;
			players->setX(W / 2);
			players->setY(H / 2);
			players->init();
			bullets->init();
			sound_1.play();
			sleep(milliseconds(150));
		}
		s_exit->setColor(Color(255, 255, 255));
	}

	if (!s_exit->getGlobalBounds().contains(translated_pos))
	{
		s_exit->setColor(Color(255, 255, 255, 85));
	}
}

void game::rockMovement(float dt, RenderWindow* w1)
{
	for (int i = 0; i < rocks.size(); i++)
	{
		x = rocks[i].getPosition().x;
		y = rocks[i].getPosition().y;
		dx = 0;
		dy = 0;
		angle = rocks[i].getRotation();
		dx += cos(angle * degtorad) * dt * 150;
		dy += sin(angle * degtorad) * dt * 150;

		float speeds = sqrt(dx * dx + dy * dy);
		if (speeds > speed[i])
		{
			dx *= speed[i] / speeds;
			dy *= speed[i] / speeds;
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
		rocks[i].setPosition(x, y);
		w1->draw(rocks[i]);
	}
	if (boom == 1 || boom == 2)
	{
		location++;
	}
}

void game::drawLife(RenderWindow* w1)
{
	for (int i = 0; i < lifes.size(); i++)
	{
		w1->draw(lifes[i]);
	}
}

void game::update(float dt, RenderWindow* w1, player* players, menu* menus, bullet* bullets, Event event, int b, int c)
{
	getBackround(b, w1);

	if (Keyboard::isKeyPressed(Keyboard::P)) // pause
	{
		if (!pause)
		{
			pause = true;
			sound_1.play();
		}
	}

	if (!pause)
	{
		bullets->bulletAnimate(w1, dt, players, event);
		coinAnimate(dt, w1);
		rockAnimate(dt, w1);
		rockMovement(dt, w1);
		snowflakeAnimate(dt, w1);
		if (b >= 2 && players->isMove)
		{
			difficulty(dt, w1);
		}
		if (life_count > 0)
		{
			if (Keyboard::isKeyPressed)
			{
				players->Movement(dt, w1, c);
			}
			w1->draw(*players->s_p);
		}
		if (boom == 1)
		{
			if (rock != -1)
			{
				s_boom1->setPosition(rocks[rock].getPosition().x - cos(rocks[rock].getRotation() * degtorad) * dt * 150 * location, rocks[rock].getPosition().y - sin(rocks[rock].getRotation() * degtorad) * dt * 150 * location);
				rocks.erase(rocks.begin() + rock);
				rock_destroy += 1;
				string s = to_string(rock_destroy) + " / " + to_string(rock_count);
				tx1->setString(s);
				if (rock_destroy == rock_count)
				{
					tx1->setFillColor(Color::Yellow);
					tx1->setString("DONE!");
				}
			}
			boomAnimate(dt, w1, s_boom1, k, boost, size);
			rock = -1;
		}

		if (boom == 2)
		{
			if (rock != -1)
			{
				s_boom2->setPosition((rocks[rock].getPosition().x - cos(rocks[rock].getRotation() * degtorad) * dt * 150 * location + players->getX()) / 2, (rocks[rock].getPosition().y - sin(rocks[rock].getRotation() * degtorad) * dt * 150 * location + players->getY()) / 2);
				rocks.erase(rocks.begin() + rock);
				rock_destroy += 1;
				string s = to_string(rock_destroy) + " / " + to_string(rock_count);
				tx1->setString(s);
				if (rock_destroy == rock_count)
				{
					tx1->setFillColor(Color::Yellow);
					tx1->setString("DONE!");
				}
			}
			boomAnimate(dt, w1, s_boom2, k, boost, size);
			rock = -1;
		}

		if (boom == 3)
		{
			collectAnimate(dt, w1, *s_collect);
		}

		if (coin_collect == coin_count && rock_destroy == rock_count && life_count > 0)
		{
			if (!win)
			{
				pause = true;
			}
		}
	}
	if (pause)
	{
		pauseMode(w1, menus, players, bullets);
	}

	collision(players, w1, dt, bullets);
}

void game::collision(player* players, RenderWindow* w1, float dt, bullet* bullets)
{
	if (players->isMove == true)
	{
		for (int i = 0; i < rocks.size(); i++)
		{
			if (rocks[i].getGlobalBounds().intersects(players->s_p->getGlobalBounds()))
			{
				if (life_count > 1)
				{
					lifes.erase(lifes.begin());
					life_count -= 1;
					sound_3.play();
					k = 20;
					size = 50;
					boost = 25;
					boom = 1;
					location = 0;
					frame_2 = 0;
					rock = i;
					break;
				}
				if (life_count == 1)
				{
					lifes.erase(lifes.begin());
					sound_4.play();
					k = 64;
					size = 192;
					boost = 25;
					life_count -= 1;
					boom = 2;
					location = 0;
					frame_2 = 0;
					rock = i;
					break;
				}

			}
		}

		for (int i = 0; i < coins.size(); i++)
		{
			if (coins[i].getGlobalBounds().intersects(players->s_p->getGlobalBounds()))
			{
				s_collect->setPosition(coins[i].getPosition());
				frame_2 = 0;
				rock = i;
				boom = 3;
				coins.erase(coins.begin() + i);
				coin_collect += 1;
				tx2->setString(to_string(coin_collect) + " / " + to_string(coin_count));
				sound_2.play();
				if (coin_collect == coin_count)
				{
					tx2->setFillColor(Color::Yellow);
					tx2->setString("DONE!");
				}
			}
		}

		for (int i = 0; i < snowflakes.size(); i++)
		{
			if (snowflakes[i].getGlobalBounds().intersects(players->s_p->getGlobalBounds()))
			{
				s_collect->setPosition(snowflakes[i].getPosition());
				frame_2 = 0;
				boom = 3;
				snowflakes.erase(snowflakes.begin() + i);
				life_count += 1;
				lifes.push_back(sf::Sprite(*t_life));
				for (int i = 0; i < lifes.size(); i++) {
					int pos = W - life_count * 40;
					lifes[i].setPosition(pos + i * 40, 15);
					lifes[i].setScale(0.15, 0.15);
				}
				sound_2.play();
			}
		}

		for (int i = 0; i < bullets->bullets.size(); i++)
		{
			for (int j = 0; j < rocks.size(); j++)
			{
				if (bullets->bullets[i].getGlobalBounds().intersects((rocks[j].getGlobalBounds())))
				{
					sound_3.play();
					k = 20;
					size = 50;
					boost = 25;
					boom = 1;
					location = 0;
					frame_2 = 0;
					rock = j;
				}
			}
		}
	}
}

void game::difficulty(float dt, RenderWindow* w1)
{
	int i = 30;
	int ii = rand() % 31 + 1;
	if (i == ii)
	{
		ii = rand() % 6 + 5;
		if (fogs.size() == 0)
		{
			for (int i = 0; i < ii; i++)
			{
				if (i < ii / 3)
				{
					s_fog->setPosition(rand() % (W - 100) + 100, rand() % (H - 100) + 100);
					s_fog->setRotation(rand() % 360);
					s_fog->setScale(0.6, 0.6);
					fogs.push_back(*s_fog);
				}

				if (i >= ii / 3 && i < 2 * ii / 3)
				{
					s_fog->setTexture(*t_fog1);
					s_fog->setPosition(rand() % (W - 100) + 100, rand() % (H - 100) + 100);
					s_fog->setRotation(rand() % 360);
					s_fog->setScale(0.4, 0.4);
					fogs.push_back(*s_fog);
				}

				if (i >= 2 * ii / 3)
				{
					s_fog->setTexture(*t_fog2);
					s_fog->setPosition(rand() % (W - 100) + 100, rand() % (H - 100) + 100);
					s_fog->setRotation(rand() % 360);
					s_fog->setScale(0.4, 0.4);
					fogs.push_back(*s_fog);
				}
			}
		}
	}

	ii = rand() % 31 + 1;
	if (i == ii)
	{
		if (satelites.size() == 0)
		{
			// Create a vector of c sprites initialised with the texture above
			for (int i = 0; i < 2; i++)
			{
				if (i == 0)
				{
					s_satelite->setTexture(*t_satelite);
					s_satelite->setPosition(rand() % (W - 100) + 100, rand() % (H - 100) + 100);
					s_satelite->setRotation(rand() % 360);
					s_satelite->setScale(0.1, 0.1);
					satelites.push_back(*s_satelite);
				}

				if (i == 1)
				{
					s_satelite->setTexture(*t_satelite1);
					s_satelite->setPosition(rand() % (W - 100) + 100, rand() % (H - 100) + 100);
					s_satelite->setRotation(rand() % 360);
					s_satelite->setScale(0.5, 0.5);
					satelites.push_back(*s_satelite);
				}
			}
		}
	}

	fogAnimate(dt, w1);

	sateliteAnimate(dt, w1);

}

void game::boomAnimate(float dt, RenderWindow* w1, Sprite* s, int kol, int boost, int size)
{
	frame_2 += dt * boost;
	if (frame_2 <= kol)
	{
		s->setScale(1, 1);
		s->setTextureRect(IntRect(int(frame_2) * size, 0, size, size));
		if (boom == 1)
		{
			s->setScale(2, 2);
		}
		w1->draw(*s);
	}

	if (frame_2 > kol && boom == 2)
	{
		pause = true;
	}
}

void game::collectAnimate(float dt, RenderWindow* w1, Sprite s)
{
	frame_2 += dt * 20;
	int kol = 20;
	if (frame_2 <= kol)
	{
		if (frame_2 <= 5.0)
		{
			s.setTextureRect(IntRect(int(frame_2) * 192, 0, 192, 163));
		}
		else if (frame_2 > 5.0 && frame_2 <= 10.0)
		{
			s.setTextureRect(IntRect(int(frame_2 - 5) * 192, 163, 192, 163));
		}
		else if (frame_2 > 10.0 && frame_2 <= 15.0)
		{
			s.setTextureRect(IntRect(int(frame_2 - 10) * 192, 163 * 2, 192, 163));
		}
		else if (frame_2 > 15.0 && frame_2 <= 20.0)
		{
			s.setTextureRect(IntRect(int(frame_2 - 15) * 192, 163 * 3, 192, 163));
		}
		s.setScale(0.5, 0.5);
		w1->draw(s);
	}
}