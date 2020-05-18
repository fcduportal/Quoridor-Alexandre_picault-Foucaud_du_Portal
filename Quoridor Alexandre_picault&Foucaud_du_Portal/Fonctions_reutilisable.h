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

void clearConsole (void);



struct point
{
    int line,column;
};
typedef struct point point;



struct plateau
{
    int board [9][9];
};
typedef struct plateau Plateau;






// -------------------------------------------  Fence



//structure for each Fence used

struct fence
{
    point A,B;
};
typedef struct fence Fence;

//define the position of a Fence

Fence enterCoordFence (void);




// end Fence -------------------------------------------  begin Pawn



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

//

int testAdjacent (point M, point N);
int switchtest_adjacent (int test, point M, point N, Plateau plateau);






// end Pawn-------------------------------------------- Begin boxes



enum boxes
{
    FREE, TAKEN, PAWN
};
typedef enum boxes boxes;

enum boxesOrdi
{
    BANNED, POSSIBLE
};
typedef enum boxesOrdi boxesOrdi;

//



int availabilityBox (point M, Plateau *plateau);

// end boxes--------------------------------------------



int hourglass (int *duration, time_t t_debut);

int gagnant (Player *player);

void display_board (Plateau *plateau, Player player[], int nb_player);

void displayPlayerName (Player player, char c1, char c2);

void displayAbscisses(char c1, char c2);

void displayLines (char c1, char c2);

void displayEmptyLine (char c1, char c2);

point enterLinesColumns (void);





struct PointCalcul
{
    point p;
    int ValeurAssigneeOrdi;
};
typedef struct PointCalcul PointCalcul;




struct PointsAdjacents
{
    PointCalcul droite, gauche, devant, derriere;
};
typedef struct PointsAdjacents PointsAdjacents;





point initialiserPointsAdjacentsPion (int ligne, int colonne, Plateau *plateau, Plateau *plateauOrdi);

