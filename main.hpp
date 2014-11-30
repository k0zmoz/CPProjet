#ifndef MAIN_HPP
#define MAIN_HPP

//enum Player { X, O, None };
//enum Action { NoAction, NewGame, Exit };
typedef enum { Down = 0, Up, Left, Right} Direction;

#define TILE_W 10
#define TILE_H 10

#define GAME_WIDTH  1200
#define GAME_HEIGHT 1000

//vitesses
#define CHAR_SPEED 5 //nombre de pixels dont un personnage se déplace
#define MOV_SPEED 30 //nombre d'images à afficher par seconde pour un déplacement
#define ATK_SPEED 10 //nombre d'images à afficher par seconde pour une attaque


#endif // MAIN_HPP