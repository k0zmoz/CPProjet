#include <list>
#include <SFML/Graphics.hpp>
#include "map.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace sf;
using namespace std;

Map::Map()
{
	imap_ = new sf::Image;
	map1_ = new sf::Sprite(*imap_);
  view_ = new sf::View(sf::FloatRect(0, 0, 1, 1)); // rectangle dont le coin en haut à gauche est en (0,0), de taille 1x1
	
	int i = 0;
	int array_size = MAP_W * MAP_H; // define the size of character array (502x500)
	array_ = new char[array_size]; // allocating an array 
	int position = 0; //this will be used incremently to fill characters in the array 
	int ligne = 0, colonne = 0;
  
	if (!imap_->LoadFromFile("map2test.JPG")) // Si le chargement a échoué
	{
		cerr << "Could not loas map2test.JPG" << endl;
		exit(EXIT_FAILURE); // On ferme le programme
	}

	map1_->SetSubRect(IntRect(0, 0, 8000, 8000));
  
	ifstream fin("carte23.txt");
 	if(fin.is_open())
	{
		while(!fin.eof() && position < array_size)
		{
			fin.get(array_[position]); //reading one character from file to array_
			position++;
		}

		array_[position - 1] = '\0'; //placing character array terminating character
    
	cout << "Displaying Array..." << endl << endl;
	//ofstream fichier ("test.txt", ios::out);

	//this loop display all the charaters in array_ till \0 
		while(array_[i] != '\0' && array_[i] != '@')
		{			
			i++;
		}
		
		if(array_[i] == '@')
		{
			ligne = i / MAP_H;
			colonne = i % MAP_W;
			map1_->SetPosition(-(colonne * TILE_W), -(ligne * TILE_H));
			pos_ = i;
		}
		//cout << "i = " << i << "col = "<< colonne << "ligne = "<< ligne<< endl;
	}
	else // Le fichier ne peut pas etre ouvert
	{
		cerr << "Carte23.txt could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

}

Map::~Map()
{
	delete imap_;
	delete map1_;
	delete view_;
	delete array_;
}

void Map::run ()
{
	//view_ = new sf::View(sf::FloatRect(0, 0, TILE_W * w_, TILE_H * h_));
	view_->SetHalfSize(25 * TILE_W, 25 * TILE_H); // Zoom cadre camera
	updateView();
}

int Map::scan(char * tab, int pos)
{
	switch (tab[pos])
	{
		case '@' : 
			return 1;
			break;
		
		case '0' : 
			return 0;		
			break;
		
		case '1' : 					
			return 1;	
			break;
		
		case '2' : 					
			return 0;		
			break;
		
		default : break;
	}
	return -1;
}

void Map::display(sf::RenderTarget &rt)
{
	rt.Draw(*map1_);
}

sf::View Map::getView ()
{
	return *view_;
}

void Map::updateView ()
{
	int x = pos_x_;
	int y = pos_y_;  
	view_->SetCenter(x, y); // Centre la camera sur le personnage au centre de la fenetre
}

void Map::movePos (Direction dir, int mov_range)
{
  	int ligne, colonne;
    switch (dir)
    {
		  case Up:
				if(scan(array_, pos_ - (mov_range * MAP_W)) == 0)
				{
					cout << "murUp\n";
					break;
				}
				pos_ -= mov_range * MAP_W; // deplacement tableau
				pos_y_ -= mov_range * TILE_H; // deplacement camera
		
				ligne = pos_ / MAP_H;
				colonne = pos_ % MAP_W;
		
				cout << "ligne:" << ligne << "\n colonne" << colonne << "\n";
				cout << "pos = " << pos_ << endl;  
		  	break;
		  
		  case Down:
				if(scan(array_, pos_ + (mov_range * MAP_W)) == 0)
				{
					cout << "murDown\n";
					break;
				}
				pos_ += mov_range * MAP_W;
				pos_y_ += mov_range * TILE_H;
			
				ligne = pos_ / MAP_H;
				colonne = pos_ % MAP_W;
			
				cout << "ligne:" << ligne << "\n colonne" << colonne << "\n";
				cout << "pos = " << pos_ << endl;
		    break;
		    
		  case Left:
				if(scan(array_, pos_ - mov_range) == 0)
				{
					cout << "murLeft\n";
					break;
				}	
		 		pos_ -= mov_range;
		  	pos_x_ -= mov_range * TILE_W;
				ligne = pos_ / MAP_H;
				colonne = pos_ % MAP_W;
			
				cout << "ligne:" << ligne << "\n colonne" << colonne << "\n";
		  	cout << "pos = " << pos_ << endl;
		    break;
		  
		  case Right:
				if(scan(array_, pos_ + mov_range) == 0)
				{
					cout << "murRight\n";
					break;
				}
		 		pos_ += mov_range;
		  	pos_x_ += mov_range * TILE_W;
		
				ligne = pos_ / MAP_H;
				colonne = pos_ % MAP_W;
			
				cout << "ligne:" << ligne << "\n colonne" << colonne << "\n";
				cout << "pos = " << pos_ << endl;
		   	break;
		  
		  default : break;
   	}

    updateView();
}
  
int Map::getPos()
{
	return pos_;
}

int Map::getPosX ()
{
  return pos_x_;
}

int Map::getPosY ()
{
  return pos_y_;
}

void Map::switchDoor (bool open)
{
	int i, j,  pos = LEFT_COORD_DOOR + TOP_COORD_DOOR * MAP_W;
	
	for(j = 0; j < DOOR_H; j++)
	{
		for(i = 0; i < DOOR_W; i++)
		{
			if(open)
			{
				array_[pos] = 1;
			}
			else
			{
				array_[pos] = 2;
			}
			pos++;
		}
		pos += (MAP_W - DOOR_W);
	}
}
