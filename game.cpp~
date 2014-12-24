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
  clk_atk_ = new Clock();
  hero_ = new Playable_Char ();
  trash_mob_ = new Npc (159, 83, false);
 	//arr_ = new Arrow (Up, 350, 350);
  //cryst_ = new Crystal(Fire, 250, 350);
  //miniboss_ = new Npc(350, 250, true);
  //duneyrr_ = new Boss();
  map_ = new Map();
	//musique_ = new Musique();
	menu_start_ = new Menu(Start);
	menu_echap_ = new Menu(Echap);
	/*menu_end_ = new Menu(End);
*/
	gs_ = Start;
	current_action_ = NoAction;
}

Game::~Game ()
{
  delete win_;
  delete clk_atk_;
  delete hero_;
  delete trash_mob_;
 //	delete arr_;
 // delete cryst_;
 // delete miniboss_;
  //delete duneyrr_;
 	delete map_;
 // delete musique_;
 delete menu_start_;
 delete menu_echap_;
 /*delete menu_end_;
*/
}

void
Game::run ()
{
	Event event;
	Color white(255, 255, 255);
	float elapsed_time_atk = 0;

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
					if (current_action_ == NoAction || current_action_ == Pause)
					{
						if(gs_ == Start)
						{
							menu_start_->setCurrentButton(input.GetMouseX(), input.GetMouseY());
						}
						else if(gs_ == Echap )
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
							case NewGame: // NewGame et pas Play ici
							  current_action_ = Play;
							  break;
							case Exit:
							 current_action_ = Exit;
							  break;
							default: break;
							}
						}
					}
					else if(gs_ == Echap)
					{
						switch (menu_echap_->getAction())
						{
							case Resume:
								current_action_ = Resume;
							  break;
							case Exit2:
								current_action_ = Exit2;
								break;
							default : break;
						}
					}
					else
					{
					}
					break;
				case Event::KeyPressed :					
					
					if(event.Key.Code == Key::Escape)
					{
						current_action_ = Pause; cout << "pause selected\n";
						gs_ = Echap;
					}	
					if(!hero_->isAttacking())
					{
			
							if(event.Key.Code == Key::Space)
							{
								hero_->attack();
								//trash_mob_->attack();
								//miniboss_->attack();
								//duneyrr_->attack();
							}
					
							if(event.Key.Code == Key::LShift)
							{
								hero_->escape(hero_->getDir());
							}
			
							if(event.Key.Code == Key::Z)
							{
						
								hero_->look(Up);
								hero_->move(Up);
								//duneyrr_->look(Up);
								//duneyrr_->move(Up);
								map_->movePos(Up);
								//trash_mob_->look(Up);
								//miniboss_->look(Up);
							}
							if(event.Key.Code == Key::Q)
							{
								hero_->look(Left);
								hero_->move(Left);
								//duneyrr_->look(Left);
								//duneyrr_->move(Left);
								map_->movePos(Left);
								//trash_mob_->look(Left);
								//miniboss_->look(Left);
							}
							if(event.Key.Code == Key::S)
							{
								hero_->look(Down);
								hero_->move(Down);
								//duneyrr_->look(Down);
								//duneyrr_->move(Down);
								map_->movePos(Down);
								//trash_mob_->look(Down);
								//miniboss_->look(Down);
								
							}
					
							if(event.Key.Code == Key::D)
							{
								hero_->look(Right);
								hero_->move(Right);
								//duneyrr_->look(Right);
								//duneyrr_->move(Right);
								map_->movePos(Right);
								//trash_mob_->look(Right);
								//miniboss_->look(Right);
							}
					}
					break;
			
				default: break;		
			}
		}

	win_->Clear(white);
	/*map_->display(*win_);
	hero_->setPosition(map_->getPosX(), map_->getPosY());
*/
	if(current_action_ == NoAction)
	{ 
		menu_start_->display(win_, gs_);
	}

	else if(current_action_ == Play)
	{
		map_->run();
		map_->display(*win_);
		hero_->setPosition(map_->getPosX(), map_->getPosY());
		hero_->display(*win_, true);
		trash_mob_->display(*win_, false);
		win_->SetView(map_->getView());
	}
	
	else if(current_action_ == Exit || current_action_ == Exit2)
	{  
		win_->Close();
	}

	else if(current_action_ == Pause)
	{  
		//cout << "exit" << "\nTest";
		win_->Clear();
		win_->SetView(sf::View(sf::FloatRect(0, 0, 800, 600)));
		cout << "gs: " << gs_ << endl;
		menu_echap_->display(win_, gs_);
		
	}
	
	else if(current_action_ == Resume)
	{  
		map_->display(*win_);
		hero_->setPosition(map_->getPosX(), map_->getPosY());
		hero_->display(*win_, true);
		//trash_mob_->display(*win_, false);
		win_->SetView(map_->getView());
	}
	
	elapsed_time_atk = clk_atk_->GetElapsedTime();
	

//	hero_->display(*win_, true);
//	trash_mob_->display(*win_, false);
	//miniboss_->display(*win_, elapsed_time_atk, false);
	/*if(duneyrr_->isAlive())
	{
		duneyrr_->display(*win_, false);
	}
	else
	{
		duneyrr_->displayDeath(*win_);
	}*/
	//arr_->display(*win_);
	//cryst_->display(*win_);

	win_->Display();
  }


}
