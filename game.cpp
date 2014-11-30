#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "game.hpp"
#include "character.hpp"

using namespace sf;
using namespace std;

Game::Game ()
{
  win_ = new sf::RenderWindow(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "VeliTech", Style::Resize|Style::Close);
  clk_ = new Clock();
  hero_ = new Playable_Char ();
  trash_mob_ = new Npc (250, 250);
}

Game::~Game ()
{
  delete win_;
  delete clk_;
  delete hero_;
  delete trash_mob_;
}

void
Game::run ()
{
	Event event;
	Color white(255, 255, 255);
	float elapsed_time;


	while (win_->IsOpened())
	{
		win_->SetFramerateLimit(30);
		while (win_->GetEvent(event))
		{
			const sf::Input &input = win_->GetInput();
			switch (event.Type)
			{
			
				//Gestion de l'attaque et l'esquive meme si un déplacement est en cours
				if(input.IsKeyDown(Key::Z) || input.IsKeyDown(Key::Q) ||
				input.IsKeyDown(Key::S) || input.IsKeyDown(Key::D))
				{
					if(!hero_->isAttacking())
					{
						switch(event.Key.Code)
						{
							case Key::LShift:
								hero_->escape(hero_->getDir());
								break;
							case Key::Escape:
								hero_->attack();
								break;
							case Key::Y:
								break;
							default: break;
						}
					}
				}
				
						
				case sf::Event::Closed:
					win_->Close();
					break;
				case sf::Event::MouseMoved:
					break;
				case sf::Event::MouseButtonPressed:
					break;
				case Event::KeyPressed :					
			
					if(!hero_->isAttacking())
					{
			
							if(event.Key.Code == Key::Space)
							{
								hero_->attack();
							}
					
							if(event.Key.Code == Key::LShift)
							{
								hero_->escape(hero_->getDir());
							}
			
							if(event.Key.Code == Key::Z)
							{
						
								hero_->look(Up);
								hero_->move(Up);
								trash_mob_->look(Up);
								
							}
							if(event.Key.Code == Key::Q)
							{
								hero_->look(Left);
								hero_->move(Left);
								
								trash_mob_->look(Left);
							}
							if(event.Key.Code == Key::S)
							{
								hero_->look(Down);
								hero_->move(Down);
								
								trash_mob_->look(Down);
							}
					
							if(event.Key.Code == Key::D)
							{
								hero_->look(Right);
								hero_->move(Right);
								
								trash_mob_->look(Right);
							}
					}
					break;
			
				default: break;		
			}
		
		}

	win_->Clear(white);
	
	elapsed_time = clk_->GetElapsedTime();
	hero_->display(*win_, elapsed_time, true);
	trash_mob_->display(*win_, elapsed_time, false);

	if(elapsed_time > 1.0 / ATK_SPEED)
	{
		clk_->Reset();
	}
	
	win_->Display();
  }


}
