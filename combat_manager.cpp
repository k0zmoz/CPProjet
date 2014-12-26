#include <SFML/Graphics.hpp>
#include <iostream>
#include "combat_manager.hpp"

using namespace sf;
using namespace std;


CombatManager::CombatManager ()
{
  trash_mob_ = new Npc (0, -1472, false);
  miniboss_ = new Npc(0, -1400, true);
  duneyrr_ = new Boss();
  npc_list_.push_back(trash_mob_);
  npc_list_.push_back(miniboss_);
  
  cryst_mob_ = new Crystal(Fire, -30, -900);
  cryst_trap1_ = new Crystal(Water, 30, -800);
  cryst_trap2_ = new Crystal(Water, 30, -850);
  
  cryst_list_.push_back(cryst_mob_);
  cryst_list_.push_back(cryst_trap1_);
  cryst_list_.push_back(cryst_trap2_);
  
  
  for (int i = 0; i < AMNT_ARR_LIST1; i++)
  {
		arr_list1_.push_front(new Arrow(Right, SPAWN_LIST1_X, SPAWN_LIST1_Y));
	}
	
	clk_mov_npc_ = new Clock();
  clk_mov_boss_ = new Clock();
  clk_launch_arr_list1 = new Clock();
  clk_chk_opport_npc_ = new Clock();
  clk_chk_opport_boss_ = new Clock();
  clk_regen_health_ = new Clock();
  clk_regen_stamina_ = new Clock();
  clk_speed_regen_health_ = new Clock();

}

CombatManager::~CombatManager()
{
	delete trash_mob_;
	delete miniboss_;
	delete duneyrr_;
	
	delete cryst_mob_;
	delete cryst_trap1_;
	delete cryst_trap2_;

	for(auto arr : arr_list1_)
	{
		delete arr;
	}
	
	delete clk_mov_npc_;
	delete clk_mov_boss_;
	delete clk_launch_arr_list1;
	delete clk_chk_opport_npc_;
	delete clk_chk_opport_boss_;
	delete clk_regen_health_;
	delete clk_regen_stamina_;
	delete clk_speed_regen_health_;
}

void CombatManager::run (PlayableChar *pc)
{
	//Gestion des déplacements:
	
	//Npc
	if(!trash_mob_->isAttacking())
	{
		manageMovNpc(trash_mob_, pc);
	}
	/*//Arrow
	manageMovArrList(arr_list1_, SPAWN_LIST1_X, SPAWN_LIST1_Y, DIST_LIM_LIST1, LAUNCH_LIST1_DELAY);		
		
	//Boss
	if(!duneyrr_->isAttacking() && !miniboss_->isAlive())
	{
		manageMovBoss(duneyrr_, pc);
	}
	}
	//Gestions des attaques:
	
	//IA
	checkOpportunities(npc_list_, pc, duneyrr_);
	*/
	//Dégâts:
	checkDamages(pc);
	
	//Régénération de la vie et de la santé
	regenPc(pc);
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

bool CombatManager::isInRadius2DObj (Object *obj, int x, int y, int radius)
{
	return Rect<int>(x - radius, y - radius, x + radius, y + radius).Contains(obj->getX(), obj->getY());
}

bool CombatManager::isNearHero (Character *chara, PlayableChar *pc, int radius_locate)
{	
	return isInRadius2D (chara, pc->getX(), pc->getY(), radius_locate);
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
		(déplacement à gauche)*/
		if(chara->getX() > x && chara->getY() > y
		&& !isInRadius1D(chara, x, RADIUS_LOCATE_COORD, true)
		&& !isInRadius1D(chara, y, RADIUS_LOCATE_COORD, false))
		{
			chara->look(Left);
		}
		
		/*Si Character au Sud Ouest du point on aligne son abscisse en 1er
		(déplacement à droite)*/
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
		(déplacement à gauche)*/
		else if(chara->getX() > x && chara-> getY() < y
		&& !isInRadius1D(chara, x, RADIUS_LOCATE_COORD, true)
		&& !isInRadius1D(chara, y, RADIUS_LOCATE_COORD, false))
		{
			chara->look(Left);
		}
		
		/*Si Character au Nord Ouest du point on aligne son abscisse en 1er
		(déplacement à droite)*/
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
/*	else
	{
		lookToCoord(chara, x, y);
	}
*/
}

void CombatManager::moveChar (Character *chara, int x, int y, int speed, int amnt_sprite)
{
		headToCoord(chara, x, y);
		chara->move(chara->getDir(), speed, amnt_sprite);
}


void CombatManager::moveRandomlyChar (Character *chara, int speed, int amnt_sprite)
{
		wander(chara);
		chara->move(chara->getDir(), speed, amnt_sprite);
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

void CombatManager::manageMovNpc(Npc *npc, PlayableChar *pc)
{
	//Si le héros est dans un rayon alentour, le npc essaye de le rejoindre
	if(isNearHero(npc, pc, RADIUS_NPC_LOCATE_PC))
	{
		moveChar(npc, pc->getX(), pc->getY(), NPC_SPEED, MOV_AMNT_SPRITE_NPC);
	}
	
	//Sinon si le mob est aux environs du centre de sa salle, il se déplace aléatoirement
	else if(isInRadius2D(npc, CENTER_ROOM_NPC_X, CENTER_ROOM_NPC_Y, RADIUS_ROOM_NPC))
	{
		//Changement de direction tous les laps de temps donnés pour réduire les saccades
		if(clk_mov_npc_->GetElapsedTime() > (1 / SWITCH_DIR_SPEED_NPC) )
		{
			moveRandomlyChar(npc, NPC_SPEED, MOV_AMNT_SPRITE_NPC); 
			clk_mov_npc_->Reset();
		}
		else
		{
			npc->move(npc->getDir(), NPC_SPEED, MOV_AMNT_SPRITE_NPC);
		}
	}

	//Sinon le mob retourne au centre de la salle
	else
	{
		moveChar(npc, CENTER_ROOM_NPC_X, CENTER_ROOM_NPC_Y, NPC_SPEED, MOV_AMNT_SPRITE_NPC);
	}
}

void CombatManager::manageMovBoss(Boss *boss, PlayableChar *pc)
{
	//Si le héros est dans un rayon alentour, le boss essaye de le rejoindre
	if(isNearHero(boss, pc, RADIUS_BOSS_LOCATE_PC))
	{
		if(!isNearHero(boss, pc, RADIUS_LOCATE_COORD))
		{
			moveChar(boss, pc->getX(), pc->getY(), BOSS_SPEED, MOV_AMNT_SPRITE_BOSS);
		}
	}
	
	//Sinon si le mob est aux environs du centre de sa salle, il se déplace aléatoirement
	else if(isInRadius2D(boss, CENTER_ROOM_BOSS_X, CENTER_ROOM_BOSS_Y, RADIUS_ROOM_BOSS))
	{
		if(clk_mov_boss_->GetElapsedTime() > (1 / SWITCH_DIR_SPEED_NPC) )
		{
			//cout << "boss rdm switch dir" << endl;
			moveRandomlyChar(boss, BOSS_SPEED, MOV_AMNT_SPRITE_BOSS); 
			clk_mov_boss_->Reset();
		}
		else
		{
			//cout << "boss rdm pas switch dir" << endl;
			boss->move(boss->getDir(), BOSS_SPEED, MOV_AMNT_SPRITE_BOSS);
		}
	}

	//Sinon le boss retourne au centre de la salle
	else
	{
		//cout << "boss go middle" << endl;
		moveChar(boss, CENTER_ROOM_BOSS_X, CENTER_ROOM_BOSS_Y, BOSS_SPEED, MOV_AMNT_SPRITE_BOSS);
	}
}

void CombatManager::manageMovArrList
(std::list<Arrow *> arr_list, int spawn_x, int spawn_y, int dist_lim, int launch_delay)
{
	for(auto arr : arr_list)
	{
		if(arr->isLaunched())
		{
			moveArrow(arr, Left, spawn_x, spawn_y, dist_lim);
		}
		else if(clk_launch_arr_list1->GetElapsedTime() > launch_delay)
		{
			launchNextArrow(arr_list);
			clk_launch_arr_list1->Reset();
		}
	}
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

void CombatManager::displayCrystalList(sf::RenderTarget &rt, std::list<Crystal *> cryst_list)
{
	std::list<Crystal *>::iterator it = cryst_list.begin();

	while(it != cryst_list.end())
	{
		if((*it)->isAlive())
		{
			(*it)->display(rt);
		}
		it++;
	}
}

void CombatManager::checkOpportunityNpc(Npc * npc, PlayableChar *pc, int radius)
{
	//Si le npc n'est pas déjà en train d'attaquer
	if(!npc->isAttacking())
	{
		//Si le pc se trouve bien dans la zone d'attaque du npc
		if(isInRadius2D(npc, pc->getX(), pc->getY(), radius))
		{
			headToCoord(npc, pc->getX(), pc->getY());
			npc->attack();
		}
	}
}

/*void CombatManager::checkOpportunityBoss
(Boss * boss, PlayableChar *pc, int radius_atk, int width_atk_x, int width_atk_y)*/
void CombatManager::checkOpportunityBoss
(Boss * boss, PlayableChar *pc, int radius_atk)
{

	if(!boss->isAttacking())
	{
		//Si le pc se trouve bien dans la zone d'attaque du npc
		if(isInRadius2D(boss, pc->getX(), pc->getY(), radius_atk))
		{
			headToCoord(boss, pc->getX(), pc->getY());
			boss->attack();
		}
	}
	
/*
	//Si le boss n'est pas déjà en train d'attaquer
	if(!boss->isAttacking())
	{
		//Si le pc se trouve à distance de charge en ordonnée et largeur de charge en abscisse
		if(	isInRadius1D(boss, pc->getX(), width_atk_x, true)
		&&	isInRadius1D(boss, pc->getY(), radius_atk, false))
		{
			cout << "chk opport width" << endl;
			headToCoord(boss, pc->getX(), pc->getY());
			boss->attack();
		}
		//Ou si le pc se trouve à distance de charge en abscisse et largeur de charge en ordonnée
		else if(isInRadius1D(boss, pc->getY(), width_atk_y, false)
		&&	isInRadius1D(boss, pc->getX(), radius_atk, true))
		{
		cout << "chk opport height" << endl;
			headToCoord(boss, pc->getX(), pc->getY());
			boss->attack();
		}
	}*/
}

void CombatManager::checkOpportunities(std::list<Npc *> npc_list, PlayableChar *pc, Boss *boss)
{
	if(clk_chk_opport_npc_->GetElapsedTime() > CHK_OPPORT_NPC_DELAY)
	{
		for(auto npc : npc_list)
		{
			checkOpportunityNpc(npc, pc, RADIUS_NPC_AGGRO);
		}
		clk_chk_opport_npc_->Reset();
	}
	
	if(clk_chk_opport_boss_->GetElapsedTime() > CHK_OPPORT_BOSS_DELAY && (!miniboss_->isAlive()) )
	{
			checkOpportunityBoss(boss, pc, RADIUS_BOSS_AGGRO);	
			/*//largeur du sprite d'atk en cours
			(boss->getSizeBossSprite(boss->getSprite(Atk, boss->getDir(), boss->getStepAtk()), true)),
			//hauteur du sprite d'atk en cours
			boss->getSizeBossSprite(boss->getSprite(Atk, boss->getDir(), boss->getStepAtk()), false));
			clk_chk_opport_boss_->Reset();*/
	}
}

void CombatManager::checkDamageNPChara
(Character *npchara, PlayableChar *pc, int range, int radius, int damage)
{
	switch(npchara->getDir())
	{
		case Down:
			if(isInRadius2D(pc, npchara->getX(), npchara->getY() + range, radius))
			{
				pc->setHealth(pc->getHealth() - damage);
				pc->setHit(true);
			}
			break;
		case Up:
			if(isInRadius2D(pc, npchara->getX(), npchara->getY() -range, radius))
			{
				pc->setHealth(pc->getHealth() - damage);
				pc->setHit(true);
			}
			break;
		case Left:
			if(isInRadius2D(pc, npchara->getX() - range, npchara->getY(), radius))
			{
				pc->setHealth(pc->getHealth() - damage);
				pc->setHit(true);
			}
			break;
		case Right:
			if(isInRadius2D(pc, npchara->getX() + range, npchara->getY(), radius))
			{
				pc->setHealth(pc->getHealth() - damage);
				pc->setHit(true);
			}
			break;
		default : break;
	} 
}

void CombatManager::checkDamageAllNpc(std::list<Npc *> npc_list, Boss *boss, PlayableChar *pc)
{
	for(auto npc : npc_list)
	{
		if(npc->isAttacking())
		{
			checkDamageNPChara(npc, pc, RANGE_NPC_ATK, RADIUS_NPC_ATK, DAMAGE_NPC);
		}
	}
	
	//Si le miniboss est en vie, le boss n'existe pas encore
	if(boss->isAttacking() && !miniboss_->isAlive())
	{
		checkDamageNPChara(boss, pc, RANGE_BOSS_ATK, RADIUS_BOSS_ATK, DAMAGE_BOSS);
	}
}


void CombatManager::checkDamagePc
(PlayableChar *pc, std::list<Npc *> npc_list, Boss *boss,
std::list<Crystal *> cryst_list, int range, int radius, int damage)
{
	switch(pc->getDir())
	{
		case Down:
			for(auto npc : npc_list)
			{
				if(isInRadius2D(npc, pc->getX(), pc->getY() + range, radius))
				{
					npc->setHealth(npc->getHealth() - damage);
				}
			}
			for(auto cryst : cryst_list)
			{
				if(!cryst->isInvincible())
				{
					if(isInRadius2DObj(cryst, pc->getX(), pc->getY() + range, radius))
					{
						cryst->setHealth(cryst->getHealth() - damage);
					}
				}
			}
			
			if(isInRadius2D(boss, pc->getX(), pc->getY() + range, radius + HELP_RADIUS_BOSS
			/*&& !miniboss_->isAlive()*/))
				{
					boss->setHealth(boss->getHealth() - damage);
				}
			break;
		case Up:
			for(auto npc : npc_list)
			{
				if(isInRadius2D(npc, pc->getX(), pc->getY() - range, radius))
				{
					npc->setHealth(npc->getHealth() - damage);
				}
			}
			for(auto cryst : cryst_list)
			{
				if(!cryst->isInvincible())
				{
					if(isInRadius2DObj(cryst, pc->getX(), pc->getY() - range, radius))
					{
						cryst->setHealth(cryst->getHealth() - damage);
					}
				}
			}
			
			if(isInRadius2D(boss, pc->getX(), pc->getY() - range, radius + HELP_RADIUS_BOSS
			/*&& !miniboss_->isAlive()*/))
				{
					boss->setHealth(boss->getHealth() - damage);
				}
			break;
		case Left:
			for(auto npc : npc_list)
			{
				if(isInRadius2D(npc, pc->getX() - range, pc->getY(), radius))
				{
					npc->setHealth(npc->getHealth() - damage);
				}
			}
			for(auto cryst : cryst_list)
			{
				if(!cryst->isInvincible())
				{
					if(isInRadius2DObj(cryst, pc->getX() - range, pc->getY(), radius))
					{
						cryst->setHealth(cryst->getHealth() - damage);
					}
				}
			}
			
			if(isInRadius2D(boss, pc->getX() - range, pc->getY(), radius + HELP_RADIUS_BOSS
			/*&& !miniboss_->isAlive()*/))
				{
					boss->setHealth(boss->getHealth() - damage);
				}
			break;
		case Right:
			for(auto npc : npc_list)
			{
				if(isInRadius2D(npc, pc->getX() + range, pc->getY(), radius))
				{
					npc->setHealth(npc->getHealth() - damage);
				}
			}
			for(auto cryst : cryst_list)
			{
				if(!cryst->isInvincible())
				{
					if(isInRadius2DObj(cryst, pc->getX() + range, pc->getY(), radius))
					{
						cryst->setHealth(cryst->getHealth() - damage);
					}
				}
			}
			
			if(isInRadius2D(boss, pc->getX() + range, pc->getY(), radius + HELP_RADIUS_BOSS
			/*&& !miniboss_->isAlive()*/))
				{
					boss->setHealth(boss->getHealth() - damage);
				}
			break;
	}
} 
	
void CombatManager::checkDamageArrow(std::list<Arrow *> arr_list, PlayableChar *pc, int damage)
{
	for(auto arr : arr_list)
	{
		if(isInRadius2D(pc, arr->getX(), arr->getY(), 1))
		{
			pc->setHealth(pc->getHealth() - damage);
		}
	}
}

void CombatManager::checkDamages(PlayableChar * pc)
{
	checkDamageAllNpc(npc_list_, duneyrr_, pc);
	
	if(pc->isAttacking())
	{
		checkDamagePc(pc, npc_list_, duneyrr_, cryst_list_,
		RANGE_PC_ATK, RADIUS_PC_ATK, DAMAGE_PC);
	}
	
	checkDamageArrow(arr_list1_, pc, ARROW_DAMAGE);
}


void CombatManager::regenPc(PlayableChar *pc)
{
	if(clk_regen_stamina_->GetElapsedTime() > DELAY_REGEN_STAMINA)
	{
		pc->setStamina(AMNT_ESCAPE_PC);
		clk_regen_stamina_->Reset();
	}
	
	if(pc->isHit())
	{
		clk_regen_health_->Reset();
		pc->setHit(false);
	}
	else
	{
		if(clk_regen_health_->GetElapsedTime() > DELAY_REGEN_HEALTH)
		{
			if(clk_speed_regen_health_->GetElapsedTime() > SPEED_REGEN_HEALTH)
			{
				pc->setHealth(pc->getHealth() + 1);
				clk_speed_regen_health_->Reset();
			}
		}
	}
}
	

Npc *CombatManager::getNpc (std::string name)
{
	if(name == "trash_mob")
	{
		return trash_mob_;
	}
	else if(name == "miniboss")
	{
		return miniboss_;
	}
	else
	{
		cerr << "Incorrect name for getNpc()" << endl;
		exit(EXIT_FAILURE);
	}
		
}

Crystal *CombatManager::getCrystal (std::string epithet)
{
	if(epithet == "mob")
	{
		return cryst_mob_;
	}
	else if(epithet == "trap1")
	{
		return cryst_trap1_;
	}
	else if(epithet == "trap2")
	{
		return cryst_trap2_;
	}
	else
	{
		cerr << "Incorrect epithet for getCrystal()" << endl;
		exit(EXIT_FAILURE);
	}
}

std::list<Crystal *> CombatManager::getCrystalList ()
{
	return cryst_list_;
}

Boss *CombatManager::getBoss ()
{
	return duneyrr_;
}

std::list<Arrow *>CombatManager::getList1 ()
{
	return arr_list1_;
}

