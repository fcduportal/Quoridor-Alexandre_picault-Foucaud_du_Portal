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
    
    char foucaud[NB_CHAR] = "Foucaud", Alexandre[NB_CHAR] = "Alexandre";
    
    strcpy(player[0].name, foucaud);
    strcpy(player[1].name, Alexandre);
    
    for (int i = 0; i<2; i++)
    {
        player[i].number_fence = NB_FENCE_MAX;
    }
    
    player[0].position.ligne = 4;
    player[0].position.colonne = 0;
    plateau.board[4][0] = PAWN;
    
    player[1].position.ligne = 4;
    player[1].position.colonne = 8;
    plateau.board[4][8] = PAWN;
    
    
    
    //    appel random (&)
    
    
    
    time_t t_debut=time(NULL);
    
    int boucle = -1;
    
    while (boucle!=0)
    {
        printf(" \nnom du joueur %s\n", player[digit_Player].name);
        printf("Votre pion est en : (%d;%d) et il vous reste %d barrieres.\n\n", player[digit_Player].position.ligne, player[digit_Player].position.colonne, player[digit_Player].number_fence);
        
        printf("Si vous voulez jouer une barriere taper 1 ou un pion taper 2:\t");
        scanf("%d",&choice);
        
        switch (choice)
        {
            case 1:
            {
                if (playFence(&player[digit_Player], digit_Player, &plateau) == EXIT_SUCCESS)
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
        
        if (sablier(duration, t_debut) == 0) // il reste du temps
        {
        }
        else
        {
            boucle = 0;
        }
    }
    
    return 0;
    
    return EXIT_SUCCESS;
}
