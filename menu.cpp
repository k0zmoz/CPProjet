#include <SFML/Graphics.hpp>
#include "menu.hpp"
#include <iostream>

using namespace sf;
using namespace std;

Menu::Menu (GameState state)
{

	background_img_ = new sf::Image;
	background_spr_ = new sf::Sprite(*background_img_);
  
	
  switch(state)
  {
		case Start:
			buttons_.push_front(new Button(Play));
			buttons_.push_front(new Button(Exit));
			buttons_.push_front(new Button(Controls));
			
			if (!background_img_->LoadFromFile("Menu/bg_start.png"))
			{
				cout<<"Erreur durant le chargement de l'image bg_start"<<endl;
				exit(EXIT_FAILURE);
			}
		
			background_spr_->SetSubRect(IntRect(0, 0, 800, 600));
	
			shade_img_ = new sf::Image;
			shade_play_ = new sf::Sprite(*shade_img_);
			shade_exit_ = new sf::Sprite(*shade_img_);
			shade_controls_ = new sf::Sprite(*shade_img_);
			
			if (!shade_img_->LoadFromFile("Menu/shade_start.png"))
			{
				cout << "Erreur durant le chargement de l'image shade_start" << endl;
				exit(EXIT_FAILURE);
			}
			shade_play_->SetSubRect(IntRect(375, 285, 500, 370));	
			shade_play_->SetPosition(375,285);
			shade_exit_->SetSubRect(IntRect(375, 430, 510, 510));	
			shade_exit_->SetPosition(375,430);
			shade_controls_->SetSubRect(IntRect(5, 40, 240, 110));	
			shade_controls_->SetPosition(5,40);
			break;
			
		case Pause :
			buttons_.push_front(new Button(Resume));
			buttons_.push_front(new Button(Exit));
			buttons_.push_front(new Button(Controls));
			
			if (!background_img_->LoadFromFile("Menu/bg_echap.png"))
			{
				cout<<"Erreur durant le chargement de l'image bg_echap"<<endl;
				exit(EXIT_FAILURE);
			}
		
			background_spr_->SetSubRect(IntRect(0, 0, 800, 600));
	
			shade_img_ = new sf::Image;
			shade_play_ = new sf::Sprite(*shade_img_);
			shade_exit_ = new sf::Sprite(*shade_img_);
			shade_controls_ = new sf::Sprite(*shade_img_);
			
			if (!shade_img_->LoadFromFile("Menu/shade_echap.png"))
			{
				cout << "Erreur durant le chargement de l'image shade_echap" << endl;
				exit(EXIT_FAILURE);
			}
			shade_play_->SetSubRect(IntRect(340, 310, 540, 370));	
			shade_play_->SetPosition(340,310);
			shade_exit_->SetSubRect(IntRect(375, 430, 510, 510));	
			shade_exit_->SetPosition(375,430);
			shade_controls_->SetSubRect(IntRect(5, 40, 240, 110));	
			shade_controls_->SetPosition(5,40);
			break;
			
			
		case Finish :
			
			if (!background_img_->LoadFromFile("Menu/bg_finish.png"))
			{
				cout<<"Erreur durant le chargement de l'image bg_finish"<<endl;
				exit(EXIT_FAILURE);
			}
  		background_spr_->SetSubRect(IntRect(0, 0, 800, 600));
		
			break;
			
		case GameOver :
			
			buttons_.push_front(new Button(NewGame));
		  buttons_.push_front(new Button(ExitThroughGameOver));
			
			if (!background_img_->LoadFromFile("Menu/Game_Over.png"))
			{
				cout<<"Erreur durant le chargement de l'image game over"<<endl;
				exit(EXIT_FAILURE);
			}
			
			background_spr_->SetSubRect(IntRect(0, 0, 800, 600));
			
			shade_img_ = new sf::Image;
			shade_play_ = new sf::Sprite(*shade_img_);
			shade_exit_ = new sf::Sprite(*shade_img_);
			
			
			if (!shade_img_->LoadFromFile("Menu/shade_game_over.png"))
			{
				cout << "Erreur durant le chargement de l'image shade_game_over" << endl;
				exit(EXIT_FAILURE);
			}
			
  		shade_play_->SetSubRect(IntRect(80,480,350,520));
  		shade_play_->SetPosition(80,480);
  		shade_exit_->SetSubRect(IntRect(470,480,750,520));
			shade_exit_->SetPosition(470,480);
			break;

			case ControlPanel :
				
				if (!background_img_->LoadFromFile("Menu/controls.png"))
				{
					cout<<"Erreur durant le chargement de l'image controls"<<endl;
					exit(EXIT_FAILURE);
				}
				
				background_spr_->SetSubRect(IntRect(0, 0, 800, 600));
				
				break;

  	default : break;
  }
  	
  	menu_state_ = state;
  	current_button_ = NoAction;
}

Menu::~Menu ()
{

	delete background_img_;
	delete background_spr_;
	
	switch(menu_state_)
	{
		case Start:
			delete shade_img_;
			delete shade_play_;
			delete shade_exit_;
			delete shade_controls_;
			break;
		case Pause:
			delete shade_img_;
			delete shade_play_;
			delete shade_exit_;
			delete shade_controls_;
			break;
		case GameOver:
			delete shade_img_;
			delete shade_play_;
			delete shade_exit_;
			break;
			
		default : break;
	}

}

void
Menu::display (sf::RenderTarget *rt)
{ 
	rt->Draw(*background_spr_);
	displayButtons(rt);  
}

void
Menu::setCurrentButton (int mouse_x, int mouse_y)
{
  current_button_ = NoAction;
  for (auto b : buttons_) {
    if (b->contains(mouse_x, mouse_y)) {
      current_button_ = b->getAction();
      return;
    }
  }
}

Action
Menu::getAction ()
{
  return current_button_;
}

void
Menu::displayButtons (sf::RenderTarget *rt)
{
  for (auto b : buttons_)
  {
    if (current_button_ == b->getAction())
    { 
      switch (current_button_)
      {		      		      	
		    case Play : 	
					rt->Draw(*shade_play_);
					break;
		    
		    case Exit : 	
					rt->Draw(*shade_exit_);
					break;
								
				case Resume :
					rt->Draw(*shade_play_);
					break;
				
				case ExitThroughGameOver :
					rt->Draw(*shade_exit_);
					break;
					
				case NewGame :
					rt->Draw(*shade_play_);
					break;
				case Controls :
					rt->Draw(*shade_controls_);
					break;
			
				default : 
					rt->Clear();
					break;
		}
   }
 }
}
