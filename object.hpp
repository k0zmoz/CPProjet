#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "main.hpp"

#define INIT_X_OBJ 150
#define INIT_Y_OBJ 150
#define INIT_HEALTH_OBJECT 1

class Object
{
public:

	Object ();
	~Object ();

	bool isLooking (Direction dir);
	bool isAlive ();
	int getX ();
	int getY ();
	int getHealth ();
	Direction getDir ();
	void setPosition (int x, int y);
	void setHealth (int health);
protected:

	Direction dir_;	
	int x_, y_;
	int health_;

};

#endif // OBJECT_HPP
