#ifndef ARROW_HPP
#define ARROW_HPP

<<<<<<< HEAD

//Constantes d'initialisation des sprites de déplacements
#define AMNT_SPRITE_ARROW 6 	/*nombre de sprites synthétisant
								 un objet*/

#define MOV_CHAR_W 35 //largeur d'un sprite objet par défaut
#define MOV_CHAR_H 67 //hauteur d'un sprite objet par défaut
#define MOV_DIFF_CHAR_W 15 //largeur entre deux sprites
#define MOV_DIFF_CHAR_H 35 //hauteur entre deux sprites

#define OFFSET_IMG_W 50 //offset des premiers sprites en largeur
#define OFFSET_IMG_H 10 //offset des premiers sprites en hauteur

#define MOVE_RANGE_ARROW 7 //deplacement d'une arrow
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
>>>>>>> objects


#include <SFML/Graphics.hpp>
#include "main.hpp"


class Arrow : public Object
{
public:

	Arrow (Direction dir);
<<<<<<< HEAD
=======
	Arrow (Direction dir, int x, int y);
>>>>>>> objects
	~Arrow ();

	void move(Direction dir);
	void display (sf::RenderTarget &rt);


protected:

	sf::Image *arrow_img_;
<<<<<<< HEAD
	
	sf::Sprite *arrow_sprite_;
	
=======
	sf::Sprite *arrow_sprite_;
	
	int dist_traveled_;
	
>>>>>>> objects
};

#endif // ARROW_HPP
