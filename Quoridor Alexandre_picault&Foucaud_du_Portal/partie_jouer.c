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
            
            if (test_adjacent(Barrier.A, Barrier.B) == EXIT_SUCCESS)
            {
                if (availability_Box(Barrier.A, plateau) == EXIT_SUCCESS)
                {
                    if (availability_Box(Barrier.B, plateau) == EXIT_SUCCESS)
                    {
                        plateau->board[Barrier.A.line][Barrier.A.column] = TAKEN;
                        plateau->board[Barrier.B.line][Barrier.B.column] = TAKEN;
                        
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
    
    if (test_adjacent(player->position, player->temp) == EXIT_SUCCESS)
    {
        if (availability_Box(player->temp, plateau) == EXIT_SUCCESS)
        {
            plateau->board[player->temp.line][player->temp.column] = PAWN;
            plateau->board[player->position.line][player->position.column] = FREE;
            
            player->position = player->temp;
            player->temp.line = -1;
            player->temp.column = -1;
            
            
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}
