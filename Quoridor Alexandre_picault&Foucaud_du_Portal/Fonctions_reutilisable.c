//
//  Fonctions_reutilisable.c
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Foucaud de Bouët du Portal on 31/03/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//



#ifndef Fonctions_reutilisable_h
#define Fonctions_reutilisable_h

#include <stdio.h>
#include <stdlib.h>
#include "Fonctions_reutilisable.h"


void clear_console (void)
{
    printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // To erase console, not great but its work.
}



void delay (void)
{
    usleep(1000000);
}


#endif /* Fonctions_reutilisable_h */


void enter_coord_Pion (void)
{
    pion player1; // Pour l'instant on met player1 mais après il vas falloir faire un tableau de player
    
    printf("Veuiilez saisir l'abscisse (x) de l'emplacement souhaite :™t");
    scanf("%d",&player1.x);
    printf("Veuiilez saisir l'ordonnee (y) de l'emplacement souhaite :\t");
    scanf("%d",&player1.y);
}

void print_coord_Pion (void)
{
    pion player1;
    printf("Votre pion est en %d;%d\n", player1.x, player1.y);
    
}


void enter_coord_fence (void)
{
    fence Barrier1; // Pour l'instant on met barrier1 mais après il vas falloir faire un tableau de barrier
    
    printf("Veuiilez saisir l'abscisse 1 (x1) de l'emplacement souhaite :\t");
    scanf("%d",&Barrier1.x1);
    printf("Veuiilez saisir l'ordonnee 1 (y1) de l'emplacement souhaite :\t");
    scanf("%d",&Barrier1.y1);
    printf("Veuiilez saisir l'abscisse 2 (x2) de l'emplacement souhaite :\t");
    scanf("%d",&Barrier1.x2);
    printf("Veuiilez saisir l'ordonnee 2 (y2) de l'emplacement souhaite :\t");
    scanf("%d",&Barrier1.y2);
}

void print_coord_fence (void)
{
    fence barrier1;
    printf("Votre barrière est en : %d;%d et %d;%d\n", barrier1.x1, barrier1.y1, barrier1.x2, barrier1.y2);
    delay();
    clear_console();
}
