#ifndef NPC_HPP
#define NPC_HPP

#include <SFML/Graphics.hpp>
#include <string.h>
#include "character.hpp"

#define HEALTH_NPC 3

class Npc: public Character
{
public:
  
	Npc (string s);
	Npc (string s, int x, int y);
	~Npc ();
	
	void move (Direction dir);
	

};
#endif // NPC_HPP
