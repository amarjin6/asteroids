#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include <thread>
using namespace sf;
class menu
{
public:
	menu();
	~menu();
	int k, b, c;
	void update(RenderWindow* w1, Music* music); // update window

private:
	Texture* t, * t_a, * t_r, * t_p, * t_s, * t_c, * tl, * tr, * t_au, * t_ru, * t_se, * t_ch, * t_ea, * t_ma, * t_mo, * t_ju, * t_ur, * lock, * t_planet, * t_lose, * t_win, * t_down, * t_up, * t_bar, * t_contact, * t_mike, * t_ship1, * t_ship2, * t_ship3, * t_ship4;
	Sprite* s, * s_a, * s_r, * s_p, * s_s, * s_c, * sl, * sr, * s_au, * s_ru, * s_se, * s_ch, * s_ea, * s_ma, * s_mo, * s_ju, * s_ur, * s_l, * s_planet, * s_lose, * s_win, * s_down, * s_up, * s_bar, * s_contact, * s_mike, * s_ship1, * s_ship2, * s_ship3, * s_ship4;
	int p, a, b1, b2, b3, b4, b5, i, m;
	SoundBuffer buffer, buffer_1, buffer_2, buffer_3;
	Sound sound, sound_1, sound_2, sound_3;
	void showMsg(RenderWindow* w1, Music* music); // show buttons msg
	void drawPlanets(RenderWindow* w1); // draw planets
	void draw(RenderWindow* w1); // draw main UI
	void clickOther(RenderWindow* w1, Music* music); // click buttons in UI
	void showInfo(RenderWindow* w1); // show planet info
	void clickRight(RenderWindow* w1); //right buton
	void clickLeft(RenderWindow* w1); // left button
};