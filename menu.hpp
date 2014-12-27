#ifndef MENU_HPP
#define MENU_HPP

#include <list>
#include <SFML/Graphics.hpp>
#include "main.hpp"
#include "button.hpp"

using namespace sf;

class Menu
{
public:
  Menu (GameState state);
  ~Menu ();

  void display (sf::RenderTarget *rt);


  void setCurrentButton (int mouse_x, int mouse_y);
  Action getAction ();
  
  void displayButtons (sf::RenderTarget *rt);

private:

  Action current_button_;
  std::list<Button *> buttons_;
  sf::String title_;
  
  Image *background_img_;
  Sprite *background_spr_;
	

	Image *shade_img_;
	Sprite *shade_play_;
	Sprite *shade_exit_;
	Sprite *shade_controls_;
	
	
	GameState menu_state_;
	
};

#endif // MENU_HPP
