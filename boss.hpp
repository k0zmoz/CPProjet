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

#define OFFSET_MOV_BOSS_W 30//Offset en largeur pour les déplacements

//Constantes d'initialisation des sprites d'attaques
#define ATK_DOWN_LEFT_BOSS_W 180 //largeur d'un sprite vers le bas et la gauche
#define ATK_XL_DOWN_LEFT_BOSS_W 250 //largeur d'un sprite large vers le bas et la gauche
#define ATK_UP_RIGHT_BOSS_W 170 //largeur d'un sprite vers le haut et la droite
#define ATK_XL_UP_RIGHT_BOSS_W 200 //largeur d'un sprite large vers le haut et la droite
#define ATK_DOWN_LEFT_BOSS_H 210 //hauteur d'un sprite vers le bas et la gauche
#define ATK_UP_RIGHT_BOSS_H 240 //hauteur d'un sprite vers le haut et la droite
#define ATK_DIFF_BOSS_H 20 //hauteur entre deux sprites

#define OFFSET_ATK_BOSS_W 40//Offset en largeur pour les déplacements

// useless #define OFFSET_ATK_BOSS_H 1100//Offset en hauteur pour les attaques

//Constantes d'initialisation des sprites de mort
#define DEATH_DOWN_LEFT_BOSS_W 180 //largeur d'un sprite vers le bas et la gauche
#define DEATH_UP_RIGHT_BOSS_W 155 //largeur d'un sprite vers le haut et la droite
#define DEATH_DOWN_LEFT_BOSS_H 220 //hauteur d'un sprite vers le bas et la gauche
#define DEATH_UP_RIGHT_BOSS_H 245 //hauteur d'un sprite vers le haut et la droite
#define DEATH_DIFF_BOSS_H 30 //hauteur entre deux sprites

#define OFFSET_DEATH_BOSS_W 40

#define HEALTH_BOSS 10

//Point de spawn
#define SPAWN_BOSS_X -800
#define SPAWN_BOSS_Y 4544

//Coordonnées de la salle du boss (rectangulaire)
#define LEFT_COORD_ROOM -1150
#define TOP_COORD_ROOM -2000
#define RIGHT_COORD_ROOM 1150
#define BOTTOM_COORD_ROOM 2000

//Distance parcourue entre deux changement de sprites lors d'une charge
#define DIST_CHARGE 50

#define DAMAGE_BOSS 3

class Boss: public Character
{
public:
  
	Boss ();
	~Boss ();
	
	void displayDeath(sf::RenderTarget &rt);
	void displayAttack (sf::RenderTarget &rt, bool is_playable);
	void display (sf::RenderTarget &rt, bool is_playable);
	void charge(Direction dir);
	bool isInRoom(int x, int y);
	bool isInvincible();
	
	int getStepDeath ();
	sf::Sprite getSprite(TypeSprite typespr, Direction dir, int step);
	int getSizeBossSprite(sf::Sprite spr, bool width_requested);
	
	void setInvincible(bool invi);
	
	sf::Sprite copyandflipSprite (sf::Sprite *sp);
	
private:

	sf::Sprite *up_dir_[MOV_AMNT_SPRITE_BOSS];
	sf::Sprite *down_dir_[MOV_AMNT_SPRITE_BOSS];
	sf::Sprite *left_dir_[MOV_AMNT_SPRITE_BOSS];
	sf::Sprite *right_dir_[MOV_AMNT_SPRITE_BOSS];

	sf::Sprite *up_attacks_[ATK_AMNT_SPRITE_BOSS];
	sf::Sprite *down_attacks_[ATK_AMNT_SPRITE_BOSS];
	sf::Sprite *left_attacks_[ATK_AMNT_SPRITE_BOSS];
	sf::Sprite *right_attacks_[ATK_AMNT_SPRITE_BOSS];

	sf::Sprite *up_deaths_[DEATH_AMNT_SPRITE_BOSS];
	sf::Sprite *down_deaths_[DEATH_AMNT_SPRITE_BOSS];
	sf::Sprite *left_deaths_[DEATH_AMNT_SPRITE_BOSS];
	sf::Sprite *right_deaths_[DEATH_AMNT_SPRITE_BOSS];

	sf::Image *general_deaths_;	
	sf::Sprite **deaths_[4];
	
	sf::Rect<int> * room_;
	sf::Clock *clk_death_;
	
	int step_death_;
	bool invincible_;

};
#endif // BOSS_HPP
