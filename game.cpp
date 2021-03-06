#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"

using namespace sf;
using namespace std;

Game::Game ()
{
  win_ = new sf::RenderWindow(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "VeliTech", Style::Resize|Style::Close);

  hero_ = new PlayableChar ();
  map_ = new Map();
  cm_ = new CombatManager();
  mm_ = new MusicManager ();
  hud_ = new Hud();

	menu_start_ = new Menu(Start);
	menu_echap_ = new Menu(Pause);
	menu_end_ = new Menu(Finish);
	menu_go_ = new Menu(GameOver);
	menu_controls_ = new Menu(ControlPanel);

	clk_display_finish_ = new Clock();
	clk_delay_victory_ = new Clock();
	clk_door_info_ = new Clock();
	
	font_text_ = new Font();
	if(!font_text_->LoadFromFile("./Font/stnicholas.ttf"))
	{
		cerr << "Error loading font file" << endl;
		exit(EXIT_FAILURE);
	}
	door_info_ = new String("BOSS DOOR IS NOW OPEN", *font_text_, TEXT_SIZE);
		
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
  delete mm_;
  delete hud_;
  
	delete menu_start_;
	delete menu_echap_;
	delete menu_end_;
	delete menu_go_;
	delete menu_controls_;
	
	delete clk_display_finish_;
	delete clk_delay_victory_;
	delete clk_door_info_;

	delete font_text_;
	delete door_info_;
}

void
Game::run ()
{
	Event event;
	Color white(255, 255, 255);
	bool map_initiated = false, new_game = false;
	bool switch_door = true, door_opened = false;
	bool escape_disabled = false;
	GameState save_gs;


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
							
							if(hero_->getStamina() != 0 && hero_->isStaminaUsable())
							{
									hero_->escape();
									map_->movePos(hero_->getDir(), ESCAPE_RANGE);
									escape_disabled = true;
							}	
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
						if(gs_ == Start)
						{
							menu_start_->setCurrentButton(input.GetMouseX(), input.GetMouseY());
						}
					else if(gs_ == Pause )
						{
							menu_echap_->setCurrentButton(input.GetMouseX(), input.GetMouseY());
						}
					else if(gs_ == GameOver )
						{
							menu_go_->setCurrentButton(input.GetMouseX(), input.GetMouseY());
						}
					break;
				case sf::Event::MouseButtonPressed:
					if(gs_ == Start)
					{
						switch (menu_start_->getAction())
						{
						case Play:
						  current_action_ = Play;
						  gs_ = Run;
						  break;
						case Controls:
						  current_action_ = Controls;
						  save_gs = gs_;
						 	gs_ = ControlPanel;
						  break;
						case Exit:
						 current_action_ = Exit;
						 gs_ = Quit;
						  break;
						default: break;
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
							case Controls:
						  	current_action_ = Controls;
						  	 save_gs = gs_;
						  	gs_ = ControlPanel;
						  	break;
							case Exit:
								current_action_ = Exit;
								gs_ = Quit;
								break;
							default : break;
						}
					}
					else if(gs_ == GameOver)
					{
						switch (menu_go_->getAction())
						{
							case NewGame:
								current_action_ = NewGame;
								gs_ = Quit;
								new_game = true;
							  break;
							case ExitThroughGameOver:
								current_action_ = ExitThroughGameOver;
								gs_ = Quit;
								break;
							default : break;
						}
					}
					break;
				case Event::KeyPressed :					
					if(event.Key.Code == Key::Escape
					&& gs_ != Start && gs_ != Finish && gs_ != Quit && gs_ != GameOver)
					{
						if(gs_ == Run)
						{
							gs_ = Pause;
						}
						else
						{
							gs_ =  save_gs;
						}
					}
						
					if(!hero_->isAttacking())
					{
							if(event.Key.Code == Key::Space)
							{
								hero_->attack();
							}
					
							if(event.Key.Code == Key::LShift)
							{
								if(hero_->getStamina() != 0 && hero_->isStaminaUsable() && !escape_disabled)
								{
									hero_->escape();
									map_->movePos(hero_->getDir(), ESCAPE_RANGE);
								}
							}
							
							if(event.Key.Code == Key::X)
							{
								cm_->setCheatMode(!cm_->getCheatMode());
							}
							
							if(event.Key.Code == Key::Z)
							{
						
								hero_->look(Up);
								hero_->move();
								map_->movePos(Up, 1);
							}
							if(event.Key.Code == Key::Q)
							{
								hero_->look(Left);
								hero_->move();
								map_->movePos(Left, 1);
							}
							if(event.Key.Code == Key::S)
							{
								hero_->look(Down);
								hero_->move();
								map_->movePos(Down, 1);
							}
					
							if(event.Key.Code == Key::D)
							{
								hero_->look(Right);
								hero_->move();
								map_->movePos(Right, 1);
							}
					}
					break;
			
				default: break;		
			}
		}

	win_->Clear(white);

	if(gs_ == Start)
	{
		if(!new_game)
		{
			menu_start_->display(win_);
		}
		else
		{
			//reset le jeu ici
			new_game = false;
		}
	}
	else if(gs_ == Run)
	{
		if(!map_initiated)
		{
			map_->run();
			map_initiated = true;
		}
		
		if(hero_->isAlive())
		{
			win_->SetView(map_->getView());
			map_->display(*win_);
			hud_->display(*win_, hero_, map_);
			hero_->setPosition(map_->getPosX(), map_->getPosY());
			hero_->display(*win_, true);
			cm_->run(hero_);
		
			if(cm_->getNpc("trash_mob")->isAlive())
			{
				cm_->getNpc("trash_mob")->display(*win_, false);
			
				if(!cm_->getCrystal("mob")->isInvincible())
				{
					cm_->getCrystal("mob")->setInvincible(true);
				}
			}
			else
			{
				if(cm_->getCrystal("mob")->isInvincible())
				{
					cm_->getCrystal("mob")->setInvincible(false);
				}
			}
			
			if((!cm_->getNpc("miniboss")->isAlive()))
			{
				if(cm_->getBoss()->isAlive())
				{
					cm_->getBoss()->display(*win_, true);
					clk_delay_victory_->Reset();
				}
				else
				{
					if(clk_delay_victory_->GetElapsedTime() < DELAY_VICTORY)
					{
						cm_->getBoss()->displayDeath(*win_);	
					}
					else
					{
						if(clk_delay_victory_->GetElapsedTime() > 4 * DELAY_VICTORY)
						{
							gs_ = Finish;
							clk_display_finish_->Reset();
						}
					}
				}
			}
			else
			{
				cm_->getNpc("miniboss")->display(*win_, false);
			}
	
			cm_->displayAllArrowList(*win_);
			cm_->displayCrystalList(*win_, cm_->getCrystalList());

			for(auto cryst : cm_->getCrystalList())
			{
				switch_door = switch_door && (!cryst->isAlive());
			}
		
			if(!door_opened && switch_door == true)
			{
				map_->switchDoor(switch_door);
				clk_door_info_->Reset();
				door_opened = true;
			}
			
			if(door_opened && clk_door_info_->GetElapsedTime() < DISPLAY_DOOR_INFO)
			{
				door_info_->SetPosition(map_->getPosX() - OFFSET_TEXT, map_->getPosY());
				door_info_->SetColor(Color(255, 140, 0, 255));
				win_->Draw(*door_info_);
			}
		
			switch_door = true;
			escape_disabled = false;
		
		}
		else
		{
			gs_ = GameOver;
		}
	}
	
	else if(gs_ == Pause)
	{
		win_->Clear();
		win_->SetView(sf::View(sf::FloatRect(0, 0, GAME_WIDTH, GAME_HEIGHT)));
		menu_echap_->display(win_);	
	}
	else if(gs_ == Finish)
	{
		win_->Clear();
		win_->SetView(sf::View(sf::FloatRect(0, 0, GAME_WIDTH, GAME_HEIGHT)));
		menu_end_->display(win_); 
		if(clk_display_finish_->GetElapsedTime() > DISPLAY_FINISH)
		{
			gs_ = Quit;
		}
	}
	else if(gs_ == ControlPanel)
	{
		win_->Clear();
		win_->SetView(sf::View(sf::FloatRect(0, 0, GAME_WIDTH, GAME_HEIGHT)));
		menu_controls_->display(win_);
	}
	else if(gs_ == GameOver)
	{
		win_->Clear();
		win_->SetView(sf::View(sf::FloatRect(0, 0, GAME_WIDTH, GAME_HEIGHT)));
		menu_go_->display(win_);
	}
	else if(gs_ == Quit)
	{
		win_->Close();
	}
	
	mm_->run(gs_, cm_->getNpc("miniboss")->isAlive(), door_opened);
	
	win_->Display();
  }


}
