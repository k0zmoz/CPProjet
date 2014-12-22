#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "character.hpp"
#include "boss.hpp"


using namespace sf;
using namespace std;

Boss::Boss () : Character ()
	{
		int i, j;
  
		general_dir_ = new sf::Image;
		general_atks_ = new sf::Image;
		general_deaths_ = new sf::Image;
			  
		if(! general_dir_->LoadFromFile("./sprite/boss/Duneyrr_walking.png")){
			cerr << "Error Loading boss walk Image" << endl;
			exit(EXIT_FAILURE);
		}
	
		//instanciation des sprites de déplacement
		directions_[Down] = down_dir_;
		directions_[Up] = up_dir_;
		directions_[Right] = right_dir_;
		directions_[Left] = left_dir_;
	
		for( i = 0; i < 4; i++){		//4 directions
			for(j = 0; j < MOV_AMNT_SPRITE_BOSS; j++){
				directions_[i][j] = new sf::Sprite(*general_dir_);
				if(i < 2)
				{
					if(i == 0)
					{
						directions_[i][j]->SetSubRect(sf::IntRect(
						OFFSET_IMG_W + j * (MOV_DOWN_LEFT_BOSS_W),
						OFFSET_IMG_H + (i % 2) * (MOV_DOWN_LEFT_BOSS_H + MOV_DIFF_BOSS_H),
						OFFSET_IMG_W + j * (MOV_DOWN_LEFT_BOSS_W) + MOV_DOWN_LEFT_BOSS_W,
						OFFSET_IMG_H + (i % 2) * (MOV_DOWN_LEFT_BOSS_H + MOV_DIFF_BOSS_H) + MOV_DOWN_LEFT_BOSS_H));
					}
					else
					{
						directions_[i][j]->SetSubRect(sf::IntRect(
						OFFSET_MOV_BOSS_W + j * (MOV_UP_RIGHT_BOSS_W + MOV_DIFF_BOSS_W),
						OFFSET_IMG_H + (i % 2) * (MOV_UP_RIGHT_BOSS_H),
						OFFSET_MOV_BOSS_W + j * (MOV_UP_RIGHT_BOSS_W + MOV_DIFF_BOSS_W) + MOV_UP_RIGHT_BOSS_W,
						OFFSET_IMG_H + (i % 2) * (MOV_UP_RIGHT_BOSS_H) + MOV_UP_RIGHT_BOSS_H));
					}
				}
				else
				{
					*(directions_[i][j]) = copyandflipSprite(directions_[i - 2][j]);
				}
			}
		}
		
		if(! general_atks_->LoadFromFile("./sprite/boss/Duneyrr_atking2.png")){
			cerr << "Error Loading boss walk Image" << endl;
			exit(EXIT_FAILURE);
		}
		
		//instanciation des sprites d'attaques
	
		attacks_[Down] = down_attacks_;
		attacks_[Up] = up_attacks_;
		attacks_[Right] = right_attacks_;
		attacks_[Left] = left_attacks_;
	
		for( i = 0; i < 4; i++){		//4 directions
			for(j = 0; j < ATK_AMNT_SPRITE_BOSS; j++){
				attacks_[i][j] = new sf::Sprite(*general_atks_);
				if(i < 2)
				{
					if(i == 0)
					{
						if(j < 4) //Condition due aux propriétés de l'image du seul boss actuel du jeu
						{
							attacks_[i][j]->SetSubRect(sf::IntRect(
							OFFSET_IMG_W + j * (ATK_DOWN_LEFT_BOSS_W),
							OFFSET_IMG_H + (i % 2) * (ATK_DOWN_LEFT_BOSS_H + ATK_DIFF_BOSS_H),
							OFFSET_IMG_W + j * (ATK_DOWN_LEFT_BOSS_W) + ATK_DOWN_LEFT_BOSS_W,
							OFFSET_IMG_H + (i % 2) * (ATK_DOWN_LEFT_BOSS_H + ATK_DIFF_BOSS_H) + ATK_DOWN_LEFT_BOSS_H));
						}
						else
						{
							attacks_[i][j]->SetSubRect(sf::IntRect(
							OFFSET_IMG_W + j * (ATK_DOWN_LEFT_BOSS_W)
							+ (j % 4) * (ATK_XL_DOWN_LEFT_BOSS_W - ATK_DOWN_LEFT_BOSS_W),
							
							OFFSET_IMG_H + (i % 2) * (ATK_DOWN_LEFT_BOSS_H + ATK_DIFF_BOSS_H),
							
							OFFSET_IMG_W + j * (ATK_DOWN_LEFT_BOSS_W) 
							+ (j % 4) * (ATK_XL_DOWN_LEFT_BOSS_W - ATK_DOWN_LEFT_BOSS_W) + ATK_XL_DOWN_LEFT_BOSS_W,
							
							OFFSET_IMG_H + (i % 2) * (ATK_DOWN_LEFT_BOSS_H + ATK_DIFF_BOSS_H) + ATK_DOWN_LEFT_BOSS_H));
						}
					}
					else
					{
						if(j != 4) //Condition due aux propriétés de l'image du seul boss actuel du jeu
						{
						attacks_[i][j]->SetSubRect(sf::IntRect(
						OFFSET_ATK_BOSS_W + j * (ATK_UP_RIGHT_BOSS_W)
						+ (j / 4) * (ATK_XL_UP_RIGHT_BOSS_W - ATK_UP_RIGHT_BOSS_W),
						
						OFFSET_IMG_H + (i % 2) * (ATK_DOWN_LEFT_BOSS_H + ATK_DIFF_BOSS_H),
						
						OFFSET_ATK_BOSS_W + j * (ATK_UP_RIGHT_BOSS_W)
						+ (j / 4) * (ATK_XL_UP_RIGHT_BOSS_W - ATK_UP_RIGHT_BOSS_W) + ATK_UP_RIGHT_BOSS_W,
						
						OFFSET_IMG_H + (i % 2) * (ATK_DOWN_LEFT_BOSS_H + ATK_DIFF_BOSS_H) + ATK_UP_RIGHT_BOSS_H));
						}
						else
						{
						attacks_[i][j]->SetSubRect(sf::IntRect(
						OFFSET_ATK_BOSS_W + j * (ATK_UP_RIGHT_BOSS_W),
						OFFSET_IMG_H + (i % 2) * (ATK_DOWN_LEFT_BOSS_H + ATK_DIFF_BOSS_H),
						OFFSET_ATK_BOSS_W + j * (ATK_UP_RIGHT_BOSS_W) + ATK_XL_UP_RIGHT_BOSS_W,
						OFFSET_IMG_H + (i % 2) * (ATK_DOWN_LEFT_BOSS_H + ATK_DIFF_BOSS_H) + ATK_UP_RIGHT_BOSS_H));
						}
					}
				}
				else
				{
					*(attacks_[i][j]) = copyandflipSprite(attacks_[i - 2][j]);
				}
			}
		}
		
		if(! general_deaths_->LoadFromFile("./sprite/boss/Duneyrr_dying2.png")){
			cerr << "Error Loading boss walk Image" << endl;
			exit(EXIT_FAILURE);
		}
		
		//instanciation des sprites de mort
	
		deaths_[Down] = down_deaths_;
		deaths_[Up] = up_deaths_;
		deaths_[Right] = right_deaths_;
		deaths_[Left] = left_deaths_;
	
		for( i = 0; i < 4; i++){		//4 directions
			for(j = 0; j < DEATH_AMNT_SPRITE_BOSS; j++){
				deaths_[i][j] = new sf::Sprite(*general_deaths_);
				if(i < 2)
				{
					if(i == 0)
					{
						deaths_[i][j]->SetSubRect(sf::IntRect(
						OFFSET_DEATH_BOSS_W + j * (DEATH_DOWN_LEFT_BOSS_W),
						OFFSET_IMG_H + (i % 2) * (DEATH_DOWN_LEFT_BOSS_H + DEATH_DIFF_BOSS_H),
						OFFSET_DEATH_BOSS_W + j * (DEATH_DOWN_LEFT_BOSS_W) + DEATH_DOWN_LEFT_BOSS_W,
						OFFSET_IMG_H + (i % 2) * (DEATH_DOWN_LEFT_BOSS_H + DEATH_DIFF_BOSS_H) + DEATH_DOWN_LEFT_BOSS_H));
					}
					else
					{
						deaths_[i][j]->SetSubRect(sf::IntRect(
						OFFSET_DEATH_BOSS_W + j * (DEATH_UP_RIGHT_BOSS_W),
						OFFSET_IMG_H + (i % 2) * (DEATH_UP_RIGHT_BOSS_H + DEATH_DIFF_BOSS_H),
						OFFSET_DEATH_BOSS_W + j * (DEATH_UP_RIGHT_BOSS_W) + DEATH_UP_RIGHT_BOSS_W,
						OFFSET_IMG_H + (i % 2) * (DEATH_UP_RIGHT_BOSS_H + DEATH_DIFF_BOSS_H) + DEATH_UP_RIGHT_BOSS_H));
					}
				}
				else
				{
					*(deaths_[i][j]) = copyandflipSprite(deaths_[i - 2][j]);
				}
			}
		}
		
		health_ = HEALTH_BOSS;
		x_ =  SPAWN_BOSS_X;
		y_ =  SPAWN_BOSS_Y;
		step_death_ = 0;
		clk_death_ = new Clock();
	}

	
Boss::~Boss ()
{
	for(int i = 0; i < MOV_AMNT_SPRITE_BOSS; i++)
	{
		delete up_dir_[i];
		delete down_dir_[i];
		delete left_dir_[i];
		delete right_dir_[i];
	}

	for(int i = 0; i < ATK_AMNT_SPRITE_BOSS; i++)
	{
		delete up_attacks_[i];
		delete down_attacks_[i];
		delete left_attacks_[i];
		delete right_attacks_[i];
	}
	
	for(int i = 0; i < DEATH_AMNT_SPRITE_BOSS; i++)
	{
		delete up_deaths_[i];
		delete down_deaths_[i];
		delete left_deaths_[i];
		delete right_deaths_[i];
	}

	delete general_deaths_;
	delete clk_death_;
	
}


void Boss::move (Direction dir)
{
	switch (dir) {
		case Up:
		  y_ -= BOSS_SPEED;
		  break;
		case Down:
		  y_ += BOSS_SPEED;
		  break;
		case Left:
		  x_ -= BOSS_SPEED;
		  break;
		case Right:
		  x_ += BOSS_SPEED;
		  break;
	}

	step_mov_++;
	if(step_mov_ == MOV_AMNT_SPRITE_BOSS || change_look_ == true)
	{
		step_mov_ = 0;
		change_look_ = false;
	}

}
	
	
Sprite Boss::copyandflipSprite(Sprite *sp)
{
	Sprite sp_flipped = *sp;
	
	sp_flipped.FlipX(true);
	
	return sp_flipped;
}

void Boss::display_death (sf::RenderTarget &rt)
{
	float elapsed_time = clk_death_->GetElapsedTime();
	
	/*cout << step_death_ << " | ";
	cout << x_ << " | " << y_ << endl;
	*/
	deaths_[dir_][step_mov_]->SetPosition(x_, y_);
	rt.Draw(*( deaths_[dir_][step_death_] ));
	
	if(step_death_ < DEATH_AMNT_SPRITE_BOSS && elapsed_time > (1 / DEATH_SPEED))
	{
		step_death_++;
		clk_death_->Reset();
	}
	
	if(step_death_ == DEATH_AMNT_SPRITE_BOSS)
	{
		step_death_ = 0;
	}
}

