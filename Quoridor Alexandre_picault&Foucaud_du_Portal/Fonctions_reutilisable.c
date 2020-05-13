/*
 Fonctions_reutilisable.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 31/03/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



#ifndef Fonctions_reutilisable_h
#define Fonctions_reutilisable_h

///

#include "header.h"

//

void clear_console (void)
{
    usleep(1000000);
    usleep(1000000);
    printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // To erase console, not great but its work.
}

//



/// -------------------------------------------  fence



fence enter_coord_fence (int *board)
{
    fence Barrier;
    
    printf("Veuiilez saisir l'abscisse 1 (x1) de l'emplacement souhaite :\t");
    scanf("%d",&Barrier.A.x);
    printf("Veuiilez saisir l'ordonnee 1 (y1) de l'emplacement souhaite :\t");
    scanf("%d",&Barrier.A.y);
    printf("Veuiilez saisir l'abscisse 2 (x2) de l'emplacement souhaite :\t");
    scanf("%d",&Barrier.B.x);
    printf("Veuiilez saisir l'ordonnee 2 (y2) de l'emplacement souhaite :\t");
    scanf("%d",&Barrier.B.y);
    
    tester_barrier(Barrier, board);
    
    return Barrier;
}

//

void tester_barrier (fence Barrier, int *board)
{
    int test=0;
    if (Barrier.A.x == Barrier.B.x)
    {
        test = Barrier.A.y-Barrier.B.y;
        switchtest_B(test, Barrier, board);
    }
    
    else if (Barrier.A.y == Barrier.B.y)
    {
        test = Barrier.A.x-Barrier.B.x;
        switchtest_B(test, Barrier, board);
    }
    else
    {
        printf("Votre barriere doit etre place sur deux cases adjacentes.\n");
        clear_console();
        enter_coord_fence(board);
    }
    
    
    if (availability_Box(Barrier.A, board)==0 || availability_Box(Barrier.B, board)==0)
    {
        printf("envoyer les coordonées au tableau");
    }
    else
    {
        printf("Une case n'est pas libre. Pauv naze\n");
        enter_coord_fence(board);
    }
}

//



void switchtest_B (int test, fence Barrier, int *board)
{
    if(test == 1 || test== -1)
    {
    }
    else
    {
        printf("Votre barriere doit etre place sur deux cases adjacentes.\n");
        clear_console();
        enter_coord_fence(board);
    }
}

//

void display_coord_fence (void)
{
    fence barrier;
    
    printf("Votre barrière est en : (%d;%d) et (%d;%d)\n", barrier.A.x, barrier.A.y, barrier.B.x, barrier.B.y);
    clear_console();
}

//



/// end fence -------------------------------------------  begin Pawn



void enter_coord_Pawn (int *board, pawn player)
{
    
    
    printf("Veuiilez saisir l'abscisse (x) de l'emplacement souhaite :\t");
    scanf("%d",&player.temp.x);
    printf("Veuiilez saisir l'ordonnee (y) de l'emplacement souhaite :\t");
    scanf("%d",&player.temp.y);
    
    tester_Pawn(player, board);
    
}

//

void tester_Pawn (pawn player, int *board)
{
    printf("coucou a : (%d,%d) , temp: (%d,%d)\n", player.A.x, player.A.y, player.temp.x, player.temp.y);
    int test=0;
    if (player.A.x == player.temp.x)
    {
        test = player.A.y-player.temp.y;
        switchtest_P(test, player, board);
    }
    else if (player.A.y == player.temp.y)
    {
        test = player.A.x-player.temp.x;
        switchtest_P(test, player, board);
    }
    else
    {
        printf("Votre pion doit etre place sur une case adjacente à la precedente.\n");
        enter_coord_Pawn(board, player);
    }

}

//

void switchtest_P (int test, pawn player, int *board)
{

            if (test==1 || test==-1)
            {
            }
            
        else
        {
            printf("Votre Pion doit etre place sur une case adjacente a la precedente.\n");
            clear_console();
            enter_coord_Pawn(board, player);
        }
            
            availability_Box(player.A, board);
}

//

void display_coord_Pawn (pawn player)
{
    printf("Votre pion est en (%d;%d)\n", player.A.x, player.A.y);
}

//

/// end Pawn-------------------------------------------- Begin boxes



int availability_Box (point M, int *board)
{
    int tableau [9][9] = {TAKEN};
    
    
    if (tableau[M.x][M.y] != FREE)
    {
        printf("Vous ne pouvez pas placer votre barrierre ici, la case est déjà prise.\n");
        clear_console();
        enter_coord_fence(board);
        return EXIT_FAILURE;
    }
    else
    {
        printf("La case est libre (%d,%d)\n", M.x, M.y);
        return EXIT_SUCCESS;
    }
}



///end boxes-------------------------------------------- 



#endif /* Fonctions_reutilisable_h */
