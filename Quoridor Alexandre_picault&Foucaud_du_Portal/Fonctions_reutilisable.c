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
#define BETWEEN(value, min, max) (value <= max && value >= min)


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
        printf("Veuiilez saisir l'abscisse 1 (x1) de l'emplacement souhaite :\t");
        scanf("%d",&Barrier.A.ligne);
        printf("Veuiilez saisir l'ordonnee 1 (y1) de l'emplacement souhaite :\t");
        scanf("%d",&Barrier.A.colonne);
        printf("Veuiilez saisir l'abscisse 2 (x2) de l'emplacement souhaite :\t");
        scanf("%d",&Barrier.B.ligne);
        printf("Veuiilez saisir l'ordonnee 2 (y2) de l'emplacement souhaite :\t");
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

//void tester_barrier (fence Barrier, plateau plateau)
//{
//    printf("tester barriere : barriere : (%d;%d), (%d;%d)\n", Barrier.A.x, Barrier.A.y, Barrier.B.x, Barrier.B.y);
//
//
//    int test=0;
//    if (Barrier.A.x == Barrier.B.x)
//    {
//        test = Barrier.A.y-Barrier.B.y;
//        switchtest_B(test, Barrier);
//    }
//
//    else if (Barrier.A.y == Barrier.B.y)
//    {
//        test = Barrier.A.x-Barrier.B.x;
//        switchtest_B(test, Barrier);
//    }
//    else
//    {
//        printf("Votre barriere doit etre place sur deux cases adjacentes.\n");
//        clear_console();
//        enter_coord_fence();
//    }
//
//    printf("test : %d\n", test);
//
//    if (availability_Box(Barrier.A, plateau)==0 || availability_Box(Barrier.B, plateau)==0)
//    {
//        printf("availability box : barriere : (%d;%d), (%d;%d)\t", Barrier.A.x, Barrier.A.y, Barrier.B.x, Barrier.B.y);
//
//        printf("envoyer les coordonées au tableau\n");
//    }
//    else
//    {
//        printf("Une case n'est pas libre. Pauv naze\n");
//        enter_coord_fence();
//    }
//}

//



//void switchtest_B (int test, fence Barrier)
//{
//    if(test == 1 || test== -1)
//    {
//    }
//    else
//    {
//        printf("Votre barriere doit etre place sur deux cases adjacentes.\n");
//        clear_console();
//        enter_coord_fence();
//    }
//}

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
    
    printf("Veuiilez saisir l'abscisse (x) de l'emplacement souhaite :\t");
    scanf("%d",&point.ligne);
    printf("Veuiilez saisir l'ordonnee (y) de l'emplacement souhaite :\t");
    scanf("%d",&point.colonne);
    
    printf("point : (%d,%d)\n",point.ligne, point.colonne);
    
    return point;
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







//int tester_Pawn (pawn player, plateau plateau)
//{
//    printf("tester pawn a : (%d,%d) , temp: (%d,%d)\n", player.A.x, player.A.y, player.temp.x, player.temp.y);
//    int test=0;
//    if (player.A.x == player.temp.x)
//    {
//        test = player.A.y-player.temp.y;
//        test = switchtest_P(test, player, plateau);
//    }
//    else if (player.A.y == player.temp.y)
//    {
//        test = player.A.x-player.temp.x;
//        test = switchtest_P(test, player, plateau);
//    }
//
//    if (test == EXIT_SUCCESS)
//    {
//        return availability_Box(player.temp, plateau);
//    }
//    else
//    {
//        return EXIT_FAILURE;
//    }
//
//
//}

//

//int switchtest_P (int test, pawn player, plateau plateau)
//{
//
//    if (test==1 || test==-1)
//    {
//        return EXIT_SUCCESS;
//    }
//
//    else
//    {
//        printf("Votre Pion doit etre place sur une case adjacente a la precedente.\n");
//        return EXIT_FAILURE;
//    }
//}

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



///end boxes-------------------------------------------- 



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
