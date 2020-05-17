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
    Plateau plateau = {-1};
    for (int i = 0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
            plateau.board[i][j]=FREE;
        }
    }
    
    
    int nbPlayers = 0, duration = 0;
    Player player[4];
    
    //
    
    info_start(&nbPlayers, &duration, player); //  Call fonction to ask the first info in order to adress differents rules to the game.
    
    //
    
    switch (nbPlayers) // play in fonction of the number of players
    {
        case 1:
        {
            Game_one_Player(player, nbPlayers, plateau, &duration);
            
            break;
        }
            
        case 2: // play 2
        {
            Game_2_Players(player, nbPlayers, plateau, &duration);
            
            break;
        }
            
        case 4: // play 4
        {
            Game_4_Player(player, nbPlayers, plateau, &duration);
            
            break;
        }
    }
    
    clear_console();
    int recommencer=0;
    printf("Voulez vous recommencer?\n1.OUI\n2.NON\n");
    scanf("%d",&recommencer);
    switch (recommencer)
    {
        case 1:
            clear_console();
            main();
            break;
            
        case 2:
            printf("Bonne nuit.\n");
            break;
            
        default:
            printf("Vous n'aviez qu'a suivre les consignes. Vous ne recommencerez pas. :( \n");
            break;
    }
    return 0;
}

///
