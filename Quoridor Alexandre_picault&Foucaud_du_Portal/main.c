/*
 main.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 15/03/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



#include "header.h"



int main(int argc, const char * argv[])
{

    int nb_players = 0, duration = 0;
    
    info_start(&nb_players, &duration); //  Call fonction to ask the first info in order to adress differents rules to the game.
    
    
     
    switch (nb_players) // play in fonction of the number of players
    {
        case 2: // play 2
        {
//            Game_2_Player();
            break;
        }
            
            
        case 4: // play 4
        {
            
            break;
        }
               return 0;
    }
}
