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
#include "music_manager.hpp"
#include "menu.hpp"
#include "combat_manager.hpp"
#include "hud.hpp"

//temps (en s) pendant lequel est affiché l'écran de fin
#define DISPLAY_FINISH 185

//temps (en s) pendant lequel est affiché la mort du boss
#define DELAY_VICTORY 0.4

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
	MusicManager *mm_;
	Hud *hud_;
	Menu *menu_start_, *menu_echap_, *menu_end_, *menu_go_;
	sf::Clock *clk_display_finish_, *clk_delay_victory_;

  Action current_action_;
	GameState gs_;
	
	bool boss_door_;
};

#endif // GAME_HPP
