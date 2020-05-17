//
//  random.c
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Alexandre Picault on 05/05/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//



#include "header.h"



int choice_player (int nb_player)
{
    srand( time( NULL ) );
    int i=0;
    switch (nb_player)
    {
        case 2:
        {
            i = rand()%nb_player;
            break;
        }
            
        default:
        {
            i = rand()%nb_player;
            break;
        }
    }
    return i;
}


