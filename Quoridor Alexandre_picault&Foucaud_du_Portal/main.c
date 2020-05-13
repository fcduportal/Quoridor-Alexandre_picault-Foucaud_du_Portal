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
    // fonction_a_tester();
    
    int nb_Players = 0, duration = 0, digit_player =0;
    pawn *player = NULL; // This pointer will be used as an array after the malloc's call...
    
    
    
    info_start(&nb_Players, &duration); //  Call fonction to ask the first info in order to adress differents rules to the game.
    
    
    
    
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
            printf("Faire le jeu avec 2 joueurs\n"); 
            Game_2_Player(&player[digit_player], nb_Players);
            
            break;
        }
            
        case 4: // play 4
        {
            printf("Faire le jeu avec 4 joueurs\n");
            Game_4_Player(&player[digit_player], nb_Players);
            
            break;
        }
    }
    
    
    
    // fonction recommencer
    
    return EXIT_SUCCESS;
}

///

