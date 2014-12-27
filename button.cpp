#include <SFML/Graphics.hpp>
#include "main.hpp"
#include "menu.hpp"
#include "button.hpp"

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace sf;
using namespace std;

Button::Button (Action action): action_(action)
{
	switch (action)
	{
		case Play :	
			zone_ = sf::FloatRect(375, 285, 500, 370);
			break;
		
		case Exit : 	
			zone_ = sf::FloatRect(375, 430, 510, 510);
			break;
				
		case Resume :
			zone_ = sf::FloatRect(340, 310, 540, 370);
			break;
			
		case ExitThroughGameOver :
			zone_ = sf::FloatRect(470,480,750,520);
			break;
		
		case NewGame :
			zone_ = sf::FloatRect(80,480,350,520);
			break;
		
		case Controls :
			zone_ = sf::FloatRect(5, 40, 240, 110);
			break;
			
		default : break;
	}
}

Button::~Button ()
{}

bool Button::contains (int mouse_x, int mouse_y)
{
  return zone_.Contains(mouse_x, mouse_y);
}

Action Button::getAction ()
{
  return action_;
}
