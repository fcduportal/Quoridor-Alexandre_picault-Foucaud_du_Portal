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
    Plateau plateau;
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
    
    info_start(&nbPlayers, &duration); //  Call fonction to ask the first info in order to adress differents rules to the game.
    
    //
    
    switch (nbPlayers) // play in fonction of the number of players
    {
        case 1:
        {
            printf("Faire le jeu avec un bot.\n");
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
            printf("Faire le jeu avec 4 joueurs\n");
            Game_4_Player(player, nbPlayers, plateau, &duration);
            
            break;
        }
    }
    
    // fonction recommencer
    
    return 0;
}

///
