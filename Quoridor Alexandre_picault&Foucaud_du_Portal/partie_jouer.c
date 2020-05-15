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
            int test = -1;
            
            test = tester_adjacent(Barrier.A, Barrier.B);
            if (test == EXIT_SUCCESS)
            {
                if (availability_Box(Barrier.A, plateau) == EXIT_SUCCESS)
                {
                    if (availability_Box(Barrier.B, plateau) == EXIT_SUCCESS)
                    {
                        plateau->board[Barrier.A.ligne][Barrier.A.colonne] = TAKEN;
                        plateau->board[Barrier.B.ligne][Barrier.B.colonne] = TAKEN;
                        display_coord_fence(Barrier);
                        player[digit_Player].number_fence--;
                        return EXIT_SUCCESS;
                    }
                }
            }
            else
            {
                return EXIT_FAILURE;
            }
            
            break;
        }
    }
    return EXIT_SUCCESS;
}



//play a pawn

int playPawn (Player player[], Plateau *plateau)
{
    int test = -1;
    
    display_coord_Pawn(*player);
    player->temp = enter_coord_Pawn();
    
    test = tester_adjacent(player->position, player->temp);
    if (test == EXIT_SUCCESS)
    {
        if (availability_Box(player->temp, plateau) == EXIT_SUCCESS)
        {
            plateau->board[player->temp.ligne][player->temp.colonne] = PAWN;
            plateau->board[player->position.ligne][player->position.colonne] = FREE;
            
            player->position = player->temp;
            player->temp.ligne = -1;
            player->temp.colonne = -1;
            
            display_coord_Pawn(*player);
            return EXIT_SUCCESS;
        }
    }
    else
    {
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
