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

void info_start(int *nb_players, int *duration, Player *player[]) //Fonction which ask the first info.
{
//    demand_nb_player(nb_players);
    *nb_players = 2;
    
//    for (int i =0; i < *nb_players; i++)
//    {
//         demand_name_player(i, player[i]);
//    }
    
//    *duration = demand_time();
    *duration = 10;
    

    clear_console();
}

//request for the number of players

void demand_nb_player (int *nb_players)
{
    printf("==NOMBRE DE JOUEURS==\n1. 1joueur humain et une IA.\n2. 2joueurs\n4. 4joueurs\n");
    scanf("%d", nb_players);
    
    switch (*nb_players)
    {
            //        case 1:
            //        {
            //            printf("Vous allez jouer tout seul mais contre un bot, mais combien de temps");
            //            break;
            //        }
            
        case 2:
        {
            printf("Vous allez jouer a 2 mais combien de temps ?\n");
            break;
        }
            
        case 4:
        {
            printf("Vous allez jouer a 4 mais combien de temps ?\n");
            break;
        }
            
        default:
        {
            printf("Choississez 1, 2 ou 4\n");
            clear_console();
            demand_nb_player(nb_players);
            break;
        }
    }
}

//request for game time

int demand_time (void)
{
    int duration = 0;
    printf("==TEMPS DE PARTIE==\n10 minutes\n15 minutes\n20.minutes\n");
    scanf("%d", &duration);
    
    switch (duration)
    {
        case 1:
        {
            printf("Vous allez jouer %d minute\n", duration);
            break;
        }
        case 10:
        {
            printf("Vous allez jouer %d minutes\n", duration);
            break;
        }
            
        case 15:
        {
            printf("Vous allez jouer %d minutes\n", duration);
            break;
        }
            
        case 20:
        {
            printf("Vous allez jouer %d minutes\n", duration);
            break;
        }
            
        default:
        {
            printf("Choississez 10, 15, 20 minutes.\n");
            clear_console();
            duration = demand_time();
            break;
        }
    }
    return duration;
}

//void demand_name_player (int i, Player *player)
//{
//    char name[NB_CHAR];
//    printf("Joueur n : %d \nComment vous appellez vous ?\t", i+1);
//    scanf("%s", name);
//    strcpy(player->name, name);
////    scanf("%s", &player->name);
//    printf("\nPar quel caractere voulez vous être represente ?\t");
//    scanf("%c", &player[i].affichage);
//    printf("cou");
//}

///

#endif /* info_start_h */
