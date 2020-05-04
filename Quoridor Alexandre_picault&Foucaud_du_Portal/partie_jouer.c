/*
 partie_jouer.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Alexandre Picault on 25/04/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */


///

#include "header.h"

//play a fence

void playFence (void)
{
    
    //
    
    pion player1 = {"",1,10,0,0}; // Pour l'instant on met player1 mais après il vas falloir faire un tableau de player
    
    //
    
    printf("Il vous reste %d barrières\n",player1.number_fence);
    switch (player1.number_fence)
    {
        case 0:
        {
            printf("Vous n'avez plus de barrieres.\nVeuillez déplacer votre pion.");
            //play a pawn
        }
            break;
            
        default:
        {
            enter_coord_fence();
            display_coord_fence();
        }
            break;
    }
    
    //
}

//play a pawn

void playPion (void)
{
    // enter code here
}
