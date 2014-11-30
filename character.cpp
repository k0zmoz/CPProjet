#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "character.hpp"


using namespace sf;
using namespace std;

Character::Character ()
  {
    dir_ = Down;
    x_ = 150;
    y_ = 150;
    change_look_ = true;
    attacking_ = false;
    step_mov_ = 0;
    step_atk_ = 0;
  
  }

Character::~Character()
  {
  	for(int i = 0; i < 4; i++){
		for(int j = 0; j < MOV_AMNT_SPRITE_PC; j++){
    		delete directions_[i][j];
    	}
    }
    delete general_dir_;
  }

void Character::look (Direction dir)
  {
  	if(dir != dir_){
  		change_look_ = true;
  	}
    dir_ = dir;
  }

void Character::attack()
	{
		attacking_ = true;
	}


void Character::display_attack (sf::RenderTarget &rt, float elapsed_time, bool is_playable)
	{
		
		attacks_[dir_][step_atk_]->SetPosition(x_, y_);
		rt.Draw(*(attacks_[dir_][step_atk_] ));
		
		if(elapsed_time > 1.0 / ATK_SPEED)
		{
			step_atk_++;
		}	
		
		if(is_playable)
		{
			if(step_atk_ == ATK_AMNT_SPRITE_PC)
			{
				step_atk_ = 0;
				attacking_ = false;
			}
		}
		else
		{
			if(step_atk_ == ATK_AMNT_SPRITE_NPC)
			{
				
				step_atk_ = 0;
				attacking_ = false;
			}
	}
	}
	
void Character::display (sf::RenderTarget &rt, float elapsed_time, bool is_playable)
	{
		if(!attacking_)
		{

			directions_[dir_][step_mov_]->SetPosition(x_, y_);
			
			rt.Draw(*( directions_[dir_][step_mov_] ));
		}
		else
		{
			display_attack(rt, elapsed_time, is_playable);
		}
	}

bool Character::isLooking (Direction dir)
	{
		return dir == dir_;
	}

bool Character::isAlive ()
	{
		return health_ > 0;
	}

bool Character::isAttacking ()
	{
		return attacking_;
	}

int Character::getX ()
	{
		return x_;
	}

int Character::getY ()
	{
		return y_;
	}
  
Direction Character::getDir()
	{
		return dir_;
	}

void Character::setPosition (int x, int y)
	{
		x_ = x;
		y_ = y;
	}








