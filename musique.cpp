#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <iostream>
#include "main.hpp"
#include "game.hpp"
#include "musique.hpp"

using namespace sf;
using namespace std;

Musique::Musique ()
{
	musique_ = new sf::Music;
}

Musique::~Musique ()
{

}

void
Musique::play ()
{
	if (!musique_->OpenFromFile("licorne.ogg"))
	{
		// Erreur
    	cerr << "Error Loading Musique" << endl;
		exit(EXIT_FAILURE);
	}

	/*if (!Musique.OpenFromMemory(FilePtr, Size))
	{
   		// Erreur
   	   	cerr << "Error Musique already in memory" << endl;
		exit(EXIT_FAILURE);
	}*/
	
	musique_->Play();
}

void
Musique::pause ()
{
	musique_->Pause();
}

void
Musique::stop ()
{
	musique_->Stop();
}
