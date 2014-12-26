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
	
	int array_size = MAP_W * MAP_H; // define the size of character array (502x500)
	array_ = new char[array_size]; // allocating an array 
	int position = 0; //this will be used incremently to fill characters in the array 
	int ligne = 0, colonne = 0;
  
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
			fin.get(array_[position]); //reading one character from file to array_
			position++;
		}

		array_[position - 1] = '\0'; //placing character array terminating character
    
	cout << "Displaying Array..." << endl << endl;
	//ofstream fichier ("test.txt", ios::out);

	//this loop display all the charaters in array_ till \0 
		for(int i = 0; array_[i] != '\0'; i++)
		{			
			switch (array_[i])
			{
			//	int ligne, colonne;
				
				case '@' : 
          ligne = i / MAP_H;
					colonne = i %MAP_W;
					cout << "i = " << i << "col = "<< colonne << "ligne = "<< ligne<< endl;
			

					map1_->SetPosition(-(colonne * TILE_W), -(ligne * TILE_H));
					walled_ = false;
					pos_ = i;
         break;
				case '1' : 
					walled_ = false;
					break;
				case '0' : 					
					walled_ = true;
					break;
				case '2' : 					
					walled_ = true;
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

int Map::isWall (int array_)
{
	if(walled_ == true)
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
    switch (dir)
    {
		  case Up:
				if(scan(array_, pos_ - MAP_W) == 0)
				{
					cout << "murUp\n";
					break;
				}
				pos_ -= MAP_W; // deplacement tableau
				pos_y_ -= TILE_H; // deplacement camera
		
				ligne = pos_ / MAP_H;
				colonne = pos_ % MAP_W;
		
				cout << "ligne:" << ligne << "\n colonne" << colonne << "\n";
				cout << "pos = " << pos_ << endl;  
		  	break;
		  
		  case Down:
				if(scan(array_, pos_ + MAP_W) == 0)
				{
					cout << "murDown\n";
					break;
				}
				pos_ += MAP_W;
				pos_y_ += TILE_H;
			
				ligne = pos_ / MAP_H;
				colonne = pos_ % MAP_W;
			
				cout << "ligne:" << ligne << "\n colonne" << colonne << "\n";
				cout << "pos = " << pos_ << endl;
		    break;
		    
		  case Left:
				if(scan(array_, pos_ - 1) == 0)
				{
					cout << "murLeft\n";
					break;
				}	
		 		pos_ -= 1;
		  	pos_x_ -= TILE_W;
				ligne = pos_ / MAP_H;
				colonne = pos_ % MAP_W;
			
				cout << "ligne:" << ligne << "\n colonne" << colonne << "\n";
		  	cout << "pos = " << pos_ << endl;
		    break;
		  
		  case Right:
				if(scan(array_, pos_ + 1) == 0)
				{
					cout << "murRight\n";
					break;
				}
		 		pos_ += 1;
		  	pos_x_ += TILE_W;
		
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
		cout << "j: " << j;
		for(i = 0; i < DOOR_W; i++)
		{
			cout << " i: " << i;
			if(open)
			{
				cout << " open -> "<< "pos: " << pos << endl;
				array_[pos] = 1;
			}
			else
			{
				cout << " close -> "<< "pos: " << pos << endl;
				array_[pos] = 2;
			}
			pos++;
		}
		pos += (MAP_W - DOOR_W);
	}
}
