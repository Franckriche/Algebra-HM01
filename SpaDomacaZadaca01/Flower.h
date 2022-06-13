#pragma once
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

class Flower
{
private:
	RenderWindow* window;

	RectangleShape blade1;
	RectangleShape blade2;
	RectangleShape blade3;
	RectangleShape blade4;
	RectangleShape house;

	int angle = 180;


public:
	Flower(RenderWindow* window);

	void draw();
	void drawflower();
	void drawwindmill();
	void drawbackground();
	void drawsmallflower(int x, int y);
	void drawsun();

	int random(int min, int max);
};

