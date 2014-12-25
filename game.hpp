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

//temps (en s) pendant lequel est affiché l'écran de fin
#define DISPLAY_FINISH 10

class Game
{
public:

	Game();
	~Game();

	void run ();

private:

	sf::RenderWindow *win_;
	
	PlayableChar *hero_;
	Map *map_;
	CombatManager *cm_;
	Menu *menu_start_, *menu_echap_, *menu_end_;
	Musique *musique_;
	sf::Clock *clk_finish_;

  Action current_action_;
	GameState gs_;
};

#endif // GAME_HPP
