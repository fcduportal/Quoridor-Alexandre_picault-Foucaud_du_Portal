//
//  random.c
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Alexandre Picault on 05/05/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//



#include "header.h"



void choice_player (int nb_player, int *i)
{
    srand( time( NULL ) );
    
    switch (nb_player)
    {
        case 2:
        {
            *i=rand()%nb_player+1;
            printf("\n c'est le joueur %d qui commence.\n", *i);
            break;
        }
            
        default:
        {
            *i=rand()%nb_player+1;
            printf("\n c'est le joueur %d qui commence.\n", *i);
            break;
        }
    }
}


