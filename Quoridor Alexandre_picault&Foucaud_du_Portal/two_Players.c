/*
 2_Players.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 03/05/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



#include "header.h"

///

int Game_2_Player (pawn player[], int nb_Players)
{
    
    
                player = malloc(nb_Players * sizeof(int)); // Memory is allocated for the array
                if (player == NULL) // Checking to see if allocation worked
                {
                    return EXIT_FAILURE; // Stop because malloc didn't worked
                }
    
    //
    
    int choice=0;
    
    //
    
    printf("si vous voulez jouer une barriere taper 1 ou un pion taper 2:\n");
    scanf("%d",&choice);
    
    switch (choice)
    {
        case 1:
        {
            playFence(player[0]); // j'ai mis 0 mais il va falloir mettre le numero du joueur
            // play fence there is 10 max
            break;
        }
            
            
        case 2:
        {
            playPawn(player[0]); // idem
            // play pawn
            break;
        }
            
            
        default:
        {
            printf("Vous devez choisir 1 ou 2 :");
            clear_console();
            Game_2_Player(player, nb_Players);
            break;
        }
            
    }
    
    // free memory gave to the malloc
    free(player);
    return EXIT_SUCCESS;
    
}

///
