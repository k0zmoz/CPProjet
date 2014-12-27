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
#define ATK_CHAR_W 50
#define ATK_CHAR_H 67
#define ATK_DIFF_CHAR_H 35


#define ESCAPE_RANGE 20 //Distance parcourue par un pc lors d'une esquive
#define HEALTH_PC 30 //Vie totale d'un pc
#define DAMAGE_PC 5 //Dommages portés lors d'une attaque de pc
#define AMNT_ESCAPE_PC 2 //Nombre d'esquives disponibles pour un pc

#define DELAY_USE_ESCAPE 1 //temps (en s) entre deux utilisations de l'esquive 
#define DELAY_REGEN_STAMINA 4 //temps (en s) avant de régénérer l'endurance
#define DELAY_REGEN_HEALTH 12 //temps (en s) avant de régénérer la vie
#define SPEED_REGEN_HEALTH 3 //Nombre de points de vie rendus par tick de régénération

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
