// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>

//Make the code easier to type with "using namespace"
using namespace sf;
using namespace std;


int main()
{

	Font font;
	font.loadFromFile("Atop.ttf");
	Text title; 
	title.setString("click 3 points bud");
	Text title2;
	title2.setString("click again to start it up pal");
	Text title3;
	title3.setString("good job chump");
	title.setFillColor(Color::Cyan);
	title2.setFillColor(Color::Cyan);
	title3.setFillColor(Color::Cyan);
	title.setFont(font);
	title2.setFont(font);
	title3.setFont(font);
	title.setCharacterSize(30);
	title2.setCharacterSize(30);
	title3.setCharacterSize(40);


	int chosenPoint = rand() % 3;
	Vector2f bufferPoint;


	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Default);
	
	vector<Vector2f> vertices;
	vector<Vector2f> points;

	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		


		Event event;
		while (window.pollEvent(event))
		{
		    if (event.type == Event::Closed)
		    {
					// Quit the game when the window is closed
					window.close();
		    }
		    if (event.type == sf::Event::MouseButtonPressed)
		    {
			if (event.mouseButton.button == sf::Mouse::Left)
			{
			    std::cout << "the left button was pressed" << std::endl;
			    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
			    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
	
			    if(vertices.size() < 3)
			    {
				vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
			    }
			    else if(points.size() == 0)
			    {
				///fourth click
				///push back to points vector
					points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
			    }
			}
		    }
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		/*
		****************************************
		Update
		****************************************
		*/
	
		if(points.size() > 0)
		{
		    ///generate more point(s)
		    ///select random vertex
		    ///calculate midpoint between random vertex and the last point in the vector
		    ///push back the newly generated coord.
			chosenPoint = rand() % 3;
			bufferPoint.x = (vertices.at(chosenPoint).x + points.back().x) / 2;
			bufferPoint.y = (vertices.at(chosenPoint).y + points.back().y) / 2;
			points.push_back(bufferPoint);
			

		}
	
		/*
		****************************************
		Draw
		****************************************
		*/
		window.clear();
		title.setPosition(Vector2f(100, 50));
		window.draw(title);


		if (vertices.size() > 2)
		{
			title2.setPosition(Vector2f(100, 200));
			window.draw(title2);
		}

		if (points.size() > 0)
		{
			title3.setPosition(Vector2f(500, 100));
			window.draw(title3);
		}

		for(int i = 0; i < vertices.size(); i++)
		{
		    RectangleShape rect(Vector2f(10,10));
		    rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
		    rect.setFillColor(Color::Blue);
		    window.draw(rect);
		}

		for (int i = 2; i < points.size(); i++)
		{
			RectangleShape dot(Vector2f(5, 5));
			dot.setPosition(points.at(i));
			dot.setFillColor(Color::Green);
			window.draw(dot);

		}



		window.display();
	}
}
