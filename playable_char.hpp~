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
	
	bool escape_disabled_;

};
#endif // PLAYABLE_CHAR_HPP
