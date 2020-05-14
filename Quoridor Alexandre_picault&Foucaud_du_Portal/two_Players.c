/*
 2_Players.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 03/05/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



#include "header.h"

///

int Game_2_Player (pawn player[], int nb_Players, plateau plateau, int *duration)
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
    
    time_t t_debut=time(NULL);
    
    printf("\ndigit player : %d",digit_Player);
    
    printf("Si vous voulez jouer une barriere taper 1 ou un pion taper 2:\n");
    scanf("%d",&choice);
    
    switch (choice)
    {
        case 1:
        {
            playFence(&player[digit_Player], digit_Player, plateau);
            digit_Player = ((digit_Player+1)%2);
            
            break;
        }
            
            
        case 2:
        {
            playPawn(player[digit_Player], plateau);
            digit_Player = ((digit_Player+1)%2);
            break;
        }
            
            
        default:
        {
            printf("Vous devez choisir 1 ou 2 :");
            clear_console();
            // appel fonction sablier
//            Game_2_Player(player, nb_Players, plateau, &duration);
            
            break;
        }
    }
    
    if (sablier(duration, t_debut) == 0)
    {
        Game_2_Player(player, nb_Players, plateau, duration);
    }
    else
    {
        return 0;
    }

    return 0;
}

///
