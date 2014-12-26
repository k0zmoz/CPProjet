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
#include "crystal.hpp"
#include "map.hpp"

//Rayon dans lequel un Character considère un point fixe quelconque comme trouvé
#define RADIUS_LOCATE_COORD 10

//Constantes relatives aux Npc

//Vitesse à laquelle un Npc change de direction aléatoirement
#define SWITCH_DIR_SPEED_NPC 0.5
//Centre de la salle du NPC
#define CENTER_ROOM_NPC_X 0
#define CENTER_ROOM_NPC_Y -1388
//Rayon dans lequel un Npc peut se déplacer aléatoirement au centre de sa salle
#define RADIUS_ROOM_NPC 200
//Rayon dans lequel un Npc peut trouver un Playable_char
#define RADIUS_NPC_LOCATE_PC 50
//Rayon dans lequel un Npc essaye d'attaquer
#define RADIUS_NPC_AGGRO 100
//Distance à laquelle un npc touche le joueur
#define RANGE_NPC_ATK 20
//Rayon dans lequel une attaque de npc fait effet
#define RADIUS_NPC_ATK 100

//Delai (en s) au delà duquel vérifier si un Npc peut attaquer
#define CHK_OPPORT_NPC_DELAY 3 

//Constantes relatives aux Boss

//Centre de la salle du Boss
#define CENTER_ROOM_BOSS_X 0
#define CENTER_ROOM_BOSS_Y -1000
//Rayon dans lequel un Boss peut se déplacer aléatoirement au centre de sa salle
#define RADIUS_ROOM_BOSS 200
//Rayon dans lequel un Boss peut trouver un Playable_char
#define RADIUS_BOSS_LOCATE_PC 500 
//Distance à laquelle un Boss essaye d'attaquer
#define RADIUS_BOSS_AGGRO (DIST_CHARGE * ATK_AMNT_SPRITE_BOSS)
//Distance à laquelle un npc touche le joueur
#define RANGE_BOSS_ATK 20
//Rayon dans lequel une attaque de npc fait effet
#define RADIUS_BOSS_ATK 10
//Delai (en s) au delà duquel vérifier si un Npc peut attaquer
#define CHK_OPPORT_BOSS_DELAY 2
 //temps (en s) entre deux mouvements lors de l'animation d'apparition du boss
#define APPEARANCE_BOSS_DELAY 0.8

//Constantes relatives aux Arrow
#define AMNT_ARR_LIST1 1 //nombre de flèches dans list1
#define SPAWN_LIST1_X 0 // abscisse du spawn des flèches de list1
#define SPAWN_LIST1_Y -1472 //ordonnée du spawn des flèches de list1
#define LAUNCH_LIST1_DELAY 2 //délai (en s) avant de lancer une autre flèche de list1
#define DIST_LIM_LIST1 100 //Distance qu'un objet de list1 doit parcourir avant de respawn


//Constantes relatives au PlayableChar (PC)

//Distance à laquelle un pc touche le joueur
#define RANGE_PC_ATK 10
//Rayon dans lequel une attaque de pc fait effet
#define RADIUS_PC_ATK 28

/*Le sprite du boss étant large mais sa hitbox étroite,
on définit une aide pour augmenter le rayon d'action d'une attaque de pc
sur le boss afin que le jeu ne soit pas trop frustrant*/
#define HELP_RADIUS_BOSS 0



using namespace sf;
using namespace std;

class CombatManager
{

public:

	CombatManager ();
	~CombatManager ();
	
	//Méthode principale du CombatManager
	void run(PlayableChar * pc);

	//Méthodes d'utilité générale retournant un booléen
	bool isInRadius1D (Character *chara, int coord, int radius, bool test_absciss);
	bool isInRadius2D (Character *chara, int x, int y, int radius);
	bool isInRadius2DObj (Object *obj, int x, int y, int radius);
	bool isNearHero (Character * chara, PlayableChar *pc, int radius_locate);
	
	//Gestion des déplacements
	void wander (Character *chara);
	//void lookToCoord (Character *chara, int x, int y);
	void headToCoord (Character *chara, int x, int y);
	
	void moveChar(Character *chara, int x, int y, int speed, int amnt_sprite);
	void moveRandomlyChar(Character *chara, int speed, int amnt_sprite);
	void moveArrow(Arrow *arr, Direction dir, int spawn_x, int spawn_y, int dist_lim);
	
	void manageMovNpc(Npc *npc, PlayableChar *pc);
	void manageMovBoss(Boss *boss, PlayableChar *pc);
	void manageMovArrList
	(std::list<Arrow *> arr_list, int spawn_x, int spawn_y, int dist_lim, int launch_delay);
	
	void launchNextArrow(std::list<Arrow *> arr_list);
	void spawnBoss(Boss *boss);
	void displayArrowList(sf::RenderTarget &rt, std::list<Arrow *> arr_list);
	void displayCrystalList(sf::RenderTarget &rt, std::list<Crystal *> cryst_list);
	
	//Gestion des attaques
	void checkOpportunityNpc(Npc *npc, PlayableChar *pc, int radius);
	void checkOpportunityBoss (Boss * boss, PlayableChar *pc, int radius_atk);
	/*void checkOpportunityBoss
	(Boss * boss, PlayableChar *pc, int radius_atk, int width_atk_x, int width_atk_y);
	*/
	void checkOpportunities(std::list<Npc *> npc_list, PlayableChar *pc, Boss *boss);
	
	void checkDamageNPChara
	(Character *npchara, PlayableChar *pc, int range, int radius, int damage);
	void checkDamageAllNpc(std::list<Npc *> npc_list, Boss *boss, PlayableChar *pc);
	void checkDamagePc
	(PlayableChar *pc, std::list<Npc *> npc_list, Boss *boss,
	std::list<Crystal *> cryst_list, int range, int radius, int damage);
	void checkDamageArrow(std::list<Arrow *> arr_list, PlayableChar *pc, int damage);	
	
	void checkDamages(PlayableChar *pc);
	
	//Gestion de la regen du PlayableChar
	void regenPc(PlayableChar *pc);
	
	//Accesseurs
	Npc *getNpc (std::string name);
	Crystal *getCrystal (std::string epithet);
	std::list<Crystal *> getCrystalList ();
	Boss *getBoss ();
	std::list<Arrow *> getList1();

private:
	
	Npc *trash_mob_, *miniboss_;
	Boss *duneyrr_;
	std::list<Npc *> npc_list_;
	
	Crystal *cryst_mob_, *cryst_trap1_, *cryst_trap2_;
	std::list<Crystal *> cryst_list_;
	std::list<Arrow *> arr_list1_;
	
	sf::Clock *clk_mov_npc_, *clk_mov_boss_;
	sf::Clock *clk_launch_arr_list1;
	sf::Clock *clk_chk_opport_boss_, *clk_chk_opport_npc_;
	sf::Clock *clk_regen_health_, *clk_regen_stamina_, *clk_speed_regen_health_;
	
	bool boss_spawned_;

};

#endif // COMBAT_MANAGER_HPP
