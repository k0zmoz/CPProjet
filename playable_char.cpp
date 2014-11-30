#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "character.hpp"
#include "playable_char.hpp"


using namespace sf;
using namespace std;

Playable_Char::Playable_Char () : Character ()
	{
		int i, j;
  
		general_dir_ = new sf::Image;
	 	general_atks_ = new sf::Image; 

		//instanciation des sprites de déplacement
	  
		if(! general_dir_->LoadFromFile("./sprite_char/walk/general_walk.png")){
			cerr << "Error Loading Walk Image" << endl;
			exit(EXIT_FAILURE);
		}
	
		directions_[Down] = down_dir_;
		directions_[Up] = up_dir_;
		directions_[Right] = right_dir_;
		directions_[Left] = left_dir_;
	
		for( i = 0; i < 4; i++){		//4 directions
			for(j = 0; j < MOV_AMNT_SPRITE_PC; j++){
				directions_[i][j] = new sf::Sprite(*general_dir_);
				directions_[i][j]->SetSubRect(sf::IntRect(
				OFFSET_IMG_W + j * (MOV_CHAR_W + MOV_DIFF_CHAR_W),
				OFFSET_IMG_H + i * (MOV_CHAR_H + MOV_DIFF_CHAR_H),
				OFFSET_IMG_W + j * (MOV_CHAR_W + MOV_DIFF_CHAR_W) + MOV_CHAR_W,
				OFFSET_IMG_H + i * (MOV_CHAR_H + MOV_DIFF_CHAR_H) + MOV_CHAR_H));
			}
		}
	
		//instanciation des sprites d'attaques
	
		 if(! general_atks_->LoadFromFile("./sprite_char/attack/general_atcks.png")){
			cerr << "Error Loading Atk Image" << endl;
			exit(EXIT_FAILURE);
		}
	
		attacks_[Down] = down_attacks_;
		attacks_[Up] = up_attacks_;
		attacks_[Right] = right_attacks_;
		attacks_[Left] = left_attacks_;
	
		for( i = 0; i < 4; i++){		//4 directions
			for(j = 0; j < ATK_AMNT_SPRITE_PC; j++){
				attacks_[i][j] = new sf::Sprite(*general_atks_);
				attacks_[i][j]->SetSubRect(sf::IntRect(
				OFFSET_IMG_W + j * ATK_CHAR_W,
				OFFSET_IMG_H + i * (ATK_CHAR_H + ATK_DIFF_CHAR_H),
				OFFSET_IMG_W + (j * ATK_CHAR_W) + ATK_CHAR_W,
				OFFSET_IMG_H + (i * (ATK_CHAR_H + ATK_DIFF_CHAR_H)) + ATK_CHAR_H));
			}
		}
		
		
		health_ = HEALTH_PC;
		escape_disabled_ = false;
	}

	
Playable_Char::~Playable_Char ()
	{
	}


void Playable_Char::move (Direction dir)
	{
		switch (dir) {
			case Up:
			  y_ -= CHAR_SPEED;
			  break;
			case Down:
			  y_ += CHAR_SPEED;
			  break;
			case Left:
			  x_ -= CHAR_SPEED;
			  break;
			case Right:
			  x_ += CHAR_SPEED;
			  break;
		}

		step_mov_++;
		if(step_mov_ == MOV_AMNT_SPRITE_PC || change_look_ == true){
			step_mov_ = 0;
			change_look_ = false;
		}

	}
	

void Playable_Char::escape (Direction dir)
	{
		switch (dir) {
			case Up:
			  y_ -= ESCAPE_RANGE;
			  break;
			case Down:
			  y_ += ESCAPE_RANGE;
			  break;
			case Left:
			  x_ -= ESCAPE_RANGE;
			  break;
			case Right:
			  x_ += ESCAPE_RANGE;
			  break;
		}
	}
