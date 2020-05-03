/*
   2_Players.c
   Quoridor Alexandre_picault&Foucaud_du_Portal
 
   Created by Foucaud de Bouët du Portal on 03/05/2020.
   Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



#include "header.h"

///

void Game_2_Player (void)
{
    
    //
    
    int choice=0;
    
    //
    
    printf("si vous voulez jouer une barriere taper 1 ou un pion taper 2:/n");
    scanf("%d",&choice);
    
    switch (choice)
    {
        case 1:
            playFence();
            // play fence there is 10 max
            break;
            
        case 2:
        {
            playPion();
            // play pion
        }
            break;
            
            
        default:
        {
            printf("Vous devez choisir 1 ou 2 :");
            delay();
            clear_console();
            Game_2_Player();
        }
            break;
    }
    
    //
    
}

///
