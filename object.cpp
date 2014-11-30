#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "object.hpp"


using namespace sf;
using namespace std;

Object::Object ()
  {
    dir_ = Down;
<<<<<<< HEAD
    x_ = 150;
    y_ = 150;
  	health_ = 0;
=======
    x_ = INIT_X_OBJ;
    y_ = INIT_Y_OBJ;
  	health_ = INIT_HEALTH_OBJECT;
>>>>>>> objects
  }

Object::~Object()
  {
  }
  
<<<<<<< HEAD
void Character::look (Direction dir)
  {
  	if(dir != dir_){
  		change_look_ = true;
  	}
    dir_ = dir;
  }
  
bool Character::isLooking (Direction dir)
=======
bool Object::isLooking (Direction dir)
>>>>>>> objects
	{
		return dir == dir_;
	}

<<<<<<< HEAD
bool Character::isAlive ()
=======
bool Object::isAlive ()
>>>>>>> objects
	{
		return health_ > 0;
	}
	
<<<<<<< HEAD
int Character::getX ()
=======
int Object::getX ()
>>>>>>> objects
	{
		return x_;
	}

<<<<<<< HEAD
int Character::getY ()
=======
int Object::getY ()
>>>>>>> objects
	{
		return y_;
	}
  
<<<<<<< HEAD
Direction Character::getDir()
=======
Direction Object::getDir()
>>>>>>> objects
	{
		return dir_;
	}

<<<<<<< HEAD
void Character::setPosition (int x, int y)
=======
void Object::setPosition (int x, int y)
>>>>>>> objects
	{
		x_ = x;
		y_ = y;
	}


