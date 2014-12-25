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
#include "menu.hpp"
#include "combat_manager.hpp"

class Game
{
public:

	Game();
	~Game();

	void run ();

private:

	sf::RenderWindow *win_;
	PlayableChar *hero_;
	Action current_action_;
	GameState gs_;
	Map *map_;
	Menu *menu_start_, *menu_echap_;// *menu_end_;
	CombatManager *cm_;
	Musique *musique_;

  
};

#endif // GAME_HPP
