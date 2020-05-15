/*
 Fonctions_reutilisable.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 31/03/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



#ifndef Fonctions_reutilisable_h
#define Fonctions_reutilisable_h

///

#include "header.h"

//

void clear_console (void)
{
    usleep(1000000);
    usleep(1000000);
    printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // To erase console, not great but its work.
}

//



/// -------------------------------------------  fence



fence enter_coord_fence (void)
{
    fence Barrier;
    int test = -1;
    
    while (test != 0)
    {
        printf("Veuillez saisir l'abscisse 1 (x1) de l'emplacement souhaite :\t");
        scanf("%d",&Barrier.A.ligne);
        printf("Veuillez saisir l'ordonnee 1 (y1) de l'emplacement souhaite :\t");
        scanf("%d",&Barrier.A.colonne);
        printf("Veuillez saisir l'abscisse 2 (x2) de l'emplacement souhaite :\t");
        scanf("%d",&Barrier.B.ligne);
        printf("Veuillez saisir l'ordonnee 2 (y2) de l'emplacement souhaite :\t");
        scanf("%d",&Barrier.B.colonne);
        
        if (BETWEEN(Barrier.A.ligne, 0, 8) && BETWEEN(Barrier.A.colonne, 0, 8) && BETWEEN(Barrier.B.ligne, 0, 8) && BETWEEN(Barrier.B.colonne, 0, 8))
        {
            printf("Beetwen\n");
            test = 0;
        }
        else
        {
            printf("Vos coordonees doivent etre comprises entre 0 et 8\n");
        }
    }
    printf("barriere : (%d;%d), (%d;%d)\t", Barrier.A.ligne, Barrier.A.colonne, Barrier.B.ligne, Barrier.B.colonne);
    return Barrier;
}

//

void display_coord_fence (fence barrier)
{
    printf("Votre barrière est en : (%d;%d) et (%d;%d)\n", barrier.A.ligne, barrier.A.colonne, barrier.B.ligne, barrier.B.colonne);
    clear_console();
}

//



/// end fence -------------------------------------------  begin Pawn



point enter_coord_Pawn (void)
{
    point point;
    
    printf("Veuillez saisir l'abscisse (x) de l'emplacement souhaite :\t");
    scanf("%d",&point.ligne);
    printf("Veuillez saisir l'ordonnee (y) de l'emplacement souhaite :\t");
    scanf("%d",&point.colonne);
    
    return point;
}

//

void display_coord_Pawn (Player player)
{
    printf("Votre pion est en (%d;%d)\n", player.position.ligne, player.position.colonne);
}

//



/// end Pawn-------------------------------------------- Begin boxes



int availability_Box (point M, Plateau *plateau)
{
    if (plateau->board[M.ligne][M.colonne] != FREE)
    {
        printf("Impossible la case (%d;%d) est déjà prise.\n", M.ligne, M.colonne);
        return EXIT_FAILURE;
    }
    else
    {
        printf("La case est libre (%d,%d)\n", M.ligne, M.colonne);
        return EXIT_SUCCESS;
    }
}

//

int tester_adjacent (point M, point N)
{
    printf("tester adjacent M : (%d,%d) , N: (%d,%d)\n", M.ligne, M.colonne, N.ligne, N.colonne);
    
    if (M.ligne == N.ligne && (M.colonne-N.colonne==-1 || M.colonne-N.colonne == 1))
    {
        return EXIT_SUCCESS;
    }
    else if (M.colonne == N.colonne && (M.ligne-N.ligne==-1 || M.ligne-N.ligne == 1))
    {
        return EXIT_SUCCESS;
    }
    else
    {
        printf("Les deux cases doivent êtres adjacentes verticalement ou horizontalement.\n");
        return EXIT_FAILURE;
    }
}



///end boxes--------------------------------------------  begin end game



int sablier (int *duration, time_t t_debut)
{
    time_t t_courant = (time(NULL));
    time_t t_ecoule = difftime(t_courant, t_debut);
    
    if (t_ecoule>(*duration*60))
    {
        return EXIT_FAILURE;
    }
    else
    {
        return EXIT_SUCCESS;
    }
}

//

int gagnant (Player *player)
{
    int etat = EXIT_FAILURE;
    printf("AVANT IF");
    if (player[0].position.ligne == 8)
    {
        printf("Le joueur %s a gagne.\n", player[0].name);
        etat = EXIT_SUCCESS;
    }
    if (player[1].position.ligne == 0)
    {
        printf("Le joueur %s a gagne.\n", player[1].name);
        etat = EXIT_SUCCESS;
    }
    if (player[2].position.colonne == 8)
    {
        printf("Le joueur %s a gagne.\n", player[2].name);
        etat = EXIT_SUCCESS;
    }
    if (player[0].position.colonne == 0)
    {
        printf("Le joueur %s a gagne.\n", player[3].name);
        etat = EXIT_SUCCESS;
    }
    return etat;
}

#endif /* Fonctions_reutilisable_h */
