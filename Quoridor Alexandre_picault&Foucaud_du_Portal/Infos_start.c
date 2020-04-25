//
//  Infos_start.c
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Foucaud de Bouët du Portal on 04/04/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//




#ifndef info_start_h
#define info_start_h

#include <stdio.h>
#include "Infos_start.h"
#include "Fonctions_reutilisable.h"

void info_start(int *nb_players, int *nb_bots, int *duration) //Fonction which ask the first info.
{
    int  nb_tot = 0, good = 0;
    
    
    
    while (good != 1)
    {
        printf ("Combien de joueurs humains vont jouer ?\n");  // Get the number of humans.
        scanf("%d",&*nb_players);
        printf("Il y a %d joueurs humain.\n\n",*nb_players);
        
        
        /*
        printf ("Combien d'IA vont jouer ?\n"); // Get the number of bots.
        scanf("%d",&*nb_bots);
        printf("Il y a %d IA.\n\n",*nb_bots);
        
        nb_tot = *nb_players + *nb_bots; // Have the total number of players.
        */
        
        
        /*
         if(nb_tot <= 4) // Verifing that the number of players is less than 4.
         {
         good = 1; // Exit while.
         }
         else // Loop.
         {
         printf("Desole, vous etes trop nombreux, le total de joueurs doit etre inferieur ou egale a 4.\n");
         }
         */
        
        good = (nb_tot <= 4) ? 1 : 0;
        
        
        
        if (good!=1)
        {
            printf("Desole, vous etes trop nombreux, le total de joueurs doit etre inferieur ou egale a 4.\n\n");
        }
    }
    printf("Il y a donc %d joueurs humains et %d joueurs ordinateurs.\n\n\n",*nb_players, *nb_bots);
    
    /*
     nb_tot = 5
     while nb_tot > 4....
     */
    
    delay();
    clear_console();
    
    
    
    good = 0;
    
    while (good != 1)
    {
        printf ("Combien de temps voulez vous jouer : entre 10 a 20 minutes.\n\n");  // Get the duration.
        scanf("%d",&*duration);
        
        
        if(*duration < 10)
        {
            printf("Desole, la partie sera trop courte, choississez une duree entre 10 et 20 minute.\n");
        }
        else if (*duration > 20)
        {
            printf("Desole, la partie sera trop longue, choississez une duree entre 10 et 20 minute.\n");
        }
        else
        {
            good = 1;
            printf("La partie durera maximum %d minutes.\n\n\n",*duration);
        }
    }
    delay();
    clear_console();
}


#endif /* info_start_h */
