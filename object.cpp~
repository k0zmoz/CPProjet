#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "object.hpp"


using namespace sf;
using namespace std;

Object::Object ()
  {
    dir_ = Down;
    x_ = 150;
    y_ = 150;
  	health_ = 0;
  }

Object::~Object()
  {
  }
  
void Character::look (Direction dir)
  {
  	if(dir != dir_){
  		change_look_ = true;
  	}
    dir_ = dir;
  }
  
bool Character::isLooking (Direction dir)
	{
		return dir == dir_;
	}

bool Character::isAlive ()
	{
		return health_ > 0;
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


