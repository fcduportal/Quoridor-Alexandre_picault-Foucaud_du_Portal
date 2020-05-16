/*
 partie_jouer.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Alexandre Picault on 25/04/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */


///

#include "header.h"

//play a fence

int playFence (Player player[], int digit_Player, Plateau *plateau)
{
    fence Barrier;
    
    printf("\n%s : Il vous reste %d barrières\n",player[digit_Player].name,player[digit_Player].number_fence);
    
    switch (player[digit_Player].number_fence)
    {
        case 0:
        {
            printf("Vous n'avez plus de barrieres.\nVeuillez déplacer votre pion.\n");
            return EXIT_FAILURE;
            break;
        }
            
        default:
        {
            Barrier = enter_coord_fence();
            
            if (tester_adjacent(Barrier.A, Barrier.B) == EXIT_SUCCESS)
            {
                if (availability_Box(Barrier.A, plateau) == EXIT_SUCCESS)
                {
                    if (availability_Box(Barrier.B, plateau) == EXIT_SUCCESS)
                    {
                        plateau->board[Barrier.A.ligne][Barrier.A.colonne] = TAKEN;
                        plateau->board[Barrier.B.ligne][Barrier.B.colonne] = TAKEN;
                        
                        player[digit_Player].number_fence--;
                        return EXIT_SUCCESS;
                    }
                }
            }
            break;
        }
    }
return EXIT_FAILURE;


}



//play a pawn

int playPawn (Player player[], Plateau *plateau)
{
    
    player->temp = enter_coord_Pawn();
    
    if (tester_adjacent(player->position, player->temp) == EXIT_SUCCESS)
    {
        if (availability_Box(player->temp, plateau) == EXIT_SUCCESS)
        {
            plateau->board[player->temp.ligne][player->temp.colonne] = PAWN;
            plateau->board[player->position.ligne][player->position.colonne] = FREE;
            
            player->position = player->temp;
            player->temp.ligne = -1;
            player->temp.colonne = -1;
            
            
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}
