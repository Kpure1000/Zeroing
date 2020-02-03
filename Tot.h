#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<fstream>
#include<cassert>
using namespace std;

namespace Tot
{
#define CannotResize  (sf::Style::Titlebar |  sf::Style::Close)
////////
#define KeyPressing sf::Event::KeyPressed
#define KeyReleasing sf::Event::KeyReleased
#define KeyEvent(EV) (sf::Keyboard::isKeyPressed(sf::Keyboard::EV))
////////
	enum class DRAWLEVEL
	{
		la, lb, lc //...
	};
	class GameObject;
	////
	class Player;
	////
	class Plat;
	////
}