#ifndef NPC_HPP
#define NPC_HPP

#include <SFML/Graphics.hpp>
#include <string.h>
#include "character.hpp"

#define HEALTH_NPC 3
#define HEALTH_MINIBOSS 1

class Npc: public Character
{
public:
  
	Npc (bool is_miniboss);
	Npc (int x, int y, bool is_miniboss);
	~Npc ();
	
	void move (Direction dir);
	
private:

	sf::Sprite *up_dir_[MOV_AMNT_SPRITE_NPC];
	sf::Sprite *down_dir_[MOV_AMNT_SPRITE_NPC];
	sf::Sprite *left_dir_[MOV_AMNT_SPRITE_NPC];
	sf::Sprite *right_dir_[MOV_AMNT_SPRITE_NPC];
	
	sf::Sprite *up_attacks_[ATK_AMNT_SPRITE_NPC];
	sf::Sprite *down_attacks_[ATK_AMNT_SPRITE_NPC];
	sf::Sprite *left_attacks_[ATK_AMNT_SPRITE_NPC];
	sf::Sprite *right_attacks_[ATK_AMNT_SPRITE_NPC];

	bool is_miniboss_;

};
#endif // NPC_HPP
