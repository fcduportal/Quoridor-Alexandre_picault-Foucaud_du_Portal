/*
 main.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 15/03/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



/*
 REFLEXION PRELIMINAIRES :
 
 
 
 BUT : Avancer son pion jusqu'au bout du plateau avant son adversaire.
 
 Présentation :
 - Un plateau de jeu
 - 2 zones de stockages
 - 20 barières et 4 pions
 
 Sous programmes nécessaires  :
 
 
 - Début :
 ( Enoncer les règles )
    infos nécéssaires
        
        Demander le nombre de joueurs humains;
        Demander le nombre de joueurs IA;
        Demander la durée de la partie ( entre 10 à 20 min )
 
    Présentation
A        Placer le plateau;
F        Placer les joueurs humains et IA dans leur emplacement de départ;
F        Placer les barrières dans leurs espaces de stockage;
A        Determiner par un tirage au sort qui commence;
A        Commencer le décompte;
 
 
 
 - Jouer :
    Commencer par le joueur choisi;
        Joueur humain
        Lui demander s'il veut jouer une barière ou son pion;
            Barrière
                Regarder s'il lui reste des barières;
                    si il lui en reste;
                        Demander où placer sa barière (coordonnées des deux cases de la barière);
                    si les deux cases sont à coté horizontement ou verticalement;
                    si la case est libre;
                        alors accepter l'emplacement
                    sinon
                        lui dire le problème et lui demander de rentrer d'autres coordonées
                    Sinon lui annoncer qu'il ne lui en reste pas
 
        Pion
 ( Afficher les endroits ou il peut aller );
 Demander où placer son pion (coordonnées de la cases);
 si la case du pion et celle souhaitée sont à coté horizontement ou verticalement;
 si la case est libre;
 alors accepter l'emplacement
 sinon
 lui dire le problème et lui demander de rentrer d'autres coordonées
 
 
 
 Comment faire l'IA:
 
 
 
 Quand c'est au tour de l'IA, il doit pouvoir déterminer toute les possibilitées de jeu qu'il peut faire ainsi que toute les possibilitées de jeu du joueur après avoir lui même joué et enfin une dernière fois ses possibilitées de jeu.
 (on peut améliorer pour qu'il fasse cela le nombre de fois qu'on détermine au début de la partie)
 
 Pour cela on doit créer un tableau contenant pour chaque possibilitées de jeu : les actions / les coordonées (C1 et C2 : C1 pour un pion, C1 et C2 pour une barrière; nombres compis entre 00 et 99 : xX -> x N° ligne, X -> n° colonne) / le nombre de lignes qui lui reste jusqu'a la fin / l'adresse du tableau de possibilités suivant
 
 On peut commencer pour determiner quelle action qu'il va faire plutôt qu'une autre par determiner le nombre de lignes qu'il lui reste jusqu'à la fin et choisir l'action qui l'amenera le plus vite au plus petit nombre (dans ce cas il va toujours avancer et jamais mettre de barrières)
 on peut sinon determiner par le chemin qui utilise le moins d'actions possibles pour arriver au résultat attendu.
 ou encore la solution qui propose le plus de résultats satisfaisants.
 
 Le mieux serait d'attribuer des coefficients à chaque action exemple : 2 pour avancer, 1 pour ralentir le joueuer adverse ... et choisir l'action qui a la meilleure somme pondéré de ces valeurs. Les coefficients pourraient varier en fonction de l'avancement du pion adverse.
 */





#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void info_start(void);
int nb_players = 0, nb_bot = 0, duration = 0;

void clear_console (void);


int main(int argc, const char * argv[])
{
    info_start(); // Call fonction to ask the first info in order to adress differents rules to the game.
}



void info_start() //Fonction which ask the first info.
{
    int  nb_tot = 0, good = 0;
    
    
    
    while (good != 1)
    {
        printf ("Combien de joueurs vont jouer ?\n");  // Get the number of humans.
        scanf("%d",&nb_players);
        printf("Il y a %d joueurs humain.\n\n",nb_players);
        
        
        printf ("Combien d'IA vont jouer ?\n"); // Get the number of bots.
        scanf("%d",&nb_bot);
        printf("Il y a %d IA.\n\n",nb_bot);
        
        nb_tot = nb_players + nb_bot; // Have the total number of players.
        
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
        
        good = (nb_tot <= 4) ? 1 : 0; printf("Desole, vous etes trop nombreux, le total de joueurs doit etre inferieur ou egale a 4.\n\n");
        
    }
    printf("Il y a donc %d joueurs humains et %d joueurs ordinateurs.\n\n\n",nb_players, nb_bot);
    
    /*
     nb_tot = 5
     while nb_tot > 4....
     */
    
    
    clear_console();
    
    
    
    good = 0;
    
    while (good != 1)
    {
        printf ("Combien de temps voulez vous jouer : entre 10 a 20 minutes.\n\n");  // Get the duration.
        scanf("%d",&duration);
        
        
        if(duration < 10)
        {
            printf("Desole, la partie sera trop courte, choississez une duree entre 10 et 20 minute.\n");
        }
        else if (duration > 20)
        {
            printf("Desole, la partie sera trop longue, choississez une duree entre 10 et 20 minute.\n");
        }
        else
        {
            good = 1;
            printf("La partie durera maximum %d minutes.\n\n\n",duration);
        }
    }
    
    clear_console();
    
}





void clear_console (void)
{
    printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // To erase console, not great but its work.
    
}
