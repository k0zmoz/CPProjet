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

  void display (sf::RenderTarget *rt, GameState gs);

  void setCurrentButton (int mouse_x, int mouse_y);
  Action getAction ();
  
  void displayButtons (sf::RenderTarget *rt);

private:

  Action current_button_;
  std::list<Button *> buttons_;
  sf::String title_;
  
  Image *background_img_;
  Sprite *background_spr_;
	
	Image *play_exit_red_img_;
	Sprite *play_exit_red_spr_;
	
	Image *play_exit_violet_img_;
	Sprite *startgame_playspr_;
	Sprite *startgame_exitspr_;
	
	Image *resume_exit_red_img_;
	Sprite *resume_exit_red_spr_;
	
	Image *resume_exit_violet_img_;
	Sprite *echap_resumespr_;
	Sprite *echap_exitspr_;
	
	Image *princess_img_;
	Sprite *princess_spr_;
	
	Image *newgame_nevermore_img_;
	Sprite *newgame_go_spr_;
	Sprite *nevermore_go_spr_;
	
	GameState menu_state_;
	
};

#endif // MENU_HPP
