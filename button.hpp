#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include "main.hpp"

class Button
{
public:
  Button (Action action);
  ~Button ();

  bool contains (int mouse_x, int mouse_y);
  Action getAction ();

  void display (sf::RenderTarget *rt);
  int displayActive (sf::RenderTarget *rt);

private:
  sf::String text_;
  sf::FloatRect zone_;
  Action action_;
  int page_;
};

#endif // BUTTON_HPP
