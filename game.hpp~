#ifndef GAME_HPP
#define GAME_HPP

#include <list>
#include <SFML/Graphics.hpp>
#include "main.hpp"
#include "character.hpp"
#include "playable_char.hpp"
#include "npc.hpp"
#include "object.hpp"
#include "arrow.hpp"
#include "crystal.hpp"
#include "boss.hpp"
#include "map.hpp"
#include "musique.hpp"

class Game
{
public:

	Game();
	~Game();

	void run ();

private:

	sf::RenderWindow *win_;
	Playable_Char *hero_;
	Npc *trash_mob_, *miniboss_;
	Arrow *arr_;
	Crystal *cryst_;
	Boss *duneyrr_;
  Map *map_;
	Musique *musique_;
  
};

#endif // GAME_HPP
