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
 
 
 
 
 - Début :
 ( Enoncer les règles )
 Demander le nombre de joueurs humains;
 Demander le nombre de joueurs IA;
 Demander la durée de la partie ( 5 / 10 / 15 / 20 min )
 Placer le plateau;
 Placer les joueurs humains et IA dans leur emplacement de départ;
 Placer les barrières dans leurs espaces de stockage;
 Determiner par un tirage au sort qui commence;
 Commencer le décompte;
 
 */



/*
 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>
 #include <math.h>
 
 int *nbPlayers(void);
 
 
 int main(int argc, const char * argv[])
 {
 int * robotAndHuman = nbPlayers();
 printf("Il y a donc %d joueurs humains et %d joueurs ordinateurs.\n ",robotAndHuman[0], robotAndHuman[1]);
 }
 
 
 int *nbPlayers()
 {
 int nb_joueur = 0, nb_ordi = 0, nb_tot, retour [2], good = 0;
 
 
 
 while (good != 1)
 {
 printf ("Combien de joueurs vont jouer ?\n");
 scanf("%d",&nb_joueur);
 printf("Il y a %d joueurs humain.\n\n",nb_joueur);
 
 printf ("Combien d'IA vont jouer ?\n");
 scanf("%d",&nb_ordi);
 printf("Il y a %d IA.\n\n",nb_ordi);
 
 nb_tot = nb_joueur + nb_ordi;
 
 if(nb_tot<=4)
 {
 good =1;
 }
 }
 
 retour[0] = nb_joueur;
 retour[1] = nb_ordi;
 return retour;
 
 }
 
 */


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void nbPlayers(void);
int nb_joueur = 0, nb_ordi = 0;


int main(int argc, const char * argv[])
{
    nbPlayers();
    
}


void nbPlayers()
{
    int  nb_tot = 0, good = 0;
    while (good != 1)
    {
        printf ("Combien de joueurs vont jouer ?\n");
        scanf("%d",&nb_joueur);
        printf("Il y a %d joueurs humain.\n\n",nb_joueur);
        
        printf ("Combien d'IA vont jouer ?\n");
        scanf("%d",&nb_ordi);
        printf("Il y a %d IA.\n\n",nb_ordi);
        
        nb_tot = nb_joueur + nb_ordi;
        
        if(nb_tot<=4)
        {
            good = 1;
        }
    }
    printf("Il y a donc %d joueurs humains et %d joueurs ordinateurs.\n ",nb_joueur, nb_ordi);
}
