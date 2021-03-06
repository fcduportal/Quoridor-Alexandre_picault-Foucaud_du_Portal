/*
 main.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 15/03/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



///

#include "header.h"

//


// test
// Cocucocu kelian


int main()
{
    Plateau plateau = {-1};
    for (int i = 0; i < 9; i++)
    {
        for (int j=0; j < 9; j++)
        {
            plateau.board[i][j] = FREE;
        }
    }
    
    
    int nbPlayers = 0, duration = 0;
    Player player[4];
    
    //
    

    startingInfos(&nbPlayers, &duration, player); //  Call fonction to ask the first info in order to adress differents rules to the game.
    
    //
    
    switch (nbPlayers) // play in fonction of the number of players
    {
        case 1:
        {
            onePlayer(player, nbPlayers, plateau, &duration);
            
            break;
        }
            
        case 2: // play 2
        {
            twoPlayers(player, nbPlayers, plateau, &duration);
            
            break;
        }
            
        case 4: // play 4
        {
            fourPlayers(player, nbPlayers, plateau, &duration);
            
            break;
        }
    }
    
    clearConsole();
    
    
    int restart = 0;
    printf("Voulez vous recommencer?\n1.OUI\n2.NON\n");
    scanf("%d",&restart);
    switch (restart)
    {
        case 1:
        {
            clearConsole();
            main();
            break;
        }
            
        case 2:
        {
            printf("Bonne nuit.\n");
            break;
        }
            
        default:
        {
            printf("Vous n'aviez qu'a suivre les consignes. Vous ne recommencerez pas. :( \n");
            break;
        }
    }
    return EXIT_SUCCESS;
}

///
