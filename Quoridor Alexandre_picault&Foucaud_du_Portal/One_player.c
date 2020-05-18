//
//  One_player.c
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Foucaud de Bouët du Portal on 12/05/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//

#include "header.h"

int Game_one_Player (Player player[], int nb_Players, Plateau plateau, int *duration)
{
    nb_Players+=1;
    int digit_Player=0, choice=0;
    
    Plateau plateauOrdi;
    for (int i = 0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
            plateauOrdi.board[i][j]=POSSIBLE;
        }
    }
    
    char Foucaud[NB_CHAR] = "Foucaud", BOT[NB_CHAR] = "BOT";

    strcpy(player[JOUEUR].name, Foucaud);
    strcpy(player[ORDI].name, BOT);
    
    
    player[0].number_fence = NB_FENCE_MAX;
    player[1].number_fence = NB_FENCE_MAX;
    
    player[0].position.line = 0;
    player[0].position.column = 4;
    plateau.board[0][4] = PAWN;
    
    player[1].position.line = 8;
    player[1].position.column = 4;
    plateau.board[8][4] = PAWN;
    
    for (int i = 0; i<nb_Players; i++)
    {
        player[i].affichage = i+1;
    }
    
    
    digit_Player = choice_player(nb_Players);
    
    
    time_t t_debut=time(NULL);
    
    int boucle = -1;
    
    while (boucle!=0)
    {
        
        display_board(&plateau, player, nb_Players);

        if (digit_Player == ORDI)
        {
            playBot(player, &plateau, &plateauOrdi);
            digit_Player = ((digit_Player+1)%2);
        }
        else
        {
            int columnChar = NUMBER_ASCII(player[digit_Player].position.column);
            printf(" \nnom du joueur %s\n", player[digit_Player].name);
            printf("%s : Votre pion est en : (%c;%d) et il vous reste %d barrieres.\n\n", player[digit_Player].name, columnChar, player[digit_Player].position.line, player[digit_Player].number_fence);
            
            printf("Si vous voulez jouer une barriere taper 1 ou un pion taper 2:\t");
            scanf("%d",&choice);
            
            switch (choice)
            {
                case 1:
                {
                    if (playFence(player, digit_Player, &plateau) == EXIT_SUCCESS)
                    {
                        digit_Player = ((digit_Player+1)%2);
                    }
                    break;
                }
                    
                    
                case 2:
                {
                    
                    if (playPawn(&player[digit_Player], &plateau) == EXIT_SUCCESS)
                    {
                        digit_Player = ((digit_Player+1)%2);
                    }
                    break;
                }
                    
                    
                default:
                {
                    printf("Vous devez choisir 1 ou 2 :");
                    break;
                }
            }
        }
        
        if (sablier(duration, t_debut) != EXIT_SUCCESS || gagnant(player) == EXIT_SUCCESS) // il ne reste plus de temps ou un joueur a gagne la partie.
        {
            printf("\nFin de Partie.\n");
            boucle=0;
        }    }
    
    return 0;
    
    return EXIT_SUCCESS;
}
