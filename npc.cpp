#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "npc.hpp"


using namespace sf;
using namespace std;

Npc::Npc (bool is_miniboss) : Character ()
{
	int i, j;

	general_dir_ = new sf::Image;
 	general_atks_ = new sf::Image; 

	//instanciation des sprites de déplacement
	if(! general_dir_->LoadFromFile("./sprite/mob/mob_walking.png")){
		cerr << "Error Loading Walk Image" << endl;
		exit(EXIT_FAILURE);
	}


	directions_[Down] = down_dir_;
	directions_[Up] = up_dir_;
	directions_[Right] = right_dir_;
	directions_[Left] = left_dir_;

	if(!is_miniboss)
	{
		for( i = 0; i < 4; i++){		//4 directions
			for(j = 0; j < MOV_AMNT_SPRITE_NPC; j++){
				directions_[i][j] = new sf::Sprite(*general_dir_);
				directions_[i][j]->SetSubRect(sf::IntRect(
				OFFSET_IMG_W + j * (MOV_NPC_W + MOV_DIFF_NPC_W),
				OFFSET_IMG_H + i * (MOV_NPC_H + MOV_DIFF_NPC_H),
				OFFSET_IMG_W + j * (MOV_NPC_W + MOV_DIFF_NPC_W) + MOV_NPC_W,
				OFFSET_IMG_H + i * (MOV_NPC_H + MOV_DIFF_NPC_H) + MOV_NPC_H));
			}
		}
	}
	else
	{
		for( i = 0; i < 4; i++){		//4 directions
			for(j = 0; j < MOV_AMNT_SPRITE_NPC; j++){
				directions_[i][j] = new sf::Sprite(*general_dir_);
				directions_[i][j]->SetSubRect(sf::IntRect(
				OFFSET_IMG_W + OFFSET_MINIBOSS_W + j * (MOV_NPC_W + MOV_DIFF_NPC_W),
				OFFSET_IMG_H + i * (MOV_NPC_H + MOV_DIFF_NPC_H),
				OFFSET_IMG_W + OFFSET_MINIBOSS_W + j * (MOV_NPC_W + MOV_DIFF_NPC_W) + MOV_NPC_W,
				OFFSET_IMG_H + i * (MOV_NPC_H + MOV_DIFF_NPC_H) + MOV_NPC_H));
			}
		}
	}


		
	//instanciation des sprites d'attaques
	 if(! general_atks_->LoadFromFile("./sprite/mob/mob_atk.png")){
		cerr << "Error Loading Atk Image" << endl;
		exit(EXIT_FAILURE);
	}

	attacks_[Down] = down_attacks_;
	attacks_[Up] = up_attacks_;
	attacks_[Right] = right_attacks_;
	attacks_[Left] = left_attacks_;

	if(!is_miniboss)
	{
		for( i = 0; i < 4; i++){		//4 directions
			for(j = 0; j < ATK_AMNT_SPRITE_NPC; j++){
				attacks_[i][j] = new sf::Sprite(*general_atks_);
				attacks_[i][j]->SetSubRect(sf::IntRect(
				OFFSET_IMG_W + j * ATK_NPC_W,
				OFFSET_IMG_H + i * (ATK_NPC_H + ATK_DIFF_NPC_H),
				OFFSET_IMG_W + (j * ATK_NPC_W) + ATK_NPC_W,
				OFFSET_IMG_H + (i * (ATK_NPC_H + ATK_DIFF_NPC_H)) + ATK_NPC_H));
			}
		}
	}
	else
	{
		for( i = 0; i < 4; i++){		//4 directions
			for(j = 0; j < ATK_AMNT_SPRITE_NPC; j++){
				attacks_[i][j] = new sf::Sprite(*general_atks_);
				attacks_[i][j]->SetSubRect(sf::IntRect(
				OFFSET_IMG_W + OFFSET_MINIBOSS_W + j * ATK_NPC_W,
				OFFSET_IMG_H + i * (ATK_NPC_H + ATK_DIFF_NPC_H),
				OFFSET_IMG_W + OFFSET_MINIBOSS_W + (j * ATK_NPC_W) + ATK_NPC_W,
				OFFSET_IMG_H + (i * (ATK_NPC_H + ATK_DIFF_NPC_H)) + ATK_NPC_H));
			}
		}
	}
	
	if(! is_miniboss)
	{
		health_ = HEALTH_NPC;
	}
	else
	{
		health_ = HEALTH_MINIBOSS;
	}

}	



//Creation d'un npc à une position donnée
Npc::Npc (int x, int y, bool is_miniboss) : Character ()
{

	int i, j;

	general_dir_ = new sf::Image;
 	general_atks_ = new sf::Image; 

	//instanciation des sprites de déplacement
	if(! general_dir_->LoadFromFile("./sprite/mob/mob_walking.png")){
		cerr << "Error Loading Walk Image" << endl;
		exit(EXIT_FAILURE);
	}

	directions_[Down] = down_dir_;
	directions_[Up] = up_dir_;
	directions_[Left] = left_dir_;
	directions_[Right] = right_dir_;

	if(!is_miniboss)
	{
		for( i = 0; i < 4; i++){		//4 directions
			for(j = 0; j < MOV_AMNT_SPRITE_NPC; j++){
				directions_[i][j] = new sf::Sprite(*general_dir_);
				directions_[i][j]->SetSubRect(sf::IntRect(
				OFFSET_IMG_W + j * (MOV_NPC_W + MOV_DIFF_NPC_W),
				OFFSET_IMG_H + i * (MOV_NPC_H + MOV_DIFF_NPC_H),
				OFFSET_IMG_W + j * (MOV_NPC_W + MOV_DIFF_NPC_W) + MOV_NPC_W,
				OFFSET_IMG_H + i * (MOV_NPC_H + MOV_DIFF_NPC_H) + MOV_NPC_H));
			}
		}
	}
	else
	{
		for( i = 0; i < 4; i++){		//4 directions
			for(j = 0; j < MOV_AMNT_SPRITE_NPC; j++){
				directions_[i][j] = new sf::Sprite(*general_dir_);
				directions_[i][j]->SetSubRect(sf::IntRect(
				OFFSET_IMG_W + OFFSET_MINIBOSS_W +j * (MOV_NPC_W + MOV_DIFF_NPC_W),
				OFFSET_IMG_H + i * (MOV_NPC_H + MOV_DIFF_NPC_H),
				OFFSET_IMG_W + OFFSET_MINIBOSS_W + j * (MOV_NPC_W + MOV_DIFF_NPC_W) + MOV_NPC_W,
				OFFSET_IMG_H + i * (MOV_NPC_H + MOV_DIFF_NPC_H) + MOV_NPC_H));
			}
		}
	}

	//instanciation des sprites d'attaques
	 if(! general_atks_->LoadFromFile("./sprite/mob/mob_atk.png")){
		cerr << "Error Loading Atk Image" << endl;
		exit(EXIT_FAILURE);
	}

	attacks_[Down] = down_attacks_;
	attacks_[Up] = up_attacks_;
	attacks_[Left] = left_attacks_;
	attacks_[Right] = right_attacks_;

	if(! is_miniboss)
	{
		for( i = 0; i < 4; i++){		//4 directions
			for(j = 0; j < ATK_AMNT_SPRITE_NPC; j++){
				attacks_[i][j] = new sf::Sprite(*general_atks_);
				attacks_[i][j]->SetSubRect(sf::IntRect(
				OFFSET_IMG_W + j * ATK_NPC_W,
				OFFSET_IMG_H + i * (ATK_NPC_H + ATK_DIFF_NPC_H),
				OFFSET_IMG_W + (j * ATK_NPC_W) + ATK_NPC_W,
				OFFSET_IMG_H + (i * (ATK_NPC_H + ATK_DIFF_NPC_H)) + ATK_NPC_H));
			}
		}
	}
	else
	{
		for( i = 0; i < 4; i++){		//4 directions
			for(j = 0; j < ATK_AMNT_SPRITE_NPC; j++){
				attacks_[i][j] = new sf::Sprite(*general_atks_);
				attacks_[i][j]->SetSubRect(sf::IntRect(
				OFFSET_IMG_W + OFFSET_MINIBOSS_W + j * ATK_NPC_W,
				OFFSET_IMG_H + i * (ATK_NPC_H + ATK_DIFF_NPC_H),
				OFFSET_IMG_W + OFFSET_MINIBOSS_W + (j * ATK_NPC_W) + ATK_NPC_W,
				OFFSET_IMG_H + (i * (ATK_NPC_H + ATK_DIFF_NPC_H)) + ATK_NPC_H));
			}
		}
	}
	
	if(! is_miniboss)
	{
		health_ = HEALTH_NPC;
	}
	else
	{
		health_ = HEALTH_MINIBOSS;
	}
	x_ = x;
	y_ = y;
}

Npc::~Npc ()
{

	for(int i = 0; i < MOV_AMNT_SPRITE_NPC; i++)
	{
		delete up_dir_[i];
		delete down_dir_[i];
		delete left_dir_[i];
		delete right_dir_[i];
	}

	for(int i = 0; i < ATK_AMNT_SPRITE_NPC; i++)
	{
		delete up_attacks_[i];
		delete down_attacks_[i];
		delete left_attacks_[i];
		delete right_attacks_[i];
	}


}
