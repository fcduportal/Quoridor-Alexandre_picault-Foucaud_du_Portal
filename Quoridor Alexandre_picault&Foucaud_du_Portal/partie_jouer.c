/*
 partie_jouer.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Alexandre Picault on 25/04/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */


///

#include "header.h"

//play a Fence

int playFence (Player player[], int digitPlayer, Plateau *Plateau)
{
    Fence Barrier;
    
    switch (player[digitPlayer].number_fence)
    {
        case 0:
        {
            printf("Vous n'avez plus de barrieres.\nVeuillez déplacer votre pion.\n");
            return EXIT_FAILURE;
            break;
        }
            
        default:
        {
            Barrier = enterCoordFence();
            
            if (testAdjacent(Barrier.A, Barrier.B) == EXIT_SUCCESS)
            {
                if (availabilityBox(Barrier.A, Plateau) == EXIT_SUCCESS)
                {
                    if (availabilityBox(Barrier.B, Plateau) == EXIT_SUCCESS)
                    {
                        Plateau->board[Barrier.A.line][Barrier.A.column] = TAKEN;
                        Plateau->board[Barrier.B.line][Barrier.B.column] = TAKEN;
                        
                        player[digitPlayer].number_fence--;
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
    
    if (testAdjacent(player->position, player->temp) == EXIT_SUCCESS)
    {
        if (availabilityBox(player->temp, plateau) == EXIT_SUCCESS)
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
