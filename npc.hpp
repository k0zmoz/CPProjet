#ifndef NPC_HPP
#define NPC_HPP

#include <SFML/Graphics.hpp>
#include <string.h>
#include "character.hpp"

//Constantes d'initialisation des sprites de déplacements
#define MOV_NPC_W 35 //largeur d'un sprite
#define MOV_NPC_H 70 //hauteur d'un sprite
#define MOV_DIFF_NPC_W 15 //largeur entre deux sprites
#define MOV_DIFF_NPC_H 30 //hauteur entre deux sprites


//Constantes d'initialisation des sprites d'attaques
#define ATK_NPC_W 50 //largeur d'un sprite
#define ATK_NPC_H 70 //hauteur d'un sprite
#define ATK_DIFF_NPC_H 30 //hauteur entre deux sprites


//Offset général sur les images
#define OFFSET_MINIBOSS_W 100 //Offset en largeur spécifique aux sprites de miniboss

#define HEALTH_NPC 6
#define HEALTH_MINIBOSS 1
#define DAMAGE_NPC 1 //Dégâts d'un npc


class Npc: public Character
{
public:
  
	Npc (bool is_miniboss);
	Npc (int x, int y, bool is_miniboss);
	~Npc ();
	
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
