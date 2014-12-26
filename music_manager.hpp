#ifndef MUSICMANAGER_HPP
#define MUSICMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include "main.hpp"

class MusicManager
{

public:

	MusicManager();
	~MusicManager();
	
	void run(GameState gs, bool miniboss_alive, bool door_opened);

	sf::Music *getMusic(std::string epithet);

private:

	sf::RenderWindow *win_;
	sf::Music *menu_music_, *general_music_,
	*miniboss_music_, *boss_music_, *ending_music_;
  
  
};

#endif // MUSICMANAGER_HPP
