/*
 main.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 15/03/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



///

#include "header.h"

//

int main()
{
       // fonction_a_tester();
    
    int nb_players = 0, duration = 0, i =0;
    pawn player = {"",1,0,0,0};
    
    info_start(&nb_players, &duration);
    choice_player(nb_players, &i);
    
    /*
    int nb_players = 0, duration = 0, i =0;
    
    //
    
    info_start(&nb_players, &duration); //  Call fonction to ask the first info in order to adress differents rules to the game.
    appel random (&)
     
    //
    
    switch (nb_players) // play in fonction of the number of players
    {
        case 2: // play 2
        {
            printf("Faire le jeu avec 2 joueurs\n");
            Game_2_Player(player);
            break;
        }
            
            
        case 4: // play 4
        {
            printf("Faire le jeu avec 4 joueurs\n");
//            game_4_players(player);
            break;
        }
            return 0;
    }
    */
    //
    
}

///
