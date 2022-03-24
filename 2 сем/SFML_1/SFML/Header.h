#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

View view;
void getplayercoordinateforview(float x, float y)
{
	view.setCenter(x + 50, y + 100);
}
