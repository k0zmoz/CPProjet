#ifndef NPC_HPP
#define NPC_HPP

#include <SFML/Graphics.hpp>
#include "character.hpp"

#define HEALTH_NPC 3

class Npc: public Character
{
public:
  
	Npc ();
	Npc (int x, int y);
	~Npc ();
	
	void move (Direction dir);
	

};
#endif // NPC_HPP
