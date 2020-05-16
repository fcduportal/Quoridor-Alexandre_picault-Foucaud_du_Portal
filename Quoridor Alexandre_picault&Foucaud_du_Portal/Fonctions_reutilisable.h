/*
 Fonctions_reutilisable.h
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 31/03/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



#define Fonctions_reutilisable_h

//

#include <time.h>
#define NB_CHAR 15

//this part is used for all the functions in we will need many times


//

void clear_console (void);



struct point
{
    int ligne,colonne;
};
typedef struct point point;



struct plateau
{
    int board [9][9];
};
typedef struct plateau Plateau;






// -------------------------------------------  fence



//structure for each fence used

struct fence
{
    point A,B;
};
typedef struct fence fence;

//define the position of a fence

fence enter_coord_fence (void);

//fence display

void display_coord_fence (fence barrier);



// end fence -------------------------------------------  begin Pawn



//structure for each pawn used

struct Player
{
    char name[NB_CHAR];
    int number_fence;
    point position, temp;
    int affichage ;
};
typedef struct Player Player;

//define the position of a Player

point enter_coord_Pawn (void);

//Player display

void display_coord_Pawn (Player player);

//

int tester_adjacent (point M, point N);
int switchtest_adjacent (int test, point M, point N, Plateau plateau);

//int tester_Pawn (Player player, plateau plateau);
//int switchtest_P (int test, Player player, plateau plateau);



// end Pawn-------------------------------------------- Begin boxes



enum boxes
{
    FREE, TAKEN, PAWN
};
typedef enum boxes boxes;

//



int availability_Box (point M, Plateau *plateau);

// end boxes--------------------------------------------



int sablier (int *duration, time_t t_debut);

int gagnant (Player *player);

void display_board (Plateau *plateau, Player player[], int nb_player);

void display_name_player (Player player);

void display_abscisses(void);

void display_lines (void);
