#ifndef MUSIQUE_HPP
#define MUSIQUE_HPP

#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>

class Musique
{
public:

	Musique();
	~Musique();

	void play ();
	void pause ();
	void stop ();

private:

	sf::RenderWindow *win_;
	sf::Music *musique_;
  
  
};

#endif // MUSIQUE_HPP
