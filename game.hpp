#ifndef GAME_HPP
#define GAME_HPP

#include <list>
#include <SFML/Graphics.hpp>
#include "character.hpp"
#include "playable_char.hpp"
#include "npc.hpp"

class Game
{
public:

	Game();
	~Game();

	void run ();

private:

	sf::RenderWindow *win_;
	Playable_Char *hero_;
	Npc *trash_mob_;
	sf::Clock *clk_atk;
  
  
};

#endif // GAME_HPP
