#ifndef BOSS_HPP
#define BOSS_HPP

#include <SFML/Graphics.hpp>
#include <string.h>
#include "character.hpp"

//Constantes d'initialisation des sprites de déplacements
#define MOV_DOWN_LEFT_BOSS_W 180 //largeur d'un sprite vers le bas et la gauche
#define MOV_UP_RIGHT_BOSS_W 170 //largeur d'un sprite vers le haut et la droite
#define MOV_DOWN_LEFT_BOSS_H 220 //hauteur d'un sprite vers le bas et la gauche
#define MOV_UP_RIGHT_BOSS_H 240 //hauteur d'un sprite vers le haut et la droite
#define MOV_DIFF_BOSS_W 10 //largeur entre deux sprites
#define MOV_DIFF_BOSS_H 40 //hauteur entre deux sprites

#define OFFSET_MOV_BOSS_W 30//Offset en hauteur pour les déplacements

//Constantes d'initialisation des sprites d'attaques
#define ATK_DOWN_LEFT_BOSS_W 180 //largeur d'un sprite vers le bas et la gauche
#define ATK_XL_DOWN_LEFT_BOSS_W 250 //largeur d'un sprite large vers le bas et la gauche
#define ATK_UP_RIGHT_BOSS_W 170 //largeur d'un sprite vers le haut et la droite
#define ATK_XL_UP_RIGHT_BOSS_W 200 //largeur d'un sprite large vers le haut et la droite
#define ATK_DOWN_LEFT_BOSS_H 210 //hauteur d'un sprite vers le bas et la gauche
#define ATK_UP_RIGHT_BOSS_H 240 //hauteur d'un sprite vers le haut et la droite
#define ATK_DIFF_BOSS_H 20 //hauteur entre deux sprites

#define OFFSET_ATK_BOSS_H 1100//Offset en hauteur pour les attaques

//Constantes d'initialisation des sprites de mort
#define DEATH_DOWN_LEFT_BOSS_W 180 //largeur d'un sprite vers le bas et la gauche
#define DEATH_UP_RIGHT_BOSS_W 155 //largeur d'un sprite vers le haut et la droite
#define DEATH_DOWN_LEFT_BOSS_H 220 //hauteur d'un sprite vers le bas et la gauche
#define DEATH_UP_RIGHT_BOSS_H 245 //hauteur d'un sprite vers le haut et la droite
#define DEATH_DIFF_BOSS_H 30 //hauteur entre deux sprites

#define OFFSET_DEATH_BOSS_H 1600//Offset en hauteur pour la mort

#define HEALTH_BOSS 10

//Point de spawn
#define SPAWN_BOSS_X 500
#define SPAWN_BOSS_Y 500


class Boss: public Character
{
public:
  
	Boss ();
	~Boss ();
	
	void move (Direction dir);
	sf::Sprite copyandflipSprite (sf::Sprite *sp);
	
private:

	sf::Sprite *up_dir_[MOV_AMNT_SPRITE_BOSS];
	sf::Sprite *down_dir_[MOV_AMNT_SPRITE_BOSS];
	sf::Sprite *left_dir_[MOV_AMNT_SPRITE_BOSS];
	sf::Sprite *right_dir_[MOV_AMNT_SPRITE_BOSS];
	/*
	sf::Sprite *up_attacks_[ATK_AMNT_SPRITE_BOSS];
	sf::Sprite *down_attacks_[ATK_AMNT_SPRITE_BOSS];
	sf::Sprite *left_attacks_[ATK_AMNT_SPRITE_BOSS];
	sf::Sprite *right_attacks_[ATK_AMNT_SPRITE_BOSS];
	
	sf::Sprite *up_death_[DEATH_AMNT_SPRITE_BOSS];
	sf::Sprite *down_deaths_[DEATH_AMNT_SPRITE_BOSS];
	sf::Sprite *left_deaths_[DEATH_AMNT_SPRITE_BOSS];
	sf::Sprite *right_deaths_[DEATH_AMNT_SPRITE_BOSS];
*/
	

};
#endif // BOSS_HPP
