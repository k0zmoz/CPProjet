#include <SFML/Graphics.hpp>
#include <iostream>
#include "combat_manager.hpp"

using namespace sf;
using namespace std;


CombatManager::CombatManager ()
{
  trash_mob_ = new Npc (0, -1472, false);
  cryst_ = new Crystal(Fire, 250, 350);
  miniboss_ = new Npc(350, 250, true);
  duneyrr_ = new Boss();
  clk_mov_npc_ = new Clock();
  clk_launch_arr_list1 = new Clock();
  for (int i = 0; i < AMNT_ARR_LIST1; i++)
  {
		arr_list1_.push_front(new Arrow(Right, SPAWN_LIST1_X, SPAWN_LIST1_Y));
	}

}

CombatManager::~CombatManager()
{
	delete trash_mob_;
	for(auto arr : arr_list1_){
		delete arr;
	}
	delete clk_mov_npc_;
	delete clk_launch_arr_list1;
	delete cryst_;
	delete miniboss_;
	delete duneyrr_;
}

void CombatManager::run (PlayableChar *pc)
{
	//Gestion des déplacements:
	
	//Npc
		
		//Si le héros est dans un rayon alentour, il essaye de le rejoindre
		if(isNearHero(trash_mob_, pc))
		{
			moveNpc(trash_mob_, pc->getX(), pc->getY());
		}
		
		//Sinon si le mob est aux environs du centre de sa salle, il se déplace aléatoirement
		else if(isInRadius2D(trash_mob_, CENTER_ROOM_NPC_X, CENTER_ROOM_NPC_Y, RADIUS_ROOM_NPC))
		{
			if(clk_mov_npc_->GetElapsedTime() > (1 / SWITCH_DIR_SPEED_NPC) )
			{
				moveRandomlyNpc(trash_mob_); 
				clk_mov_npc_->Reset();
			}
			else
			{
				trash_mob_->move(trash_mob_->getDir());
			}
		}

		//Sinon le mob retourne au centre de la salle
		else
		{
			moveNpc(trash_mob_, CENTER_ROOM_NPC_X, CENTER_ROOM_NPC_Y);
		}
		
		for(auto arr : arr_list1_)
		{
			if(arr->isLaunched())
			{
				moveArrow(arr, Left, SPAWN_LIST1_X, SPAWN_LIST1_Y, DIST_LIM_LIST1);
			}
			else if(clk_launch_arr_list1->GetElapsedTime() > LAUNCH_DELAY_LIST1)
			{
				launchNextArrow(arr_list1_);
				clk_launch_arr_list1->Reset();
			}
		}
}

void CombatManager::wander(Character *chara)
{
	int rand = sf::Randomizer::Random(0, 100);

	/*Evaluation du nombre aléatoire obtenu via rand_reduced:
	1 => 0 < rand < 25  | 2 => 25 < rand < 50  |
	3 => 50 < rand < 75 | 4 => 75 < rand < 100 |*/
	
	int rand_reduced = rand < 50 ? (rand < 25 ? 1 : 2) : (rand < 75 ? 3 : 4);
	switch(rand_reduced)
	{
		case 1 :
			chara->look(Down);
			break;
		
		case 2:
			chara->look(Up);
			break;
		
		case 3 :
			chara->look(Left);
			break;
		
		case 4 :
			chara->look(Right);
			break;
			
		default : break;
	}
}


void CombatManager::headToCoord (Character *chara, int x, int y)
{
	if(!isInRadius2D(chara, x, y, RADIUS_LOCATE_COORD))
	{
		/*Si Character au Sud Est du point on aligne son abscisse en 1er
		déplacement à gauche)*/
		if(chara->getX() > x && chara->getY() > y
		&& !isInRadius1D(chara, x, RADIUS_LOCATE_COORD, true)
		&& !isInRadius1D(chara, y, RADIUS_LOCATE_COORD, false))
		{
			chara->look(Left);
		}
		
		/*Si Character au Sud Ouest du point on aligne son abscisse en 1er
		déplacement à droite)*/
		else if(chara->getX() < x && chara->getY() > y
		&& !isInRadius1D(chara, x, RADIUS_LOCATE_COORD, true)
		&& !isInRadius1D(chara, y, RADIUS_LOCATE_COORD, false))
		{
			chara->look(Right);
		}
		
		//Si Character au Sud du point on le déplace vers le Nord
		else if(chara->getY() > y
		&& isInRadius1D(chara, x, RADIUS_LOCATE_COORD, true)
		&& !isInRadius1D(chara, y, RADIUS_LOCATE_COORD, false))
		{
			chara->look(Up);
		}
		
		/*Si Character au Nord Est du point on aligne son abscisse en 1er
		déplacement à gauche)*/
		else if(chara->getX() > x && chara-> getY() < y
		&& !isInRadius1D(chara, x, RADIUS_LOCATE_COORD, true)
		&& !isInRadius1D(chara, y, RADIUS_LOCATE_COORD, false))
		{
			chara->look(Left);
		}
		
		/*Si Character au Nord Ouest du point on aligne son abscisse en 1er
		déplacement à droite)*/
		else if(chara->getX() < x && chara-> getY() < y
		&& !isInRadius1D(chara, x, RADIUS_LOCATE_COORD, true)
		&& !isInRadius1D(chara, y, RADIUS_LOCATE_COORD, false))
		{
			chara->look(Right);
		}
		
		//Si Character au Nord du point on le déplace vers le Sud
		else if(chara->getY() < y
		&& isInRadius1D(chara, x, RADIUS_LOCATE_COORD, true)
		&& !isInRadius1D(chara, y, RADIUS_LOCATE_COORD, false))
		{
			chara->look(Down);
		}
	}
}

bool CombatManager::isInRadius1D (Character *chara, int coord, int radius, bool test_absciss)
{
	if(test_absciss)
	{
		return ( (chara->getX() > coord - radius) && (chara->getX() < coord + radius) );
	}
	else
	{
		return ( (chara->getY() > coord - radius) && (chara->getY() < coord + radius) );
	}
}

bool CombatManager::isInRadius2D (Character *chara, int x, int y, int radius)
{
	return Rect<int>(x - radius, y - radius, x + radius, y + radius).Contains(chara->getX(), chara->getY());
}

bool CombatManager::isNearHero (Character *chara, PlayableChar *pc)
{	
	return isInRadius2D (chara, pc->getX(), pc->getY(), RADIUS_LOCATE_PC);
}

void CombatManager::moveNpc (Npc *npc, int x, int y)
{
		headToCoord(npc, x, y);
		npc->move(npc->getDir());
}

void CombatManager::moveRandomlyNpc (Npc *npc)
{
		wander(npc);
		npc->move(npc->getDir());
}

void CombatManager::moveArrow(Arrow *arr, Direction dir, int spawn_x, int spawn_y, int dist_lim)
{
	if(arr->getDistTraveled() < dist_lim)
	{
		arr->move(dir);
	}
	else
	{
		arr->setPosition(spawn_x, spawn_y);
		arr->setDistTraveled(0);
	}
}

void CombatManager::moveBoss (Boss *boss, int x, int y)
{
		headToCoord(boss, x, y);
		boss->move(boss->getDir());
}


void CombatManager::launchNextArrow(std::list<Arrow *> arr_list)
{
	std::list<Arrow *>::iterator it = arr_list.begin();
	
	do
	{
		it++;
	}
	while((*it)->isLaunched() && it != arr_list.end());
	
	(*it)->setLaunched(true);
	
}


void CombatManager::displayArrowList(sf::RenderTarget &rt, std::list<Arrow *> arr_list)
{
	std::list<Arrow *>::iterator it = arr_list.begin();
	
	while(it != arr_list.end() && (*it)->isLaunched())
	{
		(*it)->display(rt);
		it++;
	}

}

Npc *CombatManager::getNpc ()
{
	return trash_mob_;
}

Crystal *CombatManager::getCrystal ()
{
	return cryst_;
}

Boss *CombatManager::getBoss ()
{
	return duneyrr_;
}

std::list<Arrow *>CombatManager::getList1 ()
{
	return arr_list1_;
}



