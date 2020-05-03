//
//  partie_jouer.c
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Alexandre Picault on 25/04/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//


#include "header.h"

void play (void)
{
    int choice=0;
    
    printf("si vous voulez jouer une barriere taper 1 ou un pion taper 2:/n");
    scanf("%d",&choice);
    
    switch (choice)
    {
        case 1:
            // play fence
            break;
            
        case 2:
        {
            // play pion
        }
            break;
            
            
        default:
        {
            printf("Vous devez choisir 1 ou 2 :");
            delay();
            play();
        }
            break;
    }
}


void playfence (void)
{
    
    pion player1 = {"",1,10,0,0}; // Pour l'instant on met player1 mais après il vas falloir faire un tableau de player
    
    
    printf("Il vous reste %d barrières\n",player1.number_fence);
    switch (player1.number_fence)
    {
        case 0:
            {
                printf("Vous n'avez plus de barrierres.\nVeuillez déplacer votre pion.");
                play();
            }
            break;
            
        default:
        {
            enter_coord_fence();
            print_coord_fence();
        }
        break;
    }
}
