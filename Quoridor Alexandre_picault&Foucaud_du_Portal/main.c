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

         int nb_Players = 0, duration = 0, digit_player =0;
          pawn *player = NULL; // Ce pointeur va servir de tableau après l'appel du malloc
         


    
         info_start(&nb_Players, &duration); //  Call fonction to ask the first info in order to adress differents rules to the game.
     //    appel random (&)
          
         
         switch (nb_Players) // play in fonction of the number of players
         {
            case 1:
             {
                 
                 nb_Players+=1;
                 player = malloc(nb_Players * sizeof(int)); // On alloue de la mémoire pour le tableau
                 if (player == NULL) // On vérifie si l'allocation a marché ou non
                 {
                     exit(0); // On arrête tout
                 }
                 
                 printf("Faire le jeu avec un bot.\n");
                 Game_one_Player(&player[digit_player]); // j'ai mis 0 il vas falloir Mettre le nb player
                 
                 // On libère la mémoire allouée avec malloc, on n'en a plus besoin
                 free(player);
                 
                 break;
             }
                 
             case 2: // play 2
             {
                 player = malloc(nb_Players * sizeof(int)); // On alloue de la mémoire pour le tableau
                 if (player == NULL) // On vérifie si l'allocation a marché ou non
                 {
                     exit(0); // On arrête tout
                 }
                 
                 printf("Faire le jeu avec 2 joueurs\n"); // idem
                 Game_2_Player(&player[digit_player]);
                 
                 // On libère la mémoire allouée avec malloc, on n'en a plus besoin
                 free(player);
                 
                 break;
             }
                 
                 
             case 4: // play 4
             {
                 player = malloc(nb_Players * sizeof(int)); // On alloue de la mémoire pour le tableau
                 if (player == NULL) // On vérifie si l'allocation a marché ou non
                 {
                     exit(0); // On arrête tout
                 }
                 
                 printf("Faire le jeu avec 4 joueurs\n"); // idem
                 Game_4_Player(&player[digit_player]);
                 
                 // On libère la mémoire allouée avec malloc, on n'en a plus besoin
                 free(player);
                 
                 break;
                 
             }
                 
         }
    return 0;
}

///

