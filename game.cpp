#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "game.hpp"
#include "character.hpp"
#include "map.hpp"
#include "musique.hpp"
#include "menu.hpp"

using namespace sf;
using namespace std;

Game::Game ()
{
  win_ = new sf::RenderWindow(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "VeliTech", Style::Resize|Style::Close);

  hero_ = new PlayableChar ();
  map_ = new Map();
  cm_ = new CombatManager();
  hud_ = new Hud();

	menu_start_ = new Menu(Start);
	menu_echap_ = new Menu(Pause);
	menu_end_ = new Menu(Finish);
	
	//musique_ = new Musique();
	clk_finish_ = new Clock();
		
	gs_ = Start;
	current_action_ = NoAction;
	
	boss_door_ = false;
}

Game::~Game ()
{
  delete win_;
  
  delete hero_;
 	delete map_;
  delete cm_;
 // delete hud_;
  
	delete menu_start_;
	delete menu_echap_;
	delete menu_end_;

	// delete musique_;
	delete clk_finish_;
}

void
Game::run ()
{
	Event event;
	Color white(255, 255, 255);
	bool map_initiated = false;
//musique_->play();

	while (win_->IsOpened())
	{
		win_->SetFramerateLimit(30);
		while (win_->GetEvent(event))
		{
			const sf::Input &input = win_->GetInput();
			
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
				
			switch (event.Type)
			{
				case sf::Event::Closed:
					win_->Close();
					break;
				case sf::Event::MouseMoved:
					if (current_action_ == NoAction)
					{
						if(gs_ == Start)
						{
							menu_start_->setCurrentButton(input.GetMouseX(), input.GetMouseY());
						}
						else if(gs_ == Pause )
						{
							menu_echap_->setCurrentButton(input.GetMouseX(), input.GetMouseY());
						}
					}
					break;
				case sf::Event::MouseButtonPressed:
					if(gs_ == Start)
					{
						if (current_action_ == NoAction)
						{
							switch (menu_start_->getAction())
							{
							case Play:
							  current_action_ = Play;
							  gs_ = Run;
							  break;
							case Exit:
							 current_action_ = Exit;
							 gs_ = Quit;
							  break;
							default: break;
							}
						}
					}
					else if(gs_ == Pause)
					{
						switch (menu_echap_->getAction())
						{
							case Resume:
								current_action_ = Resume;
								gs_ = Run;
							  break;
							case ExitThroughPause:
								current_action_ = ExitThroughPause;
								gs_ = Quit;
								break;
							default : break;
						}
					}
					break;
				case Event::KeyPressed :					
					
					if(event.Key.Code == Key::Escape
					&& gs_ != Start && gs_ != Finish && gs_ != Quit)
					{
						gs_ = Pause;
					}	
					
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
								map_->movePos(Up);
							}
							if(event.Key.Code == Key::Q)
							{
								hero_->look(Left);
								hero_->move(Left);
								map_->movePos(Left);
							}
							if(event.Key.Code == Key::S)
							{
								hero_->look(Down);
								hero_->move(Down);
								map_->movePos(Down);
							}
					
							if(event.Key.Code == Key::D)
							{
								hero_->look(Right);
								hero_->move(Right);
								map_->movePos(Right);
							}
					}
					break;
			
				default: break;		
			}
		}

	win_->Clear(white);

	if(gs_ == Start)
	{
			menu_start_->display(win_, gs_);
	}
	else if(gs_ == Run)
	{
		if(!map_initiated)
		{
			map_->run();
			map_initiated = true;
		}
		
		map_->display(*win_);
		hud_->display(*win_, hero_, map_);
		hero_->setPosition(map_->getPosX(), map_->getPosY());
		hero_->display(*win_, true);
		cm_->run(hero_);
		
		if(cm_->getNpc("trash_mob")->isAlive())
		{
			cm_->getNpc("trash_mob")->display(*win_, false);
		}
		
		else
		{
			if(!boss_door_)
			{
				map_->switchDoor(true);
				boss_door_ = true;
			}
		}	
		
		if(cm_->getBoss()->isAlive())
		{
			cm_->getBoss()->display(*win_, true);
		}
		
		else
		{
			gs_ = Finish;
			clk_finish_->Reset();
		}
		cm_->displayArrowList(*win_, cm_->getList1());
		win_->SetView(map_->getView());
	}
	
	else if(gs_ == Pause)
	{
		win_->Clear();
		win_->SetView(sf::View(sf::FloatRect(0, 0, GAME_WIDTH, GAME_HEIGHT)));
		menu_echap_->display(win_, gs_);	
	}
	else if(gs_ == Finish)
	{
		win_->Clear();
		win_->SetView(sf::View(sf::FloatRect(0, 0, GAME_WIDTH, GAME_HEIGHT)));
		menu_end_->display(win_, gs_); 
		if(clk_finish_->GetElapsedTime() > DISPLAY_FINISH)
		{
			gs_ = Quit;
		}
	}
	else if(gs_ == Quit)
	{
		win_->Close();
	}
	
	/*cm_->getCrystal("mob")->display(*win_);
	cm_->getCrystal("trap1")->display(*win_);
	cm_->getCrystal("trap2")->display(*win_);
	*/

	win_->Display();
  }


}
