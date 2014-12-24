#ifndef ARROW_HPP
#define ARROW_HPP

//Coordonnées des sprites de flèches

//Sprite flèche vers le bas
#define DOWN_ARROW_LEFT_COORD 50
#define DOWN_ARROW_TOP_COORD 80
#define DOWN_ARROW_RIGHT_COORD 60
#define DOWN_ARROW_BOTTOM_COORD 120


//Sprite flèche vers le haut
#define UP_ARROW_LEFT_COORD 70
#define UP_ARROW_TOP_COORD 80
#define UP_ARROW_RIGHT_COORD 80
#define UP_ARROW_BOTTOM_COORD 120


//Sprite flèche vers la droite
#define RIGHT_ARROW_LEFT_COORD 90
#define RIGHT_ARROW_TOP_COORD 100
#define RIGHT_ARROW_RIGHT_COORD 130
#define RIGHT_ARROW_BOTTOM_COORD 110


//Sprite flèche vers la gauche
#define LEFT_ARROW_LEFT_COORD 140
#define LEFT_ARROW_TOP_COORD 100
#define LEFT_ARROW_RIGHT_COORD 180
#define LEFT_ARROW_BOTTOM_COORD 110


#define ARROW_SPEED 7 //deplacement d'une arrow
#define LIM_DIST_ARROW 80

#include <SFML/Graphics.hpp>
#include "main.hpp"
#include "object.hpp"


class Arrow : public Object
{
public:

	Arrow (Direction dir);
	Arrow (Direction dir, int x, int y);

	~Arrow ();

	void move(Direction dir);
	void display (sf::RenderTarget &rt);
	int getDistTraveled();


protected:

	sf::Image *arrow_img_;	
	sf::Sprite *arrow_sprite_;
	int dist_traveled_;
};

#endif // ARROW_HPP
