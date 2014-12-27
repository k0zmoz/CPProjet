#ifndef MINIPAINT_HPP
#define MINIPAINT_HPP

#include <list>
#include <SFML/Graphics.hpp>
#include "main.hpp"

#define MAP_W 502
#define MAP_H 510


#define TILE_W 16
#define TILE_H 16

#define DOOR_W 25
#define DOOR_H 25
#define LEFT_COORD_DOOR 236
#define TOP_COORD_DOOR 281
#define RIGHT_COORD_DOOR 261
#define BOTTOM_COORD_DOOR 304

using namespace sf;

class Map
{
public:

  Map();
  ~Map();

void run ();
void display(sf::RenderTarget &rt);
sf::View getView ();
void updateView ();
void movePos (Direction dir, int move_range);
int getPosX ();
int getPosY ();
int getPos();
int isWall (int);
int scan(char *,int);
void switchDoor (bool open);

private:
  
  Image *imap_;
  Sprite *map1_;
	View *view_;
	
 	int pos_x_ = 0, pos_y_ = 0, pos_;
 	char * array_;
	
	bool walled_;
	
};

#endif // MINIPAINT_HPP
