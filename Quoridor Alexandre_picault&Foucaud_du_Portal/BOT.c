//
//  BOT.c
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Foucaud de Bouët du Portal on 16/05/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//

#include "header.h"

int playBot (Player player[], Plateau *plateau)
{
    int test = -1;
    player[ORDI].temp.ligne = (player[ORDI].position.ligne+1);
    player[ORDI].temp.colonne = (player[ORDI].position.colonne);
    if (BETWEEN(player[ORDI].temp.ligne, 0, 8) && BETWEEN(player[ORDI].temp.colonne, 0, 8))
    {
        test = 0;
    }
    else
    {
        printf("erreur ordi\n");
    }
    
    if (test == 0)
    {
        test = availability_Box(player[ORDI].temp, plateau);
        if (test == EXIT_SUCCESS)
        {
            plateau->board[player[ORDI].temp.ligne][player[ORDI].temp.colonne] = PAWN;
            plateau->board[player[ORDI].position.ligne][player[ORDI].position.colonne] = FREE;
            player[ORDI].position = player[ORDI].temp;
            player[ORDI].temp.ligne = -1;
            player[ORDI].temp.colonne = -1;
        }
    }
    return EXIT_SUCCESS;
}
