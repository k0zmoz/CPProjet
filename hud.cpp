#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "hud.hpp"

using namespace sf;

Hud::Hud ()
{
	hud_img_ = new sf::Image;
	shade_hud_img_ = new sf::Image;
	
	//instanciation du hud
  
	if(! hud_img_->LoadFromFile("./HUD/hud.png"))
	{
		std::cerr << "Error loading hud Image" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	hud_spr_ = new sf::Sprite(*hud_img_);
	
	//instanciation des ombres du hud
	
	if(! shade_hud_img_->LoadFromFile("./HUD/hud_shades.png"))
	{
		std::cerr << "Error loading hud Image" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	shade_health_ = std::vector<Sprite *> (AMNT_SPR_SHADE_HEALTH);
	for(int i = 0; i < AMNT_SPR_SHADE_HEALTH; i++)
	{
		shade_health_[i] = new Sprite(*shade_hud_img_);
		shade_health_[i]->SetSubRect(sf::IntRect(
		OFFSET_SHADE_HEALTH_W + i * (OFFSET_SHADE_HEALTH_W + SHADE_HEALTH_W),
		OFFSET_SHADE_HEALTH_H,
		OFFSET_SHADE_HEALTH_W + i * (OFFSET_SHADE_HEALTH_W + SHADE_HEALTH_W) + SHADE_HEALTH_W,
		OFFSET_SHADE_HEALTH_H + SHADE_HEALTH_H));
	}
	
	shade_stamina_ = std::make_pair(new Sprite (*shade_hud_img_), new Sprite (*shade_hud_img_));
	
	shade_stamina_.first->SetSubRect(sf::IntRect(FIRST_STAMINA_LEFT, FIRST_STAMINA_TOP,
	FIRST_STAMINA_RIGHT, FIRST_STAMINA_BOTTOM));
	
	shade_stamina_.second->SetSubRect(sf::IntRect(SECOND_STAMINA_LEFT, SECOND_STAMINA_TOP,
	SECOND_STAMINA_RIGHT, SECOND_STAMINA_BOTTOM));
	
}

Hud::~Hud ()
{
	delete hud_img_;
	delete hud_spr_;
	delete shade_hud_img_;
	for(std::vector<Sprite *>::iterator it = shade_health_.begin();
	it != shade_health_.end(); it++)
	{
		delete *it;
	}
	delete shade_stamina_.first;
	delete shade_stamina_.second;
}


void Hud::display (sf::RenderTarget &rt, PlayableChar *pc, Map *map)
{
	int i;
	sf::View v = map->getView();
	
	//cout << "left: " << v.GetRect().Left << "top: " << v.GetRect().Top << endl;
	
	hud_spr_->SetPosition(v.GetRect().Left, v.GetRect().Top);
	rt.Draw(*hud_spr_);

	for(i = (AMNT_SPR_SHADE_HEALTH - 1); i > 0; i--)
	{
		if(pc->getHealth() < i * (HEALTH_PC / AMNT_SPR_SHADE_HEALTH))
		{
			shade_health_[i]->SetPosition(
			v.GetRect().Left + OFFSET_SHADE_HEALTH_W + i * (OFFSET_SHADE_HEALTH_W + SHADE_HEALTH_W),
			v.GetRect().Top + OFFSET_SHADE_HEALTH_H);
			rt.Draw(*(shade_health_[i]));
		}
	}
	
	if(pc->getStamina() < 2)
	{
		shade_stamina_.first->SetPosition(v.GetRect().Left + FIRST_STAMINA_LEFT,
		v.GetRect().Top + FIRST_STAMINA_TOP);
		
		rt.Draw(*(shade_stamina_.first));
	
	 if(pc->getStamina() < 1)
		{
		shade_stamina_.second->SetPosition(v.GetRect().Left + SECOND_STAMINA_LEFT,
		v.GetRect().Top + SECOND_STAMINA_TOP);
		rt.Draw(*(shade_stamina_.second));
		}
	}
}
	
	
	
