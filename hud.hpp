#ifndef HUD_HPP
#define HUD_HPP

#include <list>
#include <vector>
#include <SFML/Graphics.hpp>
#include "main.hpp"
#include "playable_char.hpp"
#include "map.hpp"

#define AMNT_SPR_SHADE_HEALTH 6

#define OFFSET_SHADE_HEALTH_W 20
#define OFFSET_SHADE_HEALTH_H 10
#define SHADE_HEALTH_W 60
#define SHADE_HEALTH_H 50

#define FIRST_STAMINA_LEFT 570
#define FIRST_STAMINA_TOP 10
#define FIRST_STAMINA_RIGHT 640
#define FIRST_STAMINA_BOTTOM 60

#define SECOND_STAMINA_LEFT 680
#define SECOND_STAMINA_TOP 10
#define SECOND_STAMINA_RIGHT 745
#define SECOND_STAMINA_BOTTOM 60

using namespace sf;

class Hud
{
public:
  Hud ();
  ~Hud ();

  void display (sf::RenderTarget &rt, PlayableChar * pc, Map *map);


private:

  Image *hud_img_;
  Sprite *hud_spr_;
	
	Image *shade_hud_img_;
	Sprite *shade_hud_spr_;
	
	std::vector<Sprite *> shade_health_;	
	std::pair<Sprite *, Sprite *> shade_stamina_;

	
};

#endif // MENU_HPP
