#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include "main.hpp"
//#include <Vector>

//Constantes définissant le nombre de sprites pour chaque type de character

#define MOV_AMNT_SPRITE_PC 6 	//nombre de sprites synthétisant un déplacement
#define ATK_AMNT_SPRITE_PC 4 	//nombre de sprites synthétisant une attaque

#define MOV_AMNT_SPRITE_NPC 1
#define ATK_AMNT_SPRITE_NPC 1

#define MOV_AMNT_SPRITE_BOSS 8
#define ATK_AMNT_SPRITE_BOSS 7
#define DEATH_AMNT_SPRITE_BOSS 7 	//nombre de sprites synthétisant la mort

//Offset général sur les images
#define OFFSET_IMG_W 50 //offset des premiers sprites en largeur
#define OFFSET_IMG_H 10 //offset des premiers sprites en hauteur


using namespace std;

class Character
{

public:

	Character ();
	~Character ();
	
	void look (Direction dir);
	void move (Direction dir, int speed, int amnt_sprite);
	void attack ();
	void display(sf::RenderTarget &rt, bool is_playable);
	void display_attack (sf::RenderTarget &rt, bool is_playable);
	bool isLooking (Direction dir);
	bool isAlive ();
	bool isAttacking ();
	int getX ();
	int getY ();
	int getStepMov ();
	int getStepAtk();
	int getHealth();
	
	Direction getDir ();
	void setPosition (int x, int y);
	void setHealth(int health);

protected:
	
	sf::Image *general_dir_;
	sf::Image *general_atks_;
	
	sf::Sprite **directions_[4];
	sf::Sprite **attacks_[4];
	
	Direction dir_;
	sf::Clock *clk_atk_;
	bool change_look_; //permet de déterminer si on doit réinitialiser les étapes de mouvements
	bool attacking_; //permet de déterminer si le personnage réalise une attaque
	int step_mov_; //permet de déterminer l'étape de mouvement en cours
	int step_atk_;
	int x_, y_;
	int health_;

};

#endif // CHARACTER_HPP
