#ifndef CHARACTER_HPP
#define CHARACTER_HPP


//Constantes d'initialisation des sprites de déplacements
#define MOV_AMNT_SPRITE_PC 6 	/*nombre de sprites synthétisant
								 un déplacement pour un caractère jouable*/
#define MOV_AMNT_SPRITE_NPC 1 	/*nombre de sprites synthétisant
								 un déplacement pour un caractère non jouable*/
#define MOV_CHAR_W 35 //largeur d'un sprite
#define MOV_CHAR_H 67 //hauteur d'un sprite
#define MOV_DIFF_CHAR_W 15 //largeur entre deux sprites
#define MOV_DIFF_CHAR_H 35 //hauteur entre deux sprites

//Constantes d'initialisation des sprites d'attaques
#define ATK_AMNT_SPRITE_PC 4 	/*nombre de sprites synthétisant une attaque
							pour un personnage jouable*/
#define ATK_AMNT_SPRITE_NPC 1 	/*nombre de sprites synthétisant une attaque
							pour un personnage jouable*/
#define ATK_CHAR_W 50 //largeur d'un sprite
#define ATK_CHAR_H 50 //hauteur d'un sprite
#define ATK_DIFF_CHAR_H 50 //hauteur entre deux sprites

#define OFFSET_IMG_W 50 //offset des premiers sprites en largeur
#define OFFSET_IMG_H 10 //offset des premiers sprites en hauteur


#include <SFML/Graphics.hpp>
#include "main.hpp"

class Character
{
public:

	Character ();
	~Character ();
	
	void look (Direction dir);
	void attack ();
	void display(sf::RenderTarget &rt, float elapsed_time, bool is_playable);
	void display_attack (sf::RenderTarget &rt, float elapsed_time, bool is_playable);
	bool isLooking (Direction dir);
	bool isAlive ();
	bool isAttacking ();
	int getX ();
	int getY ();
	Direction getDir ();
	void setPosition (int x, int y);

protected:
	
	sf::Image *general_dir_;
	sf::Image *general_atks_;
	
	sf::Sprite *up_dir_[MOV_AMNT_SPRITE_PC];
	sf::Sprite *down_dir_[MOV_AMNT_SPRITE_PC];
	sf::Sprite *left_dir_[MOV_AMNT_SPRITE_PC];
	sf::Sprite *right_dir_[MOV_AMNT_SPRITE_PC];
	
	sf::Sprite *up_attacks_[ATK_AMNT_SPRITE_PC];
	sf::Sprite *down_attacks_[ATK_AMNT_SPRITE_PC];
	sf::Sprite *left_attacks_[ATK_AMNT_SPRITE_PC];
	sf::Sprite *right_attacks_[ATK_AMNT_SPRITE_PC];
	
	sf::Sprite **directions_[4];
	sf::Sprite **attacks_[4];
	
	Direction dir_;
	bool change_look_; //permet de déterminer si on doit réinitialiser les étapes de mouvements
	bool attacking_; //permet de déterminer si le personnage réalise une attaque
	int step_mov_; //permet de déterminer l'étape de mouvement en cours
	int step_atk_;
	int x_, y_;
	int health_;

};

#endif // CHARACTER_HPP
