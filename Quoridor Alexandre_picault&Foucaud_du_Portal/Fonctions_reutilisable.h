/*
 Fonctions_reutilisable.h
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 31/03/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



#define Fonctions_reutilisable_h

///

#include <time.h>

//this part is used for all the functions in we will need many times

#define NB_CHAR 20

//

void clear_console (void);

//structure for each pawn used

struct pion
{
    char name[NB_CHAR];
    int number_player;
    int number_fence;
    int x;
    int y;
};
typedef struct pion pion;

//structure for each fence used

struct fence
{
    int x1;
    int y1;
    int x2;
    int y2;
    
};
typedef struct fence fence;

//define the position of a pawn

void enter_coord_Pion (void);

//pawn display

void display_coord_Pion (void);

//verification that it is possible to place the fence

void tester_barrier (fence Barrier);
void switchtest (int test, fence Barrier);

//define the position of a fence

void enter_coord_fence (void);

//fence display

void display_coord_fence (void);

//



enum boxes
{
    FREE, TAKEN, PAWN
};
typedef enum boxes boxes;

//

void availability_Box (void);

///
