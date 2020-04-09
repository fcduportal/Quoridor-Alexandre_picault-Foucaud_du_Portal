/*
 main.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 15/03/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Fonctions_reutilisable.h"
#include "Infos_start.h"
#include "Plateau.h"




int main(int argc, const char * argv[])
{
    int nb_players = 0, nb_bots = 0, duration = 0;

    info_start(&nb_players, &nb_bots, &duration); // OK Call fonction to ask the first info in order to adress differents rules to the game.
    
    init_plateau();
    
    return 0;
}

