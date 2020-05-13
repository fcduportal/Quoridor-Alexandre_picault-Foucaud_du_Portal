//
//  One_player.c
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Foucaud de Bouët du Portal on 12/05/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//

#include "header.h"

int Game_one_Player (pawn player[], int nb_Players)
{
    nb_Players+=1;
    player = malloc(nb_Players * sizeof(int)); // Memory is allocated for the array
    if (player == NULL) // Checking to see if allocation worked
    {
        return EXIT_FAILURE; // Stop because malloc didn't worked
    }
    
    // free memory gave to the malloc
    free(player);
    return EXIT_SUCCESS;
}
