#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "character.hpp"


using namespace sf;
using namespace std;

Character::Character ()
  {
    dir_ = Down;
    x_ = 0;
    y_ = 0;
    change_look_ = true;
    attacking_ = false;
    step_mov_ = 0;
    step_atk_ = 0;
    clk_atk_ = new Clock();
  
  }

Character::~Character()
  {
    delete general_dir_;
   	delete general_atks_;
   	delete clk_atk_;
  }

void Character::look (Direction dir)
  {
  	if(dir != dir_){
  		change_look_ = true;
  	}
    dir_ = dir;
  }

void Character::move (Direction dir, int speed, int amnt_sprite)
{
	switch (dir)
	{
		case Up:
		  y_ -= speed;
		  break;
		case Down:
		  y_ += speed;
		  break;
		case Left:
		  x_ -= speed;
		  break;
		case Right:
		  x_ += speed;
		  break;
	}

	step_mov_++;
	if(step_mov_ == amnt_sprite || change_look_ == true)
	{
		step_mov_ = 0;
		change_look_ = false;
	}
}

void Character::attack()
	{
		attacking_ = true;
	}


void Character::display_attack (sf::RenderTarget &rt, bool is_playable)
{
	float elapsed_time = clk_atk_->GetElapsedTime();
	attacks_[dir_][step_atk_]->SetPosition(x_, y_);
	rt.Draw(*(attacks_[dir_][step_atk_] ));
	if(elapsed_time > 1.0 / ATK_SPEED)
	{
		step_atk_++;
		clk_atk_->Reset();
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
	
void Character::display (sf::RenderTarget &rt, bool is_playable)
{
	if(!attacking_)
	{

		directions_[dir_][step_mov_]->SetPosition(x_, y_);
		
		rt.Draw(*( directions_[dir_][step_mov_] ));
	}
	else
	{
		display_attack(rt, is_playable);
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
int Character::getStepMov ()
{
	return step_mov_;
}

int Character::getStepAtk ()
{
	return step_atk_;
}

int Character::getHealth ()
{
	return health_;
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
	
void Character::setHealth (int health)
{
	if(health >= 0)
	{
		health_ = health;
	}
	else
	{
		health_ = 0;
	}
}
