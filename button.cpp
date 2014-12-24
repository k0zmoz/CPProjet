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
		case NewGame :	
				zone_ = sf::FloatRect(373,288,502,374);
				break;
		case Exit : 	
				zone_ = sf::FloatRect(371,426,515,518);
				break;
				
		case Resume : 	cout << "premiere zone";
				zone_ = sf::FloatRect(367,308,521,355);
				break;
				
		case Exit2 : cout << "deuxieme zone";
				zone_ = sf::FloatRect(384,419,483,465);
				break;
				
								
		default : cout << "default" << "\ndefault";break;
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

void Button::display (sf::RenderTarget *rt)
{
  rt->Draw(text_);
}

int Button::displayActive (sf::RenderTarget *rt)
{
	switch (getAction())
	{
		case NewGame : return 1; break;
		case Exit : 	return 2; break;
		case Resume : 	cout << "  resume" << endl; return 3; break;
		case Exit2 : 	cout<<"exit2" << endl; return 4; break;
		default :  	cout << "default"; return -1; break;
	
	}
	return -1;
}
