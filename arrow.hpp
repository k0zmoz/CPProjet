#ifndef ARROW_HPP
#define ARROW_HPP


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


#include <SFML/Graphics.hpp>
#include "main.hpp"


class Arrow : public Object
{
public:

	Arrow (Direction dir);
	~Arrow ();

	void move(Direction dir);
	void display (sf::RenderTarget &rt);


protected:

	sf::Image *arrow_img_;
	
	sf::Sprite *arrow_sprite_;
	
};

#endif // ARROW_HPP