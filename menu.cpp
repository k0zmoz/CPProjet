#include <list>
#include <SFML/Graphics.hpp>
#include "main.hpp"
#include "menu.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace sf;
using namespace std;

Menu::Menu (GameState state)
{
  	
  background_img_ = new sf::Image;
	background_spr_ = new sf::Sprite(*background_img_);
	if (!background_img_->LoadFromFile("Menu/background.png")) // Si le chargement a échoué
	{
		cout<<"Erreur durant le chargement du background"<<endl;
		exit(EXIT_FAILURE); // On ferme le programme
	}
  	background_spr_->SetSubRect(IntRect(0, 0, 800, 600));
  	
  	switch(state)
  	{
  		case Start:
		  buttons_.push_front(new Button(Play));
			buttons_.push_front(new Button(Exit));
		
			play_exit_red_img_ = new sf::Image;
			play_exit_red_spr_ = new sf::Sprite(*play_exit_red_img_);
			if (!play_exit_red_img_->LoadFromFile("Menu/play_exitred.png")) // Si le chargement a échoué
			{
				cout<<"Erreur durant le chargement de l'image play_exitred"<<endl;
				exit(EXIT_FAILURE); // On ferme le programme
			}
  		
  		play_exit_red_spr_->SetSubRect(IntRect(0, 0, 800, 600));
		
			play_exit_violet_img_ = new sf::Image;
			startgame_playspr_ = new sf::Sprite(*play_exit_violet_img_);
			startgame_exitspr_ = new sf::Sprite(*play_exit_violet_img_);
			if (!play_exit_violet_img_->LoadFromFile("Menu/play_exitviolet.png")) // Si le chargement a échoué
			{
				cout<<"Erreur durant le chargement de l'image play_exitviolet"<<endl;
				exit(EXIT_FAILURE); // On ferme le programme
			}
				startgame_playspr_->SetSubRect(IntRect(373, 288, 502, 374));	
				startgame_playspr_->SetPosition(373,288);
				startgame_exitspr_->SetSubRect(IntRect(371, 426, 515, 518));	
				startgame_exitspr_->SetPosition(371,426);
		cout << "CASE START OK\n";
			break;
			
			case Pause :
			buttons_.push_front(new Button(Resume));
		  buttons_.push_front(new Button(ExitThroughPause));
		  
		  resume_exit_red_img_ = new sf::Image;
			resume_exit_red_spr_ = new sf::Sprite(*resume_exit_red_img_);
			if (!resume_exit_red_img_->LoadFromFile("Menu/resume_exitred.png")) // Si le chargement a échoué
			{
				cout<<"Erreur durant le chargement de l'image resume_exitred"<<endl;
				exit(EXIT_FAILURE); // On ferme le programme
			}
  		cout << "CASE ECHAP ENTER\n";
  		resume_exit_red_spr_->SetSubRect(IntRect(0, 0, 800, 600));
		
			resume_exit_violet_img_ = new sf::Image;
			echap_resumespr_ = new sf::Sprite(*resume_exit_violet_img_);
			echap_exitspr_ = new sf::Sprite(*resume_exit_violet_img_);
			if (!resume_exit_violet_img_->LoadFromFile("Menu/resume_exitviolet.png")) // Si le chargement a échoué
			{
				cout<<"Erreur durant le chargement de l'image resume_exitviolet"<<endl;
				exit(EXIT_FAILURE); // On ferme le programme
			}
				echap_resumespr_->SetSubRect(IntRect(367, 305, 521, 355));	
				echap_resumespr_->SetPosition(367,305);
				echap_exitspr_->SetSubRect(IntRect(384, 419, 483, 465));	
		  	echap_exitspr_->SetPosition(384,419);
		  	cout << "CASE ECHAP OK";
			break;
			
			case Finish :
			
			princess_img_ = new sf::Image;
			princess_spr_ = new sf::Sprite(*princess_img_);
			if (!princess_img_->LoadFromFile("Menu/urprincess.png")) // Si le chargement a échoué
			{
				cout<<"Erreur durant le chargement de l'image princess"<<endl;
				exit(EXIT_FAILURE); // On ferme le programme
			}
  		princess_spr_->SetSubRect(IntRect(0, 0, 800, 600));
		
			break;

  	default : break;
  }
  	
  	menu_state_ = state;
  	current_button_ = NoAction;
}

Menu::~Menu ()
{

	/*Manque delete list button*/

	delete background_img_;
	delete background_spr_;
	
	switch(menu_state_)
	{
		case Start:
			delete play_exit_red_img_;
			delete play_exit_red_spr_;
			delete play_exit_violet_img_;
			delete startgame_playspr_;
			delete startgame_exitspr_;
			break;
		case Pause:
			delete resume_exit_red_img_;
			delete resume_exit_red_spr_;
			delete resume_exit_violet_img_;
			delete echap_resumespr_;
			delete echap_exitspr_;
			break;
		case Finish:
			delete princess_img_;
			delete princess_spr_;
			break;
		default : break;
	}

}


void
Menu::display (sf::RenderTarget *rt, GameState gs)
{ 
	switch(gs)
	{
		case Start :
					rt->Draw(*background_spr_);
					rt->Draw(*play_exit_red_spr_);
					break;
					
		case Pause :
					rt->Draw(*background_spr_);
					rt->Draw(*resume_exit_red_spr_);				
					break;
					
		case Finish :
					rt->Draw(*background_spr_);
					rt->Draw(*princess_spr_);
					break;

		default :   break;
	}
												
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
	int shade=0;
  for (auto b : buttons_) {
    if (current_button_ == b->getAction()) {
      shade = b->displayActive(rt);
      cout << "shade : " << shade << endl;
      	
      	switch (shade){	
  		case -1 : 	rt->Draw(*background_spr_); break;
      	      		      	
      case 1 : 	
	      //rt->Draw(*background_spr_);
	     //rt->Draw(*play_exit_red_spr_);
				rt->Draw(*startgame_playspr_);

				break;

      case 2 : 	
	      //rt->Draw(*background_spr_);
	      //rt->Draw(*play_exit_red_spr_);
				rt->Draw(*startgame_exitspr_);

				break;
								
		case 3 : 	//cout<<"33";
	     // rt->Draw(*background_spr_);
				rt->Draw(*echap_resumespr_);

				break;
				
		case 4 : 	//cout<<"44";
	      //rt->Draw(*background_spr_);
				rt->Draw(*echap_exitspr_);
				break;
				
				
		default : 	rt->Clear();break;
	}
	
    }
    else {
      b->display(rt);
    }
  }
}
