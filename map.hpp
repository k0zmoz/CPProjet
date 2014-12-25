#ifndef MINIPAINT_HPP
#define MINIPAINT_HPP

#include <list>
#include <SFML/Graphics.hpp>

#include "main.hpp"

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
void movePos (Direction dir);
int getPosX ();
int getPosY ();
int getPos();
int isWall (int);
int scan(char *,int);

private:
  
  Sprite *map1_;
	Image *imap_;
	int w_ = 500, h_ = 502;
 	int pos_x_ = 0, pos_y_ = 0, pos_;
 	//char **walled_;
 	bool walled;
 	char * array_;
	//std::list<std::pair<int, int>> walls_;
	View *view_;
	
};

#endif // MINIPAINT_HPP
