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
          pawn player[2] = {"",0,0,0};
         


    
         info_start(&nb_players, &duration); //  Call fonction to ask the first info in order to adress differents rules to the game.
     //    appel random (&)
          
         
         switch (nb_players) // play in fonction of the number of players
         {
            case 1:
             {
                 printf("Faire le jeu avec un bot.\n");
                 Game_one_player(&player[0]); // j'ai mis 0 il vas falloir Mettre le nb player
             }
                 
             case 2: // play 2
             {
                 printf("Faire le jeu avec 2 joueurs\n"); // idem
                 Game_2_Player(&player[0]);
                 break;
             }
                 
                 
             case 4: // play 4
             {
                 printf("Faire le jeu avec 4 joueurs\n"); // idem
                 Game_4_Player(&player[0]);
                 break;
             }
                 return 0;
         }
}

///
