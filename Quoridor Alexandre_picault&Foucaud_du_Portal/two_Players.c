/*
 2_Players.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 03/05/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



#include "header.h"

///

int Game_2_Player (pawn player[], int nb_Players, plateau plateau)
{

    

    
    
    
    int digit_Player=0, choice=0;
    
    player[0].number_fence = NB_FENCE_MAX;
    player[1].number_fence = NB_FENCE_MAX;
    
    player[0].A.x = 4;
    player[0].A.y = 0;
    plateau.board[4][0] = PAWN;
    
    player[1].A.x = 4;
    player[1].A.y = 8;
    plateau.board[4][8] = PAWN;


    
    //    appel random (&)
    
    
    printf("Si vous voulez jouer une barriere taper 1 ou un pion taper 2:\n");
    scanf("%d",&choice);
    
    switch (choice)
    {
        case 1:
        {
            playFence(&player[digit_Player], digit_Player, plateau);
            break;
        }
            
            
        case 2:
        {
            playPawn(player[digit_Player], plateau);
            break;
        }
            
            
        default:
        {
            printf("Vous devez choisir 1 ou 2 :");
            clear_console();
            Game_2_Player(player, nb_Players, plateau);
            break;
        }
            
    }
    
    
    
    // rappel de la fonction avec le deuxieme player
    

    
    
    return 0;
    
}

///
