/*
 2_Players.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 03/05/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



#include "header.h"

///

int Game_2_Players (Player player[], int nb_Players, Plateau plateau, int *duration)
{
    int digitPlayer=0, choice=0;
    
    char Foucaud[NB_CHAR] = "Foucaud", Alexandre[NB_CHAR] = "Alexandre";
    
    strcpy(player[0].name, Foucaud);
    strcpy(player[1].name, Alexandre);
    
    player[0].number_fence = NB_FENCE_MAX;
    player[1].number_fence = NB_FENCE_MAX;
    
    player[0].position.ligne = 0;
    player[0].position.colonne = 4;
    plateau.board[0][4] = PAWN;
    
    player[1].position.ligne = 8;
    player[1].position.colonne = 4;
    plateau.board[8][4] = PAWN;
    
    
    
    
    //    appel random (&)
    
    
    time_t t_debut=time(NULL);
    
    int boucle = -1;
    
    while (boucle!=0)
    {
        printf(" \nnom du joueur %s\n", player[digitPlayer].name);
        printf("Votre pion est en : (%d;%d) et il vous reste %d barrieres.\n\n", player[digitPlayer].position.ligne, player[digitPlayer].position.colonne, player[digitPlayer].number_fence);
        
        printf("Si vous voulez jouer une barriere taper 1 ou un pion taper 2:\t");
        scanf("%d",&choice);
        
        switch (choice)
        {
            case 1:
            {
                if (playFence(player, digitPlayer, &plateau) == EXIT_SUCCESS)
                {
                    digitPlayer = ((digitPlayer+1)%2);
                }
                break;
            }
                
                
            case 2:
            {
                
                if (playPawn(&player[digitPlayer], &plateau) == EXIT_SUCCESS)
                {
                    digitPlayer = ((digitPlayer+1)%2);
                }
                break;
            }
                
                
            default:
            {
                printf("Vous devez choisir 1 ou 2 :");
                break;
            }
        }
        
        if (sablier(duration, t_debut) == EXIT_SUCCESS) // il ne reste pas de temps
        {
        }
        else
        {
            printf("JE SUIS UN CONNARD");
            boucle=0;
        }

        
        if (gagnant(player) == EXIT_SUCCESS) // Quelqu'un a gagné
        {
            boucle=0;
        }
        else
        {
            printf("Je suis aussI UHN CONNARD");
        }
    }
    
    return 0;
}

///
