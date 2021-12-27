#include "menu.h"
#include "Main.h"
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include <thread>
#include <iostream>
using namespace sf;

const int W = VideoMode::getDesktopMode().width;
const int H = VideoMode::getDesktopMode().height;

menu::menu()
{
	t = new Texture;
	t->loadFromFile("images/background/b13.jpg");
	t->setSmooth(true);

	lock = new Texture;
	lock->loadFromFile("images/background/lock.png");
	lock->setSmooth(true);

	t_ea = new Texture;
	t_ea->loadFromFile("images/background/earth.png");
	t_ea->setSmooth(true);

	t_ma = new Texture;
	t_ma->loadFromFile("images/background/mars.png");
	t_ma->setSmooth(true);

	t_mo = new Texture;
	t_mo->loadFromFile("images/background/moon.png");
	t_mo->setSmooth(true);

	t_ju = new Texture;
	t_ju->loadFromFile("images/background/jupiter.png");
	t_ju->setSmooth(true);

	t_ur = new Texture;
	t_ur->loadFromFile("images/background/uranus.png");
	t_ur->setSmooth(true);

	t_a = new Texture;
	t_a->loadFromFile("images/background/author.png");
	t_a->setSmooth(true);

	t_au = new Texture;
	t_au->loadFromFile("images/background/author_text.png");
	t_au->setSmooth(true);

	t_r = new Texture;
	t_r->loadFromFile("images/background/rules.png");
	t_r->setSmooth(true);

	t_ru = new Texture;
	t_ru->loadFromFile("images/background/rules_text.png");
	t_ru->setSmooth(true);

	t_p = new Texture;
	t_p->loadFromFile("images/background/play.png");
	t_p->setSmooth(true);

	t_s = new Texture;
	t_s->loadFromFile("images/background/settings.png");
	t_s->setSmooth(true);

	t_se = new Texture;
	t_se->loadFromFile("images/background/settings_text.png");
	t_se->setSmooth(true);

	t_c = new Texture;
	t_c->loadFromFile("images/background/character.png");
	t_c->setSmooth(true);

	t_ch = new Texture;
	t_ch->loadFromFile("images/background/character_text.png");
	t_ch->setSmooth(true);

	tl = new Texture;
	tl->loadFromFile("images/background/arrow_l.png");
	tl->setSmooth(true);

	tr = new Texture;
	tr->loadFromFile("images/background/arrow_r.png");
	tr->setSmooth(true);

	t_planet = new Texture;
	t_planet->loadFromFile("images/background/p1.png");
	t_planet->setSmooth(true);

	t_lose = new Texture;
	t_lose->loadFromFile("images/background/lose.png");
	t_lose->setSmooth(true);

	t_win = new Texture;
	t_win->loadFromFile("images/background/win.png");
	t_win->setSmooth(true);

	t_down = new Texture;
	t_down->loadFromFile("images/background/volume_down.png");
	t_down->setSmooth(true);

	t_up = new Texture;
	t_up->loadFromFile("images/background/volume_up.png");
	t_up->setSmooth(true);

	t_bar = new Texture;
	t_bar->loadFromFile("images/background/bar.png");
	t_bar->setSmooth(true);

	t_contact = new Texture;
	t_contact->loadFromFile("images/background/contact.png");
	t_contact->setSmooth(true);

	t_mike = new Texture;
	t_mike->loadFromFile("images/background/mike.png");
	t_mike->setSmooth(true);

	t_ship1 = new Texture;
	t_ship1->loadFromFile("images/game/spaceship/ship.png");
	t_ship1->setSmooth(true);

	t_ship2 = new Texture;
	t_ship2->loadFromFile("images/game/spaceship/pointer.png");
	t_ship2->setSmooth(true);

	t_ship3 = new Texture;
	t_ship3->loadFromFile("images/game/spaceship/ship_1.png");
	t_ship3->setSmooth(true);

	t_ship4 = new Texture;
	t_ship4->loadFromFile("images/game/spaceship/ship_2.png");
	t_ship4->setSmooth(true);

	s = new Sprite;
	s->setTexture(*t);
	s->setTextureRect(sf::IntRect(0, 0, W, H));

	s_l = new Sprite;
	s_l->setTexture(*lock);
	s_l->setColor(Color(255, 255, 255));
	s_l->setPosition(W / 2.7, H / 10);

	s_ea = new Sprite;
	s_ea->setTexture(*t_ea);
	s_ea->setColor(Color(255, 255, 255, 200));
	s_ea->setPosition(W / 3, H / 5);

	s_ma = new Sprite;
	s_ma->setTexture(*t_ma);
	s_ma->setColor(Color(255, 255, 255, 90));
	s_ma->setPosition(W / 3, H / 5);

	s_mo = new Sprite;
	s_mo->setTexture(*t_mo);
	s_mo->setColor(Color(255, 255, 255, 90));
	s_mo->setPosition(W / 3, H / 5);

	s_ju = new Sprite;
	s_ju->setTexture(*t_ju);
	s_ju->setColor(Color(255, 255, 255, 90));
	s_ju->setPosition(W / 3, H / 5);

	s_ur = new Sprite;
	s_ur->setTexture(*t_ur);
	s_ur->setColor(Color(255, 255, 255, 90));
	s_ur->setPosition(W / 3, H / 5);

	s_a = new Sprite;
	s_a->setTexture(*t_a);
	s_a->setScale(.35, .35);
	s_a->setColor(Color(255, 255, 255, 85));
	s_a->setPosition(W / 1.53, H / 1.3);

	s_au = new Sprite;
	s_au->setTexture(*t_au);
	s_au->setColor(Color(255, 255, 255, 90));
	s_au->setPosition(W / 3, H / 5);

	s_r = new Sprite;
	s_r->setTexture(*t_r);
	s_r->setScale(.35, .35);
	s_r->setColor(Color(255, 255, 255, 85));
	s_r->setPosition(W / 1.8, H / 1.3);

	s_ru = new Sprite;
	s_ru->setTexture(*t_ru);
	s_ru->setColor(Color(255, 255, 255, 90));
	s_ru->setPosition(W / 3, H / 5);

	s_s = new Sprite;
	s_s->setTexture(*t_s);
	s_s->setScale(.35, .35);
	s_s->setColor(Color(255, 255, 255, 85));
	s_s->setPosition(W / 2.87, H / 1.3);

	s_se = new Sprite;
	s_se->setTexture(*t_se);
	s_se->setColor(Color(255, 255, 255, 90));
	s_se->setPosition(W / 3, H / 5);

	s_c = new Sprite;
	s_c->setTexture(*t_c);
	s_c->setScale(.35, .35);
	s_c->setColor(Color(255, 255, 255, 85));
	s_c->setPosition(W / 4, H / 1.3);

	s_ch = new Sprite;
	s_ch->setTexture(*t_ch);
	s_ch->setColor(Color(255, 255, 255, 90));
	s_ch->setPosition(W / 3, H / 5);

	s_p = new Sprite;
	s_p->setTexture(*t_p);
	s_p->setScale(.9, .9);
	s_p->setColor(Color(255, 255, 255, 85));
	s_p->setPosition(W / 2.28, H / 1.4);

	s_planet = new Sprite;
	s_planet->setTexture(*t_planet);
	s_planet->setScale(.9, .9);
	s_planet->setPosition(W / 3.45, 0);

	sl = new Sprite;
	sl->setTexture(*tl);
	sl->setScale(.2, .2);
	sl->setColor(Color(255, 255, 255, 85));
	sl->setPosition(W / 4.5, H / 3);

	sr = new Sprite;
	sr->setTexture(*tr);
	sr->setScale(.2, .2);
	sr->setColor(Color(255, 255, 255, 85));
	sr->setPosition(W / 1.4, H / 3);

	s_lose = new Sprite;
	s_lose->setTexture(*t_lose);
	s_lose->setScale(.35, .35);
	s_lose->setColor(Color(255, 255, 255, 200));
	s_lose->setPosition(W / 1.9, 35);

	s_win = new Sprite;
	s_win->setTexture(*t_win);
	s_win->setScale(.35, .35);
	s_win->setColor(Color(255, 255, 255, 200));
	s_win->setPosition(W / 1.9, 35);

	s_down = new Sprite;
	s_down->setTexture(*t_down);
	s_down->setScale(.15, .15);
	s_down->setColor(Color(255, 255, 255, 85));
	s_down->setPosition(W / 2.86, H / 3.5);

	s_up = new Sprite;
	s_up->setTexture(*t_up);
	s_up->setScale(.15, .15);
	s_up->setColor(Color(255, 255, 255, 85));
	s_up->setPosition(W / 1.65, H / 3.5);

	s_bar = new Sprite;
	s_bar->setTexture(*t_bar);
	s_bar->setTextureRect(IntRect(0, 0, 0, 54));
	s_bar->setScale(.5, .5);
	s_bar->setColor(Color(255, 255, 255, 85));
	s_bar->setPosition(W / 2.53, H / 3.25);

	s_contact = new Sprite;
	s_contact->setTexture(*t_contact);
	s_contact->setScale(.30, .30);
	s_contact->setColor(Color(255, 255, 255, 85));
	s_contact->setPosition(W / 2.22, H / 2.7);

	s_mike = new Sprite;
	s_mike->setTexture(*t_mike);
	s_mike->setScale(.42, .42);
	s_mike->setColor(Color(255, 255, 255, 85));
	s_mike->setPosition(W / 1.9, H / 3.6);

	s_ship1 = new Sprite;
	s_ship1->setTexture(*t_ship1);
	s_ship1->setColor(Color(255, 255, 255, 85));
	s_ship1->setTextureRect(IntRect(76, 0, 80, 78));
	s_ship1->setPosition(W / 2.8, H / 3.5);
	s_ship1->setScale(0.8, 0.8);

	s_ship2 = new Sprite;
	s_ship2->setTexture(*t_ship2);
	s_ship2->setScale(.24, .24);
	s_ship2->setColor(Color(255, 255, 255, 85));
	s_ship2->setPosition(W / 2.3, H / 3.5);

	s_ship3 = new Sprite;
	s_ship3->setTexture(*t_ship3);
	s_ship3->setScale(.10, .10);
	s_ship3->setTextureRect(IntRect(0, 0, 531, 854));
	s_ship3->setColor(Color(255, 255, 255, 85));
	s_ship3->setPosition(W / 2.78, H / 2.5);

	s_ship4 = new Sprite;
	s_ship4->setTexture(*t_ship4);
	s_ship4->setScale(.10, .10);
	s_ship4->setTextureRect(IntRect(0, 0, 713, 935));
	s_ship4->setColor(Color(255, 255, 255, 85));
	s_ship4->setPosition(W / 2.33, H / 2.5);

	FILE* levels;
	levels = fopen("levels.txt", "a+");
	char* str = new char[1024];
	i = 0;
	while (!feof(levels))
	{
		fgets(str, 1024, levels);
		i++;
	}
	fclose(levels);
	delete str;

	k = 0;
	p = 0;
	a = 0;
	b = 1;
	b1 = 0;
	b2 = 0;
	b3 = 0;
	b4 = 0;
	b5 = 0;
	m = 6;
	c = 1;

	if (!buffer.loadFromFile("music/click_1.wav"))
	{
		std::cout << "error";
	}
	sound.setBuffer(buffer);

	if (!buffer_1.loadFromFile("music/click_2.wav"))
	{
		std::cout << "error";
	}
	sound_1.setBuffer(buffer_1);

	if (!buffer_2.loadFromFile("music/click_3.wav"))
	{
		std::cout << "error";
	}
	sound_2.setBuffer(buffer_2);

	if (!buffer_3.loadFromFile("music/error.wav"))
	{
		std::cout << "error";
	}
	sound_3.setBuffer(buffer_3);
}

menu::~menu()
{
	delete t_au; //destructor
	delete t_ru;
	delete t_se;
	delete t_ch;
	delete t_ea;
	delete t_ma;
	delete t_mo;
	delete t_ju;
	delete t_ur;
	delete lock;
	delete t;
	delete t_a;
	delete t_r;
	delete t_p;
	delete t_s;
	delete t_c;
	delete tl;
	delete tr;
	delete t_planet;
	delete t_down;
	delete t_up;
	delete t_bar;
	delete t_contact;
	delete t_mike;
	delete t_ship1;
	delete t_ship2;
	delete t_ship3;
	delete t_ship4;

	t_au = NULL; //garbage collect
	t_ru = NULL;
	t_se = NULL;
	t_ch = NULL;
	t_ea = NULL;
	t_ma = NULL;
	t_mo = NULL;
	t_ju = NULL;
	t_ur = NULL;
	lock = NULL;
	t = NULL;
	t_a = NULL;
	t_r = NULL;
	t_p = NULL;
	t_s = NULL;
	t_c = NULL;
	tl = NULL;
	tr = NULL;
	t_planet = NULL;
	t_down = NULL;
	t_up = NULL;
	t_bar = NULL;
	t_contact = NULL;
	t_mike = NULL;
	t_ship1 = NULL;
	t_ship2 = NULL;
	t_ship3 = NULL;
	t_ship4 = NULL;

	delete s_au;
	delete s_ru;
	delete s_se;
	delete s_ch;
	delete s_ea;
	delete s_ma;
	delete s_mo;
	delete s_ju;
	delete s_ur;
	delete s_l;
	delete s;
	delete s_a;
	delete s_r;
	delete s_p;
	delete s_s;
	delete s_c;
	delete sl;
	delete sr;
	delete s_planet;
	delete s_down;
	delete s_up;
	delete s_bar;
	delete s_contact;
	delete s_mike;
	delete s_ship1;
	delete s_ship2;
	delete s_ship3;
	delete s_ship4;

	s_au = NULL;
	s_ru = NULL;
	s_se = NULL;
	s_ch = NULL;
	s_ea = NULL;
	s_ma = NULL;
	s_mo = NULL;
	s_ju = NULL;
	s_ur = NULL;
	s_l = NULL;
	s = NULL;
	s_a = NULL;
	s_r = NULL;
	s_p = NULL;
	s_s = NULL;
	s_c = NULL;
	sl = NULL;
	sr = NULL;
	s_planet = NULL;
	s_down = NULL;
	s_up = NULL;
	s_bar = NULL;
	s_contact = NULL;
	s_mike = NULL;
	s_ship1 = NULL;
	s_ship2 = NULL;
	s_ship3 = NULL;
	s_ship4 = NULL;
}

void menu::update(RenderWindow* w1, Music* music)
{
	draw(w1);
	showInfo(w1);
	clickOther(w1, music);

	FILE* levels;
	levels = fopen("levels.txt", "a+");
	char* str = new char[1024];
	i = 0;
	while (!feof(levels))
	{
		fgets(str, 1024, levels);
		i++;
	}
	fclose(levels);
	delete str;
}

void menu::clickRight(RenderWindow* w1)
{
	sound.play();
	p += 1;
	drawPlanets(w1);
}

void menu::clickLeft(RenderWindow* w1)
{
	sound.play();
	p -= 1;
	drawPlanets(w1);
}

void menu::draw(RenderWindow* w1)
{
	if (this->k < 1)
	{
		w1->draw(*s);
		w1->draw(*sl);
		w1->draw(*sr);
		w1->draw(*s_a);
		w1->draw(*s_p);
		w1->draw(*s_r);
		w1->draw(*s_s);
		w1->draw(*s_c);
		w1->draw(*s_planet);

		if (Keyboard::isKeyPressed(Keyboard::Right)) // right
		{
			clickRight(w1);
			sleep(milliseconds(150));
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) // left
		{
			clickLeft(w1);
			sleep(milliseconds(150));
		}

		if (Keyboard::isKeyPressed(Keyboard::Enter)) // play game
		{
			if (b <= i)
			{
				sound_2.play();
				sleep(milliseconds(150));
				k = 1;
			}
			if (b > i)
			{
				sound_3.play();
				sleep(milliseconds(150));
			}
		}
	}
}

void menu::clickOther(RenderWindow* w1, Music* music)
{
	auto mouse_pos = Mouse::getPosition(*w1);
	auto translated_pos = (*w1).mapPixelToCoords(mouse_pos);

	if (k < 1)
	{
		if (sr->getGlobalBounds().contains(translated_pos))
		{
			if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
			{
				clickRight(w1);
				sleep(milliseconds(100));
			}
			sr->setColor(Color(255, 255, 255));
		}

		if (sl->getGlobalBounds().contains(translated_pos))
		{
			if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
			{
				clickLeft(w1);
				sleep(milliseconds(100));
			}
			sl->setColor(Color(255, 255, 255));
		}

		if (!sr->getGlobalBounds().contains(translated_pos))
		{
			sr->setColor(Color(255, 255, 255, 85));
		}

		if (!sl->getGlobalBounds().contains(translated_pos))
		{
			sl->setColor(Color(255, 255, 255, 85));
		}

		if (s_p->getGlobalBounds().contains(translated_pos))
		{
			s_p->setColor(Color(255, 255, 255));
			if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
			{
				if (b <= i)
				{
					sound_2.play();
					sleep(milliseconds(150));
					k = 1;
				}
				if (b > i)
				{
					sound_3.play();
					sleep(milliseconds(150));
				}
			}
		}

		if (!s_p->getGlobalBounds().contains(translated_pos))
		{
			s_p->setColor(Color(255, 255, 255, 85));
		}

		if (s_a->getGlobalBounds().contains(translated_pos))
		{
			s_a->setColor(Color(255, 255, 255));
			if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
			{
				a = 1;
				sound_1.play();
				sleep(milliseconds(150));
			}
		}
		if (!s_a->getGlobalBounds().contains(translated_pos))
		{
			s_a->setColor(Color(255, 255, 255, 85));
		}

		if (s_r->getGlobalBounds().contains(translated_pos))
		{
			s_r->setColor(Color(255, 255, 255));
			if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
			{
				a = 2;
				sound_1.play();
				sleep(milliseconds(150));
			}
		}
		if (!s_r->getGlobalBounds().contains(translated_pos))
		{
			s_r->setColor(Color(255, 255, 255, 85));
		}

		if (s_s->getGlobalBounds().contains(translated_pos))
		{
			s_s->setColor(Color(255, 255, 255));
			if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
			{
				a = 3;
				sound_1.play();
				sleep(milliseconds(150));
			}
		}
		if (!s_s->getGlobalBounds().contains(translated_pos))
		{
			s_s->setColor(Color(255, 255, 255, 85));
		}

		if (s_c->getGlobalBounds().contains(translated_pos))
		{
			s_c->setColor(Color(255, 255, 255));
			if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
			{
				a = 4;
				sound_1.play();
				sleep(milliseconds(150));
			}
		}
		if (!s_c->getGlobalBounds().contains(translated_pos))
		{
			s_c->setColor(Color(255, 255, 255, 85));
		}

		showMsg(w1, music);
	}
}

void menu::showMsg(RenderWindow* w1, Music* music)
{
	auto mouse_pos = Mouse::getPosition(*w1);
	auto translated_pos = (*w1).mapPixelToCoords(mouse_pos);
	if (k < 1)
	{
		if (a == 1)
		{
			w1->draw(*s_au);
			if (s_au->getGlobalBounds().contains(translated_pos))
			{
				s_au->setColor(Color(255, 255, 255));
				if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					sound_1.play();
					a = 0;
				}
			}
			if (!s_au->getGlobalBounds().contains(translated_pos))
			{
				s_au->setColor(Color(255, 255, 255, 90));
			}
		}

		else if (a == 2)
		{
			w1->draw(*s_ru);
			if (s_ru->getGlobalBounds().contains(translated_pos))
			{
				s_ru->setColor(Color(255, 255, 255));
				if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					sound_1.play();
					a = 0;
				}
			}
			if (!s_ru->getGlobalBounds().contains(translated_pos))
			{
				s_ru->setColor(Color(255, 255, 255, 90));
			}
		}

		else if (a == 3)
		{
			w1->draw(*s_se);
			w1->draw(*s_up);
			w1->draw(*s_down);
			w1->draw(*s_bar);
			w1->draw(*s_contact);
			if (s_se->getGlobalBounds().contains(translated_pos) && !s_down->getGlobalBounds().contains(translated_pos) && !s_up->getGlobalBounds().contains(translated_pos))
			{
				s_se->setColor(Color(255, 255, 255));
				s_contact->setColor(Color(255, 255, 255));
				s_bar->setColor(Color(255, 255, 255, 255));
				if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					sound_1.play();
					a = 0;
				}
			}
			if (!s_se->getGlobalBounds().contains(translated_pos))
			{
				s_se->setColor(Color(255, 255, 255, 90));
				s_contact->setColor(Color(255, 255, 255, 90));
				s_bar->setColor(Color(255, 255, 255, 90));
			}

			if (s_down->getGlobalBounds().contains(translated_pos))
			{
				s_down->setColor(Color(255, 255, 255));
				if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					sound_1.play();
					if (m >= 1)
					{
						m--;
					}
					sleep(milliseconds(150));
				}
			}
			if (!s_down->getGlobalBounds().contains(translated_pos))
			{
				s_down->setColor(Color(255, 255, 255, 90));
			}

			if (s_up->getGlobalBounds().contains(translated_pos))
			{
				s_up->setColor(Color(255, 255, 255));
				if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					sound_1.play();
					if (m < 12)
					{
						m++;
					}
					sleep(milliseconds(150));
				}
			}
			if (!s_up->getGlobalBounds().contains(translated_pos))
			{
				s_up->setColor(Color(255, 255, 255, 90));
			}

			s_bar->setTextureRect(IntRect(0, 0, m * 64.5, 54));
			music->setVolume(m * 8.3);
		}

		else if (a == 4)
		{
			w1->draw(*s_ch);
			w1->draw(*s_mike);
			w1->draw(*s_ship1);
			w1->draw(*s_ship2);
			w1->draw(*s_ship3);
			w1->draw(*s_ship4);
			if (s_ch->getGlobalBounds().contains(translated_pos) && !s_ship1->getGlobalBounds().contains(translated_pos) && !s_ship2->getGlobalBounds().contains(translated_pos) && !s_ship3->getGlobalBounds().contains(translated_pos) && !s_ship4->getGlobalBounds().contains(translated_pos))
			{
				s_ch->setColor(Color(255, 255, 255));
				s_mike->setColor(Color(255, 255, 255));
				if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					sound_1.play();
					a = 0;
				}
			}
			if (!s_ch->getGlobalBounds().contains(translated_pos))
			{
				s_ch->setColor(Color(255, 255, 255, 90));
				s_mike->setColor(Color(255, 255, 255, 90));
			}

			if (s_ship1->getGlobalBounds().contains(translated_pos))
			{
				s_ship1->setColor(Color(255, 255, 255));
				if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					sound_1.play();
					c = 1;
				}
			}
			if (!s_ship1->getGlobalBounds().contains(translated_pos))
			{
				s_ship1->setColor(Color(255, 255, 255, 90));
			}

			if (s_ship2->getGlobalBounds().contains(translated_pos))
			{
				s_ship2->setColor(Color(255, 255, 255));
				if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					sound_1.play();
					c = 2;
				}
			}
			if (!s_ship2->getGlobalBounds().contains(translated_pos))
			{
				s_ship2->setColor(Color(255, 255, 255, 90));
			}

			if (s_ship3->getGlobalBounds().contains(translated_pos))
			{
				s_ship3->setColor(Color(255, 255, 255));
				if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					sound_1.play();
					c = 3;
				}
			}
			if (!s_ship3->getGlobalBounds().contains(translated_pos))
			{
				s_ship3->setColor(Color(255, 255, 255, 90));
			}

			if (s_ship4->getGlobalBounds().contains(translated_pos))
			{
				s_ship4->setColor(Color(255, 255, 255));
				if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					sound_1.play();
					c = 4;
				}
			}
			if (!s_ship4->getGlobalBounds().contains(translated_pos))
			{
				s_ship4->setColor(Color(255, 255, 255, 90));
			}

			if (c == 1)
			{
				s_ship1->setColor(Color(255, 255, 255, 255));
			}

			else if (c == 2)
			{
				s_ship2->setColor(Color(255, 255, 255, 255));
			}

			else if (c == 3)
			{
				s_ship3->setColor(Color(255, 255, 255, 255));
			}

			else if (c == 4)
			{
				s_ship4->setColor(Color(255, 255, 255, 255));
			}
		}
	}
}

void menu::showInfo(RenderWindow* w1)
{
	auto mouse_pos = Mouse::getPosition(*w1);
	auto translated_pos = (*w1).mapPixelToCoords(mouse_pos);
	if (k < 1)
	{
		if (i > 1)
		{
			if (b < i)
			{
				w1->draw(*s_win);
			}

			if (b == i)
			{
				w1->draw(*s_lose);
			}
		}

		if (b == 1 && b1 != 1)
		{
			w1->draw(*s_ea);
			if (s_ea->getGlobalBounds().contains(translated_pos))
			{
				s_ea->setColor(Color(255, 255, 255));
				if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					b1 = 1;
					sound_1.play();
				}
			}
			if (!s_ea->getGlobalBounds().contains(translated_pos))
			{
				s_ea->setColor(Color(255, 255, 255, 90));
			}
		}

		else if (b == 2 && b2 != 1 && b <= i)
		{
			w1->draw(*s_ma);
			if (s_ma->getGlobalBounds().contains(translated_pos))
			{
				s_ma->setColor(Color(255, 255, 255));
				if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					b2 = 1;
					sound_1.play();
				}
			}
			if (!s_ma->getGlobalBounds().contains(translated_pos))
			{
				s_ma->setColor(Color(255, 255, 255, 90));
			}
		}

		else if (b == 3 && b3 != 1 && b <= i)
		{
			w1->draw(*s_mo);
			if (s_mo->getGlobalBounds().contains(translated_pos))
			{
				s_mo->setColor(Color(255, 255, 255));
				if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					b3 = 1;
					sound_1.play();
				}
			}
			if (!s_mo->getGlobalBounds().contains(translated_pos))
			{
				s_mo->setColor(Color(255, 255, 255, 90));
			}
		}

		else if (b == 4 && b4 != 1 && b <= i)
		{
			w1->draw(*s_ju);
			if (s_ju->getGlobalBounds().contains(translated_pos))
			{
				s_ju->setColor(Color(255, 255, 255));
				if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					b4 = 1;
					sound_1.play();
				}
			}
			if (!s_ju->getGlobalBounds().contains(translated_pos))
			{
				s_ju->setColor(Color(255, 255, 255, 90));
			}
		}

		else if (b == 5 && b5 != 1 && b <= i)
		{
			w1->draw(*s_ur);
			if (s_ur->getGlobalBounds().contains(translated_pos))
			{
				s_ur->setColor(Color(255, 255, 255));
				if (Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					b5 = 1;
					sound_1.play();
				}
			}
			if (!s_ur->getGlobalBounds().contains(translated_pos))
			{
				s_ur->setColor(Color(255, 255, 255, 90));
			}
		}

		if (b > i)
		{
			w1->draw(*s_l);
		}
	}
}

void menu::drawPlanets(RenderWindow* w1)
{
	if (k < 1)
	{
		if (p >= 0)
		{
			p = abs(p % 14);
			if (p == 0)
			{
				t_planet->loadFromFile("images/background/p1.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(.9, .9);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 1;
			}
			else if (p == 1)
			{
				t_planet->loadFromFile("images/background/p2.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(.9, .9);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 2;
			}
			else if (p == 2)
			{
				t_planet->loadFromFile("images/background/p3.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(.9, .9);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 3;
			}
			else if (p == 3)
			{
				t_planet->loadFromFile("images/background/p4.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(.9, .9);
				s_planet->setPosition(W / 3.25, 25);

				w1->draw(*s_planet);
				b = 4;
			}
			else if (p == 4)
			{
				t_planet->loadFromFile("images/background/p5.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(.9, .9);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 5;
			}
			else if (p == 5)
			{
				t_planet->loadFromFile("images/background/p6.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(1, 1);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 6;

			}
			else if (p == 6)
			{
				t_planet->loadFromFile("images/background/p7.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(0.9, 0.9);
				s_planet->setPosition(W / 3.25, 25);

				w1->draw(*s_planet);
				b = 7;
			}
			else if (p == 7)
			{
				t_planet->loadFromFile("images/background/p8.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(1, 1);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 8;
			}
			else if (p == 8)
			{
				t_planet->loadFromFile("images/background/p9.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(0.9, 0.9);
				s_planet->setPosition(W / 3.25, 25);

				w1->draw(*s_planet);
				b = 9;
			}
			else if (p == 9)
			{
				t_planet->loadFromFile("images/background/p10.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(0.9, 0.9);
				s_planet->setPosition(W / 3.25, 25);

				w1->draw(*s_planet);
				b = 10;
			}
			else if (p == 10)
			{
				t_planet->loadFromFile("images/background/p11.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(1, 1);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 11;
			}
			else if (p == 11)
			{
				t_planet->loadFromFile("images/background/p12.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(1, 1);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 12;
			}
			else if (p == 12)
			{
				t_planet->loadFromFile("images/background/p13.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(1, 1);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 13;
			}
			else if (p == 13)
			{
				t_planet->loadFromFile("images/background/p14.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(1, 1);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 14;
			}
		}
		if (p < 0)
		{
			p = p % 14;
			if (p == 0)
			{
				t_planet->loadFromFile("images/background/p1.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(.9, .9);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 1;
			}
			else if (p == -1)
			{
				t_planet->loadFromFile("images/background/p14.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(1, 1);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 14;
			}
			else if (p == -2)
			{
				t_planet->loadFromFile("images/background/p13.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(1, 1);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 13;
			}
			else if (p == -3)
			{
				t_planet->loadFromFile("images/background/p12.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(1, 1);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 12;
			}
			else if (p == -4)
			{
				t_planet->loadFromFile("images/background/p11.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(1, 1);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 11;
			}
			else if (p == -5)
			{
				t_planet->loadFromFile("images/background/p10.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(0.9, 0.9);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 10;
			}
			else if (p == -6)
			{
				t_planet->loadFromFile("images/background/p9.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(0.9, 0.9);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 9;
			}
			else if (p == -7)
			{
				t_planet->loadFromFile("images/background/p8.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(1, 1);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 8;
			}
			else if (p == -8)
			{
				t_planet->loadFromFile("images/background/p7.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(0.9, 0.9);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 7;
			}
			else if (p == -9)
			{
				t_planet->loadFromFile("images/background/p6.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(1, 1);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 6;
			}
			else if (p == -10)
			{
				t_planet->loadFromFile("images/background/p5.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(.9, .9);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 5;
			}
			else if (p == -11)
			{
				t_planet->loadFromFile("images/background/p4.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(.9, .9);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 4;
			}
			else if (p == -12)
			{
				t_planet->loadFromFile("images/background/p3.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(.9, .9);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 3;
			}
			else if (p == -13)
			{
				t_planet->loadFromFile("images/background/p2.png");
				t_planet->setSmooth(true);

				s_planet->setTexture(*t_planet);
				s_planet->setScale(.9, .9);
				s_planet->setPosition(W / 3.45, 0);

				w1->draw(*s_planet);
				b = 2;
			}
		}
	}
}
