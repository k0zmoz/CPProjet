#ifndef NPC_HPP
#define NPC_HPP

#include <SFML/Graphics.hpp>
#include "character.hpp"


class Npc: public Character
{
public:
  
	Npc ();
	~Npc ();
	
	void move (Direction dir);
	

};
#endif // NPC_HPP
