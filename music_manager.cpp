#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <iostream>
#include "music_manager.hpp"

using namespace sf;
using namespace std;

MusicManager::MusicManager ()
{
	menu_music_ = new sf::Music;
	general_music_ = new sf::Music;
	miniboss_music_ = new sf::Music;
	boss_music_ = new sf::Music;
	ending_music_ = new sf::Music;
	game_over_music_ = new sf::Music;
	
	if (!menu_music_->OpenFromFile("./Audio/Musics/licorne.ogg"))
	{
    cerr << "Error Loading menu_music" << endl;
		exit(EXIT_FAILURE);
	}
	
	if (!general_music_->OpenFromFile("./Audio/Musics/TheForestAwakes.ogg"))
	{
    cerr << "Error Loading general_music" << endl;
		exit(EXIT_FAILURE);
	}
	
	if (!miniboss_music_->OpenFromFile("./Audio/Musics/dks_gwyn.ogg"))
	{
    cerr << "Error Loading boss_music" << endl;
		exit(EXIT_FAILURE);
	}
	
	if (!boss_music_->OpenFromFile("./Audio/Musics/demon_souls.ogg"))
	{
    cerr << "Error Loading boss_music" << endl;
		exit(EXIT_FAILURE);
	}
	
	if (!ending_music_->OpenFromFile("./Audio/Musics/still_alive.ogg"))
	{
    cerr << "Error Loading ending music" << endl;
		exit(EXIT_FAILURE);
	}
	
	if (!game_over_music_->OpenFromFile("./Audio/Musics/nevermore.ogg"))
	{
    cerr << "Error Loading ending music" << endl;
		exit(EXIT_FAILURE);
	}
	
	menu_music_->SetVolume(50);
	general_music_->SetVolume(50);
	miniboss_music_->SetVolume(50);
	boss_music_->SetVolume(50);
	ending_music_->SetVolume(50);
	game_over_music_->SetVolume(100);
}

MusicManager::~MusicManager ()
{
	delete menu_music_;
	delete general_music_;
	delete boss_music_;
	delete ending_music_;
	delete game_over_music_;
}


void MusicManager::run (GameState gs, bool miniboss_alive, bool door_opened)
{
	switch(gs)
	{
		case Start:
			if(game_over_music_->GetStatus() == 2)
			{
				game_over_music_->Stop();
			}
			if(menu_music_->GetStatus() != 2) //Playing <=> GetStatus = 2
			{
				menu_music_->Play();
			}
			break;
		case Run:
			if(menu_music_->GetStatus() == 2)
			{
				menu_music_->Stop();
			}
			if(general_music_->GetStatus() != 2)
			{
				if(!door_opened && general_music_->GetStatus() != 1)
				{
					general_music_->Play();
				}
				else
				{
					if(!miniboss_alive)
					{	
						if(boss_music_->GetStatus() != 2)
						{
							miniboss_music_->Stop();
							boss_music_->Play();
						}
					}
				}
			}
				
			if(general_music_->GetStatus() == 2 && door_opened)
			{
				if(miniboss_alive)
				{
					general_music_->Stop();
					miniboss_music_->Play();
				}
				else
				{
					miniboss_music_->Stop();
					boss_music_->Play();
				}
			}
			
			if(general_music_->GetStatus() == 1)
			{
				general_music_->Play();
			}
			else if(miniboss_music_->GetStatus() == 1)
			{
				miniboss_music_->Play();
			}
			else if(boss_music_->GetStatus() == 1)
			{
				boss_music_->Play();
			}
			
			break;
		
		case Pause:
			if(general_music_->GetStatus() == 2)
			{
				general_music_->Pause();
			}
			else if (miniboss_music_->GetStatus() == 2)
			{
				miniboss_music_->Pause();
			}
			else if (boss_music_->GetStatus() == 2)
			{
				boss_music_->Pause();
			}
			
			if(menu_music_->GetStatus() != 2)
			{
				menu_music_->Play();
			}
			break;
		
		case Finish:
		
			if(boss_music_->GetStatus() == 2)
			{
				boss_music_->Stop();
			}
			if(ending_music_->GetStatus() != 2)
			{
				ending_music_->Play();
			}
				
			break;
		
		case GameOver:
			
			if(menu_music_->GetStatus() == 2)
			{
				menu_music_->Stop();
			}
			
			if(general_music_->GetStatus() == 2)
			{
				general_music_->Stop();
			}
			if(miniboss_music_->GetStatus() == 2)
			{
				miniboss_music_->Stop();
			}
			if(boss_music_->GetStatus() == 2)
			{
				boss_music_->Stop();
			}
			if(game_over_music_->GetStatus() != 2)
			{
				game_over_music_->Play();
			}	
			break;
			
		case Quit:
			if(ending_music_->GetStatus() == 2)
			{
				ending_music_->Stop();
			}
			else if(menu_music_->GetStatus() == 2)
			{
				menu_music_->Stop();
			}
			else if(game_over_music_->GetStatus() == 2)
			{
				game_over_music_->Stop();
			}
		break;
		
		default : break;
	}
}
			

sf::Music * MusicManager::getMusic(std::string epithet)
{
	if(epithet == "menu")
	{
		return menu_music_;
	}
	else if(epithet == "general")
	{
		return general_music_;
	}
	else if(epithet == "boss")
	{
		return boss_music_;
	}
	else if(epithet == "ending")
	{
		return ending_music_;
	}
	else
	{
		cerr << "Error epithet getMusic" << endl;
		exit(EXIT_FAILURE);
	}
}
