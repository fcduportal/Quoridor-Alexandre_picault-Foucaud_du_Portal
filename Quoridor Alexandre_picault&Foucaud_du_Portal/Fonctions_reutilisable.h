/*
   Fonctions_reutilisable.h
   Quoridor Alexandre_picault&Foucaud_du_Portal
 
   Created by Foucaud de Bouët du Portal on 31/03/2020.
   Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



#define Fonctions_reutilisable_h

///

#include <time.h>

//

#define NB_CHAR 20

//

void clear_console (void);

//

void delay (void);

//

struct pion
{
    char name[NB_CHAR];
    int number_player;
    int number_fence;
    int x;
    int y;
};
typedef struct pion pion;

//

struct fence
{
    int x1;
    int y1;
    int x2;
    int y2;

};
typedef struct fence fence;

//

void enter_coord_Pion (void);

//

void display_coord_Pion (void);

//

void tester_barrier (fence Barrier);
void switchtest (int test, fence Barrier);

//

void enter_coord_fence (void);

//

void display_coord_fence (void);

///
