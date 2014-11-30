#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "main.hpp"


class Object
{
public:

	Object ();
	~Object ();
	
	void look (Direction dir);
	bool isLooking (Direction dir);
	bool isAlive ();
	int getX ();
	int getY ();
	Direction getDir ();
	void setPosition (int x, int y);

protected:

	Direction dir_;	
	int x_, y_;
	int health_;

};

#endif // OBJECT_HPP
