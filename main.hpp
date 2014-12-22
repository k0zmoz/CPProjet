#ifndef MAIN_HPP
#define MAIN_HPP

//enum Player { X, O, None };
//enum Action { NoAction, NewGame, Exit };
typedef enum { Down = 0, Up, Left, Right} Direction;

#define TILE_W 16
#define TILE_H 16

#define GAME_WIDTH  1200
#define GAME_HEIGHT 1000

//vitesses
#define CHAR_SPEED 5 //nombre de pixels dont un personnage jouable se déplace
#define NPC_SPEED 5 //nombre de pixels dont un npc se déplace
#define BOSS_SPEED 5 //nombre de pixels dont un boss se déplace
#define MOV_SPEED 30 //nombre d'images à afficher par seconde pour un déplacement
#define ATK_SPEED 1	 //nombre d'images à afficher par seconde pour une attaque
#define DEATH_SPEED 0.5	 //nombre d'images à afficher par seconde pour une mort


#endif // MAIN_HPP
