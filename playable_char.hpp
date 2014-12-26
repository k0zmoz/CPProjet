#ifndef PLAYABLECHAR_HPP
#define PLAYABLECHAR_HPP

#include <SFML/Graphics.hpp>
#include "character.hpp"

//Constantes d'initialisation des sprites de déplacements

#define MOV_CHAR_W 35 //largeur d'un sprite
#define MOV_CHAR_H 67 //hauteur d'un sprite
#define MOV_DIFF_CHAR_W 15 //largeur entre deux sprites
#define MOV_DIFF_CHAR_H 35 //hauteur entre deux sprites

//Constantes d'initialisation des sprites d'attaques
#define ATK_CHAR_W 50 //largeur d'un sprite
#define ATK_CHAR_H 67 //hauteur d'un sprite
#define ATK_DIFF_CHAR_H 35 //hauteur entre deux sprites

#define ESCAPE_RANGE 20
#define HEALTH_PC 0
#define DAMAGE_PC 5
#define AMNT_ESCAPE_PC 2

#define DELAY_USE_ESCAPE 1
#define DELAY_REGEN_STAMINA 4
#define DELAY_REGEN_HEALTH 20
#define SPEED_REGEN_HEALTH 3

class PlayableChar: public Character
{
public:
  
	PlayableChar ();
	~PlayableChar ();

	void move ();
	void escape ();
	
	bool isHit();
	bool isStaminaUsable();
	
	int getStamina();
	bool getEscaping();
	
	void setHit(bool hit);
	void setStamina(int stam);
  
private:

	sf::Sprite *up_dir_[MOV_AMNT_SPRITE_PC];
	sf::Sprite *down_dir_[MOV_AMNT_SPRITE_PC];
	sf::Sprite *left_dir_[MOV_AMNT_SPRITE_PC];
	sf::Sprite *right_dir_[MOV_AMNT_SPRITE_PC];
	
	sf::Sprite *up_attacks_[ATK_AMNT_SPRITE_PC];
	sf::Sprite *down_attacks_[ATK_AMNT_SPRITE_PC];
	sf::Sprite *left_attacks_[ATK_AMNT_SPRITE_PC];
	sf::Sprite *right_attacks_[ATK_AMNT_SPRITE_PC];
	
	sf::Clock *clk_use_stamina_;
	
	int stamina_;
	bool hit_;

};
#endif // PLAYABLECHAR_HPP
