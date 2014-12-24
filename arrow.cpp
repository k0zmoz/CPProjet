#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "object.hpp"
#include "arrow.hpp"

Arrow::Arrow (Direction dir)
{
	arrow_img_ = new sf::Image;	
	
	if(! arrow_img_->LoadFromFile("./sprite/items/crystal.png"))
	{
		std::cerr << "Error Loading Walk Image" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	arrow_sprite_ = new sf::Sprite(*arrow_img_);
	
	switch(dir)
	{
		case Down :
			arrow_sprite_->SetSubRect(sf::IntRect(
			DOWN_ARROW_LEFT_COORD, DOWN_ARROW_TOP_COORD,
			DOWN_ARROW_RIGHT_COORD, DOWN_ARROW_BOTTOM_COORD));
		break;
		
		case Up :
		
			arrow_sprite_->SetSubRect(sf::IntRect(
			UP_ARROW_LEFT_COORD, UP_ARROW_TOP_COORD,
			UP_ARROW_RIGHT_COORD, UP_ARROW_BOTTOM_COORD));
		break;
		
		case Right :
		
			arrow_sprite_->SetSubRect(sf::IntRect(
			RIGHT_ARROW_LEFT_COORD, RIGHT_ARROW_TOP_COORD,
			RIGHT_ARROW_RIGHT_COORD, RIGHT_ARROW_BOTTOM_COORD));
		break;
		
		case Left :
		
			arrow_sprite_->SetSubRect(sf::IntRect(
			LEFT_ARROW_LEFT_COORD, LEFT_ARROW_TOP_COORD,
			LEFT_ARROW_RIGHT_COORD, LEFT_ARROW_BOTTOM_COORD));
		break;
		
		default : break;
	}
	
	dist_traveled_ = 0;
	dir_ = dir;
	
}

Arrow::Arrow (Direction dir, int x, int y)
{
	arrow_img_ = new sf::Image;
	
	
	//instanciation des sprites de déplacement
  
	if(! arrow_img_->LoadFromFile("./sprite/items/crystal.png"))
	{
		std::cerr << "Error Loading Walk Image" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	arrow_sprite_ = new sf::Sprite(*arrow_img_);
	
	switch(dir)
	{
		case Down :
			arrow_sprite_->SetSubRect(sf::IntRect(
			DOWN_ARROW_LEFT_COORD, DOWN_ARROW_TOP_COORD,
			DOWN_ARROW_RIGHT_COORD, DOWN_ARROW_BOTTOM_COORD));
		break;
		
		case Up :
		
			arrow_sprite_->SetSubRect(sf::IntRect(
			UP_ARROW_LEFT_COORD, UP_ARROW_TOP_COORD,
			UP_ARROW_RIGHT_COORD, UP_ARROW_BOTTOM_COORD));
		break;
		
		case Right :
		
			arrow_sprite_->SetSubRect(sf::IntRect(
			RIGHT_ARROW_LEFT_COORD, RIGHT_ARROW_TOP_COORD,
			RIGHT_ARROW_RIGHT_COORD, RIGHT_ARROW_BOTTOM_COORD));
		break;
		
		case Left :
		
			arrow_sprite_->SetSubRect(sf::IntRect(
			LEFT_ARROW_LEFT_COORD, LEFT_ARROW_TOP_COORD,
			LEFT_ARROW_RIGHT_COORD, LEFT_ARROW_BOTTOM_COORD));
		break;
		
		default : break;
	}
	
	
	dist_traveled_ = 0;
	dir_ = dir;
		
	x_ = x;
	y_ = y;

}
	

Arrow::~Arrow ()
{
	delete arrow_sprite_;
	delete arrow_img_;
}

void Arrow::move (Direction dir)
	{
		switch (dir) {
			case Up:
			  y_ -= ARROW_SPEED;
			  break;
			case Down:
			  y_ += ARROW_SPEED;
			  break;
			case Left:
			  x_ -= ARROW_SPEED;
			  break;
			case Right:
			  x_ += ARROW_SPEED;
			  break;
		}

	dist_traveled_ += ARROW_SPEED;

	}


void Arrow::display (sf::RenderTarget &rt)
	{
		arrow_sprite_->SetPosition(x_, y_);
		rt.Draw(*arrow_sprite_);
	}
	
int getDistTraveled()
{
	return dist_traveled_;
}
