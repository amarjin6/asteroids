//include libraries
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include <SFML/System.hpp>
#include "enter.h"
#include "menu.h"
#include "game.h"
#include "player.h"
#include "bullet.h"

using namespace sf;

//getting screen parameters
const int W = VideoMode::getDesktopMode().width;
const int H = VideoMode::getDesktopMode().height;

int main()
{
	int b = 0; //level num
	bool isFullscreen = true; //fullscreen

	Clock clock;
	Time time;
	float dt = 0; //response time	

	RenderWindow w1(VideoMode(W, H), "Asteroids", Style::Fullscreen); //main window

	w1.setFramerateLimit(60);

	//initialize dependencies
	menu* menus = new menu();
	enter* enters = new enter();
	player* players = new player();
	game* games = new game();
	bullet* bullets = new bullet();

	Music music;
	music.openFromFile("music/background.wav");
	music.setVolume(50);
	music.play();
	music.setLoop(true);

	//main program loop
	while (w1.isOpen())
	{
		Event event;
		while (w1.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyPressed:
				switch (event.key.code)
				{
				case Keyboard::Escape:
				{
					if (true == isFullscreen)
					{
						w1.create(VideoMode(W, H), "Asteroids", Style::Default);

						isFullscreen = false;
					}
					else
					{
						w1.create(VideoMode(W, H), "Asteroids", Style::Fullscreen);

						isFullscreen = true;
					}

					break;
				}
				}
				break;

			case Event::Closed:
				w1.close();
				break;
			}
		}

		w1.setKeyRepeatEnabled(false);

		if (enters != NULL) //enter window
		{
			enters->update(&w1, dt);

			if (enters->k >= 1)
			{
				delete enters;
				enters = NULL;
				w1.clear();
			}
		}

		else if (menus->k != 1) //menu window
		{
			if (games->pause)
			{
				delete(games);
				games = new game();
			}

			menus->update(&w1, &music);

			if (menus->k == 1)
			{
				b = menus->b;
			}
		}

		else if (games != NULL && players != NULL) // game window
		{
			games->update(dt, &w1, players, menus, bullets, event, b, menus->c);
		}

		time = clock.restart();
		dt = time.asSeconds();
		w1.display();
	}

	menus->~menu();
	games->~game();
	players->~player();
	bullets->~bullet();

	return 0;
}