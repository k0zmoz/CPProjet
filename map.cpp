#include <list>
#include <SFML/Graphics.hpp>
#include "map.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
/*
#define TILE_W 16
#define TILE_H 16
*/
using namespace sf;
using namespace std;

Map::Map()
{
	imap_ = new sf::Image;
	map1_ = new sf::Sprite(*imap_);
    	view_ = new sf::View(sf::FloatRect(0, 0, 1, 1)); // rectangle dont le coin en haut à gauche est en (0,0), de taille 1x1
	
	int array_size = w_*h_; // define the size of character array (500x500)
	array = new char[array_size]; // allocating an array 
	int position = 0; //this will be used incremently to fill characters in the array 
	int ligne, colonne;
  
	if (!imap_->LoadFromFile("map2test.JPG")) // Si le chargement a échoué
	{
		cout<<"Erreur durant le chargement de l'image"<<endl;
		exit(EXIT_FAILURE); // On ferme le programme
	}

	map1_->SetSubRect(IntRect(0, 0, 8000, 8000));
   
	ifstream fin("carte23.txt");
 	if(fin.is_open())
	{
		while(!fin.eof() && position < array_size)
		{
			fin.get(array[position]); //reading one character from file to array
			position++;
		}
		array[position-1] = '\0'; //placing character array terminating character

		//this loop display all the charaters in array till \0 
		for(int i = 0; array[i] != '\0'; i++)
		{			
			switch (array[i])
			{
				case '@' : 
          				ligne = i / 500;
					colonne = i %502;
					cout << "i = " << i << "col = "<< colonne << "lign = "<< ligne<< endl;
					map1_->SetPosition(-(colonne*16),-(ligne*16));
					walled = false;
					pos_ = i;
          				break;
				case '1' : 
					walled = false;
					break;
				case '0' : 					
					walled = true;
					break;
				case '2' : 					
					walled = true;
					break;
				default : break;
			}
			
		}
	}
	else // Le fichier ne peut pas etre ouvert
	{
		cout << "File (.txt) could not be opened." << endl;
	}

}

Map::~Map()
{
	delete view_;
    	
	//delete imap_;
	//delete map1_;
}

void Map::run ()
{
    	view_->SetHalfSize(60 * TILE_W, 60 * TILE_H); // Zoom cadre camera
    	updateView();
}

int Map::isWall (int array)
{
	if(walled == true)
	{
		return 1;
	}
	return 0;
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

void Map::movePos (Direction dir)
{
  	int ligne, colonne;
    switch (dir) {
    
    case Up:
		if(scan(array, pos_-502) == 0) { cout << "murUp\n"; break; }
		pos_ -= 502; // deplacement tableau
    		pos_y_ -= 16; // deplacement camera
    		//view_->Move(0,-16);
		ligne = pos_ / 500;
		colonne = pos_ % 502;
		cout << "ligne:" << ligne << "\n colonne" << colonne << "\n";
    	cout << "pos = " << pos_ << endl;
    
    	break;
    case Down:
		if(scan(array, pos_+502) == 0) { cout << "murDown\n"; break; }
    		pos_ += 502;
    		pos_y_ += 16;
    		//view_->Move(0,+16);
		ligne = pos_ / 500;
		colonne = pos_ % 502;
	//	colonne = pos_ - ligne*502;
		cout << "ligne:" << ligne << "\n colonne" << colonne << "\n";
    	cout << "pos = " << pos_ << endl;

      break;
    case Left:
		if(scan(array, pos_-1) == 0) { cout << "murLeft\n"; break; }	
   		pos_ -= 1;
    		pos_x_ -= 16;
		ligne = pos_ / 500;
		colonne = pos_ % 502;
		cout << "ligne:" << ligne << "\n colonne" << colonne << "\n";
    	cout << "pos = " << pos_ << endl;
      
      break;
    case Right:
		if(scan(array, pos_+1) == 0) {cout << "murRight\n"; break; }
   		pos_ += 1;
    		pos_x_ += 16;
		ligne = pos_ / 500;
		colonne = pos_ % 502;
		cout << "ligne:" << ligne << "\n colonne" << colonne << "\n";cout << "pos = " << pos_ << endl;
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

