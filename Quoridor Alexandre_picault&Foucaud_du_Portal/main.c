/*
 main.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 15/03/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



///

#include "header.h"

//

int main()
{
    plateau plateau;
    
    for (int i = 0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
            plateau.board[i][j]=FREE;
        }
    }
    
    // fonction_a_tester();
    
    int nb_Players = 0, duration = 0, digit_player =0;
    pawn *player = NULL; // This pointer will be used as an array after the malloc's call...
    

    
    info_start(&nb_Players, &duration); //  Call fonction to ask the first info in order to adress differents rules to the game.
    

    int test=111;
    
    switch (nb_Players) // play in fonction of the number of players
    {
        case 1:
        {
            printf("Faire le jeu avec un bot.\n");
            Game_one_Player(&player[digit_player], nb_Players);

            break;
        }
            
        case 2: // play 2
        {
            
            player = malloc(nb_Players * sizeof(pawn)); // Memory is allocated for the array
            if (player == NULL) // Checking to see if allocation worked
            {
                return EXIT_FAILURE; // Stop because malloc didn't worked
            }
            
            test = Game_2_Player(&player[digit_player], nb_Players, plateau, &duration);
            
            printf("\nAvant free memory\n");
            
            // free memory gave to the malloc
            free(player);
            
            printf("\nApres free memory\n");
            
            printf("Avant break : test : %d\n", test);
            
            break;
        }
            
        case 4: // play 4
        {
            printf("Faire le jeu avec 4 joueurs\n");
            Game_4_Player(&player[digit_player], nb_Players, plateau);
            
            break;
        }
    }
    
    printf("Avant exit success : test : %d\n", test);
    
    // fonction recommencer
    
    return 0;
}

///

