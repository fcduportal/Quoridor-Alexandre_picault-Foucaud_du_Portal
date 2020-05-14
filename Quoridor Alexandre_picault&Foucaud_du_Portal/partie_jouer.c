/*
 partie_jouer.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Alexandre Picault on 25/04/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */


///

#include "header.h"

//play a fence

void playFence (pawn player[], int digit_Player, plateau plateau)
{
    fence Barrier;
    
    printf("Il vous reste %d barrières\n",player[digit_Player].number_fence);
    switch (player[digit_Player].number_fence)
    {
        case 0:
        {
            printf("Vous n'avez plus de barrieres.\nVeuillez déplacer votre pion.");
            playPawn(*player, plateau);
            break;
        }
            
        default:
        {
            Barrier = enter_coord_fence();
            
            printf("play fence : barriere : (%d;%d), (%d;%d)\t", Barrier.A.x, Barrier.A.y, Barrier.B.x, Barrier.B.y);
            
            tester_barrier(Barrier, plateau);
            
            plateau.board[Barrier.A.x][Barrier.A.y] = TAKEN;
            plateau.board[Barrier.B.x][Barrier.B.y] = TAKEN;
            display_coord_fence();
            
            printf("\ndigit player : %d / number fence : %d\t ",digit_Player, player[digit_Player].number_fence );
            player[digit_Player].number_fence--;
            printf("\ndigit player : %d / number fence : %d\t ",digit_Player, player[digit_Player].number_fence );
            
            break;
        }
    }
    
    //
}

//play a pawn

void playPawn (pawn player, plateau plateau)
{
    display_coord_Pawn(player);
    enter_coord_Pawn(player, plateau);
    
}
