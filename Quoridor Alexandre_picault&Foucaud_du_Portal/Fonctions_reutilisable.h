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



struct point
{
    int x,y;
};
typedef struct point point;







/// -------------------------------------------  fence



//structure for each fence used

struct fence
{
    point A,B;
};
typedef struct fence fence;

//define the position of a fence

 fence enter_coord_fence (int *board);


//verification that it is possible to place the fence

void tester_barrier (fence Barrier, int *board);
void switchtest_B (int test, fence Barrier, int *board);


//fence display

void display_coord_fence (void);



/// end fence -------------------------------------------  begin Pawn



//structure for each pawn used

struct pawn
{
    char name[NB_CHAR];
    int number_fence;
    point A, temp;
};
typedef struct pawn pawn;

//define the position of a pawn

void enter_coord_Pawn (int *board, pawn player);

//pawn display

void display_coord_Pawn (pawn player);

//

void tester_Pawn (pawn player, int *board);
void switchtest_P (int test, pawn player, int *board);



/// end Pawn-------------------------------------------- Begin boxes



enum boxes
{
    FREE, TAKEN, PAWN
};
typedef enum boxes boxes;

//







int availability_Box (point M, int *board);




/// end boxes-------------------------------------------- 
