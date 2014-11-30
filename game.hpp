#ifndef GAME_HPP
#define GAME_HPP

#include <list>
#include <SFML/Graphics.hpp>
#include "character.hpp"
#include "playable_char.hpp"

class Game
{
public:

	Game();
	~Game();

	void run ();

private:

	sf::RenderWindow *win_;
	Playable_Char *hero_;
	sf::Clock *clk_;
  
  
};

#endif // GAME_HPP
