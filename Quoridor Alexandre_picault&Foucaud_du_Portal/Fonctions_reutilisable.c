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




void saisir_coord_Pion (coordinates *point)
{
    pion player1;
    
    printf("Ou voulez vous aller ?\n");
    printf("Entrez l'abcisse du point :\n");
    scanf("%d",&player1.coord.x);
    printf("Entrez l'ordonnees du point :\n");
    scanf("%d",&player1.coord.y);

}


void afficher_coord_Pion (coordinates *point)
{
    pion player1;
    printf("Votre piont est à la case de coordonees x: %d et y: %d",player1.coord.x, player1.coord.y);
}
