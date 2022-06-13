#include "Flower.h"
#include <sstream>
#include <string>
#include <iostream>

void Flower::draw()
{

	drawbackground();

	drawsun();


	for (int i = 0; i < 200; i++)
	{
		int x = random(5, 1650);
		int y = random(5, 1050);
		RectangleShape rain;
		rain.setPosition(Vector2f(x, y));
		rain.setSize(Vector2f(2, 10));

		window->draw(rain);
	}

	for (int i = 50; i < 1650; i+=50)
	{
		for (int j = 705; j < 1050; j+=100)
		{
			drawsmallflower(i, j);
		}

	}
	drawflower();

	drawwindmill();


}

int Flower::random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}


void Flower::drawflower()
{
	CircleShape flower;
	RectangleShape stem;
	ConvexShape leaf;
	CircleShape petals;

	//heart
	flower.setOutlineThickness(60.f);
	flower.setOutlineColor(Color(93, 138, 168));
	flower.setRadius(100);
	flower.setFillColor(Color(250, 90, 0));
	flower.setPosition(170, 390);

	//stem
	stem.setFillColor(Color(0, 200, 100));
	stem.setSize(Vector2f(10, 400));
	stem.setPosition(265, 655);

	//leaf
	leaf.setFillColor(Color(0, 200, 0));
	leaf.setPointCount(4);
	leaf.setPoint(0, Vector2f(275, 955));
	leaf.setPoint(1, Vector2f(375, 805));
	leaf.setPoint(2, Vector2f(415, 905));
	leaf.setPoint(3, Vector2f(375, 875));

	//petals
	static int angle = 0;
	petals.setRadius(80);
	petals.setPosition(Vector2f(270, 490));
	petals.setRotation(0);

	window->draw(stem);
	window->draw(leaf);
	for (int i = 0; i < 9; i++)
	{
		if (angle < 0)
		{
			angle = 180;
		}

		petals.rotate(80);
		angle -= 5;

		petals.setFillColor(Color(236, 230, 61));
		window->draw(petals);
	}
	window->draw(flower);
}


void Flower::drawsmallflower(int x, int y)
{
	CircleShape flower;
	RectangleShape stem;
	ConvexShape leaf;
	CircleShape petals;

	//heart
	flower.setOutlineThickness(6.f);
	flower.setOutlineColor(Color(93, 138, 168));
	flower.setRadius(10);
	flower.setFillColor(Color(250, 90, 0));
	flower.setPosition(x, y);

	//stem
	stem.setFillColor(Color(0, 200, 100));
	stem.setSize(Vector2f(10, 40));
	stem.setPosition(x, y);

	//petals
	static int angle = 0;
	petals.setRadius(8);
	petals.setPosition(Vector2f(x+10, y+10));
	petals.setRotation(0);

	window->draw(stem);
	window->draw(leaf);
	for (int i = 0; i < 9; i++)
	{
		if (angle < 0)
		{
			angle = 180;
		}

		petals.rotate(80);
		angle -= 5;

		petals.setFillColor(Color(236, 230, 61));
		window->draw(petals);
	}
	window->draw(flower);

}

void Flower::drawsun()
{
	CircleShape sun;
	sun.setPosition(Vector2f(350, 40));
	sun.setRadius(140);
	sun.setFillColor(Color(245, 210, 41));

	window->draw(sun);
}

void Flower::drawbackground()
{
	RectangleShape ground;
	RectangleShape sky;

	//sky
	sky.setPosition(Vector2f(0, 0));
	sky.setSize(Vector2f(1660, 680));
	sky.setFillColor(Color(0, 100, 160));
	
	
	//ground

	ground.setPosition(Vector2f(0, 680));
	ground.setSize(Vector2f(1660, 680));
	ground.setFillColor(Color(139, 69, 19));

	window->draw(sky);
	window->draw(ground);
}

void Flower::drawwindmill()
{
	CircleShape roof (Triangles, 3);


	//house
	house.setPosition(Vector2f(900, 480));
	house.setSize(Vector2f(300, 500));
	house.setFillColor(Color(245, 245, 220));
	house.setOutlineColor(Color(139, 69, 19));
	house.setOutlineThickness(10);

	//roof
	roof.setPosition(Vector2f(880, 220));
	roof.setRadius(170);
	roof.setFillColor(Color(245, 245, 220));
	roof.setOutlineColor(Color(139, 69, 19));
	roof.setOutlineThickness(10);

	window->draw(house);
	window->draw(roof);

	//blades

	blade1.setPosition(Vector2f(1050, 305));
	blade1.setSize(Vector2f(100, 300));
	blade1.setFillColor(Color(118, 80, 56));
	blade1.setRotation(0);


	blade2.setPosition(blade1.getPosition());
	blade2.setSize(blade1.getSize());
	blade2.setFillColor(Color(118, 80, 56));
	blade2.setRotation(180);


	blade3.setPosition(blade1.getPosition());
	blade3.setSize(Vector2f(100, 300));
	blade3.setFillColor(Color(118, 80, 56));
	blade3.setRotation(90);

	blade4.setPosition(blade1.getPosition());
	blade4.setSize(blade3.getSize());
	blade4.setFillColor(Color(118, 80, 56));
	blade4.setRotation(270);

		if (angle < 0)
		{
			angle = 180;
		}

		blade1.rotate(angle);
		blade2.rotate(angle);
		blade3.rotate(angle);
		blade4.rotate(angle);

		angle -= 5;



	window->draw(blade1);
	window->draw(blade2);
	window->draw(blade3);
	window->draw(blade4);


}


 Flower::Flower(RenderWindow* window)
{
	 this->window = window;
}


