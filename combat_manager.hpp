#ifndef COMBAT_MANAGER_HPP
#define COMBAT_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <list>
#include "map.hpp"
#include "character.hpp"
#include "playable_char.hpp"
#include "npc.hpp"
#include "boss.hpp"
#include "arrow.hpp"
#include "arrow.hpp"
#include "crystal.hpp"
#include "map.hpp"

//Rayon dans lequel chercher un Character par rapport à un point fixe quelconque
#define RADIUS_LOCATE_COORD 10

//Rayon dans lequel chercher un Playable_char
#define RADIUS_LOCATE_PC 500

//Constantes relatives aux Npc

//Vitesse à laquelle un Npc change de direction aléatoirement
#define SWITCH_DIR_SPEED_NPC 1.3

//Centre de la salle du NPC
#define CENTER_ROOM_NPC_X 159
#define CENTER_ROOM_NPC_Y 83

//Rayon dans lequel un Npc peut se déplacer aléatoirement au centre de sa salle
#define RADIUS_ROOM_NPC 200


//Constantes relatives aux Boss



using namespace std;

class CombatManager
{

public:

	CombatManager ();
	~CombatManager ();
	
	void run(PlayableChar * pc);
	
	//Gestion des déplacements
	void wander (Character *chara);
	void headToCoord (Character *chara, int x, int y);
	void popBoss ();
	bool isInRadius1D (Character *chara, int coord, int radius, bool test_absciss);
	bool isInRadius2D (Character *chara, int x, int y, int radius);
	bool isNearHero (Character * chara, PlayableChar *pc);
	void moveNpc(Npc *npc, int x, int y);
	void moveRandomlyNpc(Npc *npc);
	void moveArrow(Arrow *arr);
	void moveBoss(Boss *boss, int x, int y);
	
	Npc *getNpc ();
	Arrow *getArrow ();
	Crystal *getCrystal ();
	Boss *getBoss ();
	
	//Gestion des attaques
	//bool IsInRangeAtk(string typeid(Character).name())

private:
	
	Npc *trash_mob_, *miniboss_;
	Arrow *arr_;
	Crystal *cryst_;
	Boss *duneyrr_;
	sf::Clock *clk_mov_npc_;

};

#endif // COMBAT_MANAGER_HPP
