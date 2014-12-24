#ifndef MAIN_HPP
#define MAIN_HPP

//enum Player { X, O, None };
enum Action { NoAction = 0, NewGame, Exit, Play, Pause, Resume, Exit2};
typedef enum { Down = 0, Up, Left, Right} Direction;
typedef enum { Start= 0, Echap, End} GameState;

#define CELL_WIDTH 150
#define CELL_PADDING 10

#define TILE_W 16
#define TILE_H 16

#define GAME_WIDTH  800
#define GAME_HEIGHT 600

//vitesses
#define CHAR_SPEED 5 //nombre de pixels dont un personnage jouable se déplace
#define NPC_SPEED 5 //nombre de pixels dont un npc se déplace
#define BOSS_SPEED 5 //nombre de pixels dont un boss se déplace
#define MOV_SPEED 30 //nombre d'images à afficher par seconde pour un déplacement
#define ATK_SPEED 11	 //nombre d'images à afficher par seconde pour une attaque
#define DEATH_SPEED 10	 //nombre d'images à afficher par seconde pour une mort


#endif // MAIN_HPP
