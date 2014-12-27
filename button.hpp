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

private:

  sf::FloatRect zone_;
  Action action_;

};

#endif // BUTTON_HPP
