//
//  Plateau.c
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Foucaud de Bouët du Portal on 09/04/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//

#include "Plateau.h"
#include <stdio.h>

#define N_CASE 12

void init_plateau(void)
{
    char tab[N_CASE][N_CASE];
    for (int i=0; i<N_CASE; i++)
    {
        for (int j=0; j<N_CASE; j++)
        {
            tab[i][j]='0';
            printf("%c   ",tab[i][j]);
        }
        printf("\n\n");
    }
}

