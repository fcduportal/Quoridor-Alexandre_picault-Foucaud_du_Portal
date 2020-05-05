/*
 partie_jouer.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Alexandre Picault on 25/04/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */


///

#include "header.h"

//play a fence

void playFence (pawn player)
{
    printf("Il vous reste %d barrières\n",player.number_fence);
    switch (player.number_fence)
    {
        case 0:
        {
            printf("Vous n'avez plus de barrieres.\nVeuillez déplacer votre pion.");
            playPawn(player);
            break;
        }
            
        default:
        {
            enter_coord_fence();
            availability_Box();
            display_coord_fence();
            break;
        }
    }
    
    //
}

//play a pawn

void playPawn (pawn player)
{
    display_coord_Pawn();
    enter_coord_Pawn();
    availability_Box();
}
