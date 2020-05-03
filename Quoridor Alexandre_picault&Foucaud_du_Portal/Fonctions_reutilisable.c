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
    printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // To erase console, not great but its work.
}

//

void delay (void)
{
    usleep(1000000);
    usleep(100000);
}

//

void enter_coord_Pion (void)
{
    pion player; // Pour l'instant on met player1 mais après il vas falloir faire un tableau de player
    
    printf("Veuiilez saisir l'abscisse (x) de l'emplacement souhaite :™t");
    scanf("%d",&player.x);
    printf("Veuiilez saisir l'ordonnee (y) de l'emplacement souhaite :\t");
    scanf("%d",&player.y);
}

//

void display_coord_Pion (void)
{
    pion player;
    printf("Votre pion est en %d;%d\n", player.x, player.y);
}

//

void switchtest (int test, fence Barrier)
{
    switch (test)
    {
        case 1:
            printf("Votre barriere est place en %d; %d. et en %d; %d", Barrier.x1, Barrier.y1, Barrier.x2, Barrier.y2);
            break;
            
        case -1:
            printf("Votre barriere est place en %d; %d. et en %d; %d", Barrier.x1, Barrier.y1, Barrier.x2, Barrier.y2);
            break;

        default:
        {
            printf("Votre barriere doit etre place sur deux cases adjacentes.");
            delay();
            clear_console();
            enter_coord_fence();
        }
            break;
    }
}

//

void tester_barrier (fence Barrier)
{
    if (Barrier.x1 == Barrier.x2)
    {
        int test=0;
        test = Barrier.y1-Barrier.y2;
        
        switchtest(test, Barrier);
    }
    
    else if (Barrier.y1 == Barrier.y2)
    {
        int test=0;
        test = Barrier.x1-Barrier.x2;
        
        switchtest(test, Barrier);
    }
    else
    {
        printf("Votre barriere doit etre place sur deux cases adjacentes.");
        delay();
        clear_console();
        enter_coord_fence();
    }
}

//

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
    
    //
    
    tester_barriere(Barrier);
    
    //
    
}

//

void display_coord_fence (void)
{
    fence barrier;
    printf("Votre barrière est en : %d;%d et %d;%d\n", barrier.x1, barrier.y1, barrier.x2, barrier.y2);
    delay();
    clear_console();
}

///

#endif /* Fonctions_reutilisable_h */
