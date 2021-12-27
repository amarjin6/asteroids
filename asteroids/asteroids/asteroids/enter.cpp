#include "enter.h"
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"

const int W = VideoMode::getDesktopMode().width;
const int H = VideoMode::getDesktopMode().height;

enter::enter()
{
	t1 = new Texture;
	t1->loadFromFile("images/background/b8.jpg");
	t1->setSmooth(true);

	t2 = new Texture;
	t2->loadFromFile("images/background/p1.png");
	t2->setSmooth(true);

	t3 = new Texture;
	t3->loadFromFile("images/background/start.png");
	t3->setSmooth(true);

	s1 = new Sprite;
	s1->setTexture(*t1);
	s1->setTextureRect(sf::IntRect(0, 0, W, H));

	s2 = new Sprite;
	s2->setTexture(*t2);
	s2->setColor(Color(255, 255, 255, 999));
	s2->setTextureRect(sf::IntRect(-W / 3.8, -H / 30, W, H));

	s3 = new Sprite;
	s3->setTexture(*t3);
	s3->setTextureRect({ 0,0,515,45 });
	s3->setPosition(W / 2.6, H / 1.1);

	text = new Text;
	font = new Font;
	font->loadFromFile("fonts/Affirmative.ttf");
	text->setFont(*font);
	text->setString("ASTEROIDS");
	text->setCharacterSize(100);
	text->setFillColor(Color::Cyan);
	text->setStyle(Text::Bold);
	text->setPosition(W / 2.9, H / 2.6);

	buffer.loadFromFile("music/click_3.wav");
	sound.setBuffer(buffer);
	kol = 2;
	frame = 0;
}

enter::~enter()
{
	delete t1;  //desturctor
	delete t2;
	delete t3;
	t1 = NULL;  //garbage collect
	t2 = NULL;
	t3 = NULL;

	delete s1;
	delete s2;
	delete s3;
	s1 = NULL;
	s2 = NULL;
	s3 = NULL;

	delete text;
	delete font;
	text = NULL;
	font = NULL;
}

void enter::update(RenderWindow* w1, float dt)
{
	draw(w1);
	press(w1, dt);
}

void enter::press(RenderWindow* w1, float dt)
{
	frame += dt * 1.5;

	if (frame > kol)
	{
		frame -= kol;
	}

	s3->setTextureRect(IntRect(int(frame) * 515, 0, 515, 45));
	w1->draw(*s3);
}

void enter::draw(RenderWindow* w1)
{
	w1->draw(*s1);
	w1->draw(*s2);
	w1->draw(*text);

	if (Keyboard::isKeyPressed(Keyboard::Enter) || Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::P)) // next window
	{
		k++;
		sound.play();
		sleep(milliseconds(150));
	}
}


