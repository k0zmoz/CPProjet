#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "object.hpp"
#include "crystal.hpp"


Crystal::Crystal (CrystalAttribute cryst_att)
{
	crystal_img_ = new sf::Image;
	
	
	//instanciation des sprites de déplacement
  
	if(! crystal_img_->LoadFromFile("./sprite/items/crystal.png"))
	{
		std::cerr << "Error Loading Walk Image" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	crystal_sprite_ = new sf::Sprite(*crystal_img_);
	
	switch(cryst_att)
	{
		case Fire :
			crystal_sprite_->SetSubRect(sf::IntRect(
			FIRE_CRYSTAL_LEFT_COORD, FIRE_CRYSTAL_TOP_COORD,
			FIRE_CRYSTAL_RIGHT_COORD, FIRE_CRYSTAL_BOTTOM_COORD));
			
			/*crystal_sprite_->Resize(
			(FIRE_CRYSTAL_RIGHT_COORD - FIRE_CRYSTAL_LEFT_COORD) * SCALE_RESIZE_FIRE_CRYSTAL,
			(FIRE_CRYSTAL_TOP_COORD - FIRE_CRYSTAL_BOTTOM_COORD) * SCALE_RESIZE_FIRE_CRYSTAL);*/
		break;
		
		case Water :
			crystal_sprite_->SetSubRect(sf::IntRect(
			WATER_CRYSTAL_LEFT_COORD, WATER_CRYSTAL_TOP_COORD,
			WATER_CRYSTAL_RIGHT_COORD, WATER_CRYSTAL_BOTTOM_COORD));
			
			/*crystal_sprite_->Resize(
			(WATER_CRYSTAL_RIGHT_COORD - WATER_CRYSTAL_LEFT_COORD) * SCALE_RESIZE_WATER_CRYSTAL,
			(WATER_CRYSTAL_TOP_COORD - WATER_CRYSTAL_BOTTOM_COORD) * SCALE_RESIZE_WATER_CRYSTAL);*/
		break;		
			
		
		default : break;
	}
	
	health_ = CRYSTAL_HEALTH;
	invincible_ = false;
	
}

Crystal::Crystal (CrystalAttribute cryst_att, int x, int y)
{
	crystal_img_ = new sf::Image;
	
	
	//instanciation des sprites de déplacement
  
	if(! crystal_img_->LoadFromFile("./sprite/items/crystal.png"))
	{
		std::cerr << "Error Loading Walk Image" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	crystal_sprite_ = new sf::Sprite(*crystal_img_);
	
	switch(cryst_att)
	{
		case Fire :
			crystal_sprite_->SetSubRect(sf::IntRect(
			FIRE_CRYSTAL_LEFT_COORD, FIRE_CRYSTAL_TOP_COORD,
			FIRE_CRYSTAL_RIGHT_COORD, FIRE_CRYSTAL_BOTTOM_COORD));
		break;
		
		case Water :
			crystal_sprite_->SetSubRect(sf::IntRect(
			WATER_CRYSTAL_LEFT_COORD, WATER_CRYSTAL_TOP_COORD,
			WATER_CRYSTAL_RIGHT_COORD, WATER_CRYSTAL_BOTTOM_COORD));
		break;		
			
		
		default : break;
	}
	
	health_ = CRYSTAL_HEALTH;
	x_ = x;
	y_ = y;
	
}
	

Crystal::~Crystal ()
{
	delete crystal_sprite_;
	delete crystal_img_;
}


void Crystal::display (sf::RenderTarget &rt)
	{
		crystal_sprite_->SetPosition(x_, y_);
		rt.Draw(*crystal_sprite_);
	}
	
bool Crystal::isInvincible()
{
	return invincible_;
}
	
void Crystal::setInvincible(bool invi)
{
	invincible_ = invi;
}
