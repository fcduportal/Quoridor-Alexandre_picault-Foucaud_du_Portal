//
//  Plateau.c
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Foucaud de Bouët du Portal on 08/05/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//

#include "header.h"

void display_board (void)
{
        int x,y;
        printf(" | a--b--c--d--e--f--g--h--i |\n");
        for (x=0; x<9; x++)
        {
            printf("%d|",x+1);

            
            
            printf("\n");
        }
        printf(" | a--b--c--d--e--f--g--h--i |\n");
}





