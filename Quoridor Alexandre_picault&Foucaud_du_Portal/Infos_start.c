/*
 Infos_start.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 04/04/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



#ifndef info_start_h
#define info_start_h

///

#include "header.h"

void startingInfos(int *nbPlayers, int *duration, Player *player) //Fonction which ask the first info.
{
    demandNbPlayer(nbPlayers);
    *duration = demandTime();
    demandNamePlayers(*nbPlayers, player);
}

//request for the number of players

void demandNbPlayer (int *nbPlayers)
{
    printf("==NOMBRE DE JOUEURS==\n\nSaississez le nombre de joueur. (1, 2, 4)\nAppuyer sur 'entrer' après avoir saisie le nombre de joueur.\n\n1. 1joueur humain et une IA.\n2. 2joueurs\n4. 4joueurs\n");
    scanf("%d", nbPlayers);
    
    switch (*nbPlayers)
    {
        case 1:
        {
            printf("Vous allez jouer tout seul mais contre un bot, mais combien de temps\n\n");
            break;
        }
            
        case 2:
        {
            printf("Vous allez jouer a 2 mais combien de temps ?\n\n");
            break;
        }
            
        case 4:
        {
            printf("Vous allez jouer a 4 mais combien de temps ?\n\n");
            break;
        }
            
        default:
        {
            printf("Choississez 1, 2 ou 4\n");
            clearConsole();
            demandNbPlayer(nbPlayers);
            break;
        }
    }
}

//request for game time

int demandTime (void)
{
    int duration = 0;
    printf("\n\n==TEMPS DE PARTIE==\n\nSaississez la duree de la partie. (10, 15, 20)\nAppuyer sur 'entrer' après avoir saisie la duree.\n\n10 minutes\n15 minutes\n20.minutes\n");
    scanf("%d", &duration);
    
    switch (duration)
    {
        case 10:
        {
            break;
        }
            
        case 15:
        {
            break;
        }
            
        case 20:
        {
            break;
        }
            
        default:
        {
            printf("Choississez 10, 15, 20 minutes.\n");
            clearConsole();
            duration = demandTime();
            break;
        }
    }
    return duration;
}

void demandNamePlayers (int nbPlayers, Player *player)
{
    if (nbPlayers == 1)
    {
        printf("\n\nComment vous appelez vous?\t");
        scanf("%s",player[1].name);
        
        printf("Comment voulez vous appeler l'iA?\t");
        scanf ("%s",player[0].name);
    }
    else
    {
        printf("\n");
        for (int i = 0; i < nbPlayers; i++)
        {
            printf("Comment s'appelle le joueur numero %d?\t", (i + 1));
            scanf("%s",player[i].name);
        }
    }
}


///

#endif /* info_start_h */
