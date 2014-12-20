#ifndef PLAYABLE_CHAR_HPP
#define PLAYABLE_CHAR_HPP

#include <SFML/Graphics.hpp>
#include "character.hpp"

#define ESCAPE_RANGE 100
#define HEALTH_PC 20

class Playable_Char: public Character
{
public:
  
	Playable_Char ();
	~Playable_Char ();

	void move (Direction dir);
	void escape (Direction dir);
  
private:

	sf::Sprite *up_dir_[MOV_AMNT_SPRITE_PC];
	sf::Sprite *down_dir_[MOV_AMNT_SPRITE_PC];
	sf::Sprite *left_dir_[MOV_AMNT_SPRITE_PC];
	sf::Sprite *right_dir_[MOV_AMNT_SPRITE_PC];
	
	sf::Sprite *up_attacks_[ATK_AMNT_SPRITE_PC];
	sf::Sprite *down_attacks_[ATK_AMNT_SPRITE_PC];
	sf::Sprite *left_attacks_[ATK_AMNT_SPRITE_PC];
	sf::Sprite *right_attacks_[ATK_AMNT_SPRITE_PC];
	
	bool escape_disabled_;

};
#endif // PLAYABLE_CHAR_HPP
