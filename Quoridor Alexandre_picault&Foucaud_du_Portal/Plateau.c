//
//  Plateau.c
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Foucaud de Bouët du Portal on 09/04/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//



#ifndef init_plateau_h
#define init_plateau_h

#include "Plateau.h"
#include <stdio.h>

#define N_CASE 36

void init_plateau(void)
{
    
     char tab[N_CASE][N_CASE];
     for (int i=0; i<N_CASE; i++)
     {
         for (int j=0; j<N_CASE; j++)
         {
             tab[i][j]='0';
             printf("%c",tab[i][j]);
         }
         printf("\n\n");
     }
     

    
    /*

     int i=0, j=0;
     
     char lignes[N_CASE];
     char colones[N_CASE];
     
     for (i=0; i<N_CASE; i++)
     {
         lignes[i]='|';
         printf(" %c ",lignes[i]);
         
         for (j=0; j<N_CASE; j+=3)
         {
             colones[j]='|';
             printf(" %c ",colones[i]);
         }
         printf("\n");
     }
     */
    
    
}


#endif /* init_plateau_h */



