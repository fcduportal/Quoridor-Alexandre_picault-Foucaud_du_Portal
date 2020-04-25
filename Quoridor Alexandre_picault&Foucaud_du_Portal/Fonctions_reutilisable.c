//
//  Fonctions_reutilisable.c
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Foucaud de Bouët du Portal on 31/03/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//



#ifndef Fonctions_reutilisable_h
#define Fonctions_reutilisable_h

#include <stdio.h>
#include <stdlib.h>
#include "Fonctions_reutilisable.h"


void clear_console (void)
{
    printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // To erase console, not great but its work.
}



void delay (void)
{
    usleep(1000000);
}


#endif /* Fonctions_reutilisable_h */

