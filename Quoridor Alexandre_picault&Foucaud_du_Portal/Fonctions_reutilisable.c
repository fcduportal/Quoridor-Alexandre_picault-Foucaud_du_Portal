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



void enter_coord_fence (void)
{
    fence Barrier; // Pour l'instant on met barrier1 mais après il vas falloir faire un tableau de barrier
    
    printf("Veuiilez saisir l'abscisse 1 (x1) de l'emplacement souhaite :\t");
    scanf("%d",&Barrier.x1);
    printf("Veuiilez saisir l'ordonnee 1 (y1) de l'emplacement souhaite :\t");
    scanf("%d",&Barrier.y1);
    printf("Veuiilez saisir l'abscisse 2 (x2) de l'emplacement souhaite :\t");
    scanf("%d",&Barrier.x2);
    printf("Veuiilez saisir l'ordonnee 2 (y2) de l'emplacement souhaite :\t");
    scanf("%d",&Barrier.y2);
    
    tester_barrier(Barrier);
}

//

void tester_barrier (fence Barrier)
{
    int test=0;
    if (Barrier.x1 == Barrier.x2)
    {
        test = Barrier.y1-Barrier.y2;
        switchtest_B(test, Barrier);
    }
    
    else if (Barrier.y1 == Barrier.y2)
    {
        test = Barrier.x1-Barrier.x2;
        switchtest_B(test, Barrier);
    }
    else
    {
        printf("Votre barriere doit etre place sur deux cases adjacentes.\n");
        clear_console();
        enter_coord_fence();
    }
}

//

void switchtest_B (int test, fence Barrier)
{
    if(test == 1 || test== -1){
        availability_Box();
    }
    else
    {
        printf("Votre barriere doit etre place sur deux cases adjacentes.\n");
        clear_console();
        enter_coord_fence();
    }
}

//

void display_coord_fence (void)
{
    fence barrier;
    
    printf("Votre barrière est en : %d;%d et %d;%d\n", barrier.x1, barrier.y1, barrier.x2, barrier.y2);
    clear_console();
}

//



/// end fence -------------------------------------------  begin Pawn



void enter_coord_Pawn (void)
{
    pawn player; // Pour l'instant on met player1 mais après il vas falloir faire un tableau de player
    
    printf("Veuiilez saisir l'abscisse (x) de l'emplacement souhaite :™t");
    scanf("%d",&player.x);
    printf("Veuiilez saisir l'ordonnee (y) de l'emplacement souhaite :\t");
    scanf("%d",&player.y);
    
    tester_Pawn(player);
    
}

//

void tester_Pawn (pawn player)
{
    int test=0;
    if (player.x == player.xtemp)
    {
        test = player.x-player.xtemp;
        switchtest_P(test, player);
    }
}

//

void switchtest_P (int test, pawn player)
{
    switch (test)
    {
        case 1:
            break;
            
        case -1:
            break;
            
        default:
        {
            printf("Votre Pion doit etre place sur une case adjacente a la precedente.\n");
            clear_console();
            enter_coord_Pawn();
        }
            break;
    }
}

//

void display_coord_Pawn (void)
{
    pawn player;
    printf("Votre pion est en %d;%d\n", player.x, player.y);
}

//

/// end Pawn-------------------------------------------- Begin boxes



void availability_Box (void)
{
    
    boxes box = FREE; // il faudra le bouger

    if (box != FREE)
    {
        printf("Vous ne pouvez pas placer votre barrierre ici, la case est déjà prise.\n");
        clear_console();
        enter_coord_fence();
    }
}



///end boxes-------------------------------------------- 






#endif /* Fonctions_reutilisable_h */
