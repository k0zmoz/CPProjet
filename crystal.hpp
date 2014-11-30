#ifndef CRYSTAL_HPP
#define CRYSTAL_HPP

#include <SFML/Graphics.hpp>
#include "main.hpp"

//Coordonnées des sprites de crystal

//Sprite fire crystal
#define FIRE_CRYSTAL_LEFT_COORD 50
#define FIRE_CRYSTAL_TOP_COORD 20
#define FIRE_CRYSTAL_RIGHT_COORD 80
#define FIRE_CRYSTAL_BOTTOM_COORD 60

//Sprite  water crystal
#define WATER_CRYSTAL_LEFT_COORD 100
#define WATER_CRYSTAL_TOP_COORD 30
#define WATER_CRYSTAL_RIGHT_COORD 120
#define WATER_CRYSTAL_BOTTOM_COORD 60

#define CRYSTAL_HEALTH 3

typedef enum { Fire = 0, Water} CrystalAttribute;

class Crystal : public Object
{
public:

	Crystal (CrystalAttribute cryst_att);
	Crystal (CrystalAttribute cryst_att, int x, int y);
	~Crystal ();

	void display (sf::RenderTarget &rt);


protected:

	sf::Image *crystal_img_;
	sf::Sprite *crystal_sprite_;
	
};

#endif // CRYSTAL_HPP
