//
//  random.c
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Alexandre Picault on 05/05/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//



#include "header.h"



int choicePlayer (int nbPlayer)
{
    srand( time( NULL ) );
    int i=0;
    switch (nbPlayer)
    {
        case 2:
        {
            i = rand()%nbPlayer;
            break;
        }
            
        default:
        {
            i = rand()%nbPlayer;
            break;
        }
    }
    return i;
}


