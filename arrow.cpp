#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "object.hpp"


Arrow::Arrow (Direction dir)
{
	arrow_img = new sf::Image;
	
	
	//instanciation des sprites de déplacement
  
	if(! general_dir_->LoadFromFile("./sprite/items/crystal.png"))
	{
		cerr << "Error Loading Walk Image" << endl;
		exit(EXIT_FAILURE);
	}
		
