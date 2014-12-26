#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "object.hpp"


using namespace sf;
using namespace std;

Object::Object ()
  {
    dir_ = Down;
    x_ = INIT_X_OBJ;
    y_ = INIT_Y_OBJ;
  	health_ = INIT_HEALTH_OBJECT;
  }

Object::~Object()
  {
  }

bool Object::isLooking (Direction dir)
	{
		return dir == dir_;
	}
	
bool Object::isAlive ()
	{
		return health_ > 0;
	}
	
int Object::getX ()
	{
		return x_;
	}
	
int Object::getY ()
	{
		return y_;
	}
 
int Object::getHealth ()
{
	return health_;
}

Direction Object::getDir()
	{
		return dir_;
	}

void Object::setPosition (int x, int y)
	{
		x_ = x;
		y_ = y;
	}

void Object::setHealth (int health)
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
