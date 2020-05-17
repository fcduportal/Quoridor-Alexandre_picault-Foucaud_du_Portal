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
    printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // To erase console, not great but its work.
}

//



/// -------------------------------------------  fence



fence enter_coord_fence (void)
{
    fence Barrier = {-1, -1, -1, -1};
    int test = -1;
    
    while (test != 0)
    {
        Barrier.A = saisie_colonnes_lignes();
        Barrier.B = saisie_colonnes_lignes();
        
        if (BETWEEN_0_8(Barrier.A.ligne) && BETWEEN_0_8(Barrier.A.colonne) && BETWEEN_0_8(Barrier.B.ligne) && BETWEEN_0_8(Barrier.B.colonne))
        {
            test = 0;
        }
        else
        {
            printf("Vos coordonees doivent etre comprises entre 0 et 8\n");
        }
    }
    return Barrier;
}


point saisie_colonnes_lignes (void)
{
    char lettre;
    int chiffre=0;
    point point={-1, -1};
    
    
    scanf("%c",&lettre); // recuperer le \n precedent
    
    printf("Veuillez saisir les coordonees souhaitee. (ie : A 2)\t");
    scanf("%c %d", &lettre, &chiffre);
    lettre = toupper(lettre);
    
    point.colonne = ASCII_NUMBER(lettre);
    point.ligne = chiffre;
    
    return point;
}



//



/// end fence -------------------------------------------  begin Pawn



point enter_coord_Pawn (void)
{
    point point = {-1, -1};
    int test = -1;
    
    while (test != 0)
    {
        point = saisie_colonnes_lignes();

        
            if (BETWEEN_0_8(point.ligne) && BETWEEN_0_8(point.colonne))
            {
                test = 0;
            }
            else
            {
                printf("Vos coordonees doivent etre comprises entre 0 et 8\n");
            }
    }
    return point;
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
        return EXIT_SUCCESS;
    }
}

//

int tester_adjacent (point M, point N)
{
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


void display_board (Plateau *plateau, Player player[], int nb_player)
{
    char nomJoueur3[LG_COLONNE+1];
    char nomJoueur4[LG_COLONNE+1];
    unsigned long p3 = 0, p4 = 0;
    unsigned long lg3 = strlen(player[2].name), lg4 = strlen(player[3].name);
    
    p3 = NB_BLANCS(LG_COLONNE, lg3);
    p4 = NB_BLANCS(LG_COLONNE, lg4);
    
    for (int i = 0; i < p3 ; i++)
    {
        nomJoueur3[i] = ' ';
    }
    for (unsigned long i = p3; i < (p3 + lg3) ; i++)
    {
        nomJoueur3[i] = player[2].name[i - p3];
    }
    for (unsigned long i = (p3 + lg3) ; i < LG_COLONNE ; i++)
    {
        nomJoueur3[i] = ' ';
    }

   nomJoueur3[LG_COLONNE] = '\0';
    
    
    for (int i = 0; i < p4 ; i++)
    {
        nomJoueur4[i] = ' ';
    }
    for (unsigned long i = p4; i < (p4 + lg4) ; i++)
    {
        nomJoueur4[i] = player[3].name[i - p4];
    }
    for (unsigned long i = (p4 + lg4) ; i < LG_COLONNE ; i++)
    {
        nomJoueur4[i] = ' ';
    }
    nomJoueur4[LG_COLONNE] = '\0';

    
    clear_console();
    
    int curseur = 0 ;
    
    display_name_player(player[0], nomJoueur3[curseur], nomJoueur4[curseur]) ;
    curseur++;
    
    display_ligne_vide(nomJoueur3[curseur], nomJoueur4[curseur]);
    curseur++;
    
    display_abscisses(nomJoueur3[curseur], nomJoueur4[curseur]);
    curseur++;
    
    display_lines(nomJoueur3[curseur],  nomJoueur4[curseur]);
    curseur++;
    
    for (int i = 0; i < 9; i++)
    {

        printf("%c  %d", nomJoueur3[curseur], i);
        for (int j = 0; j < 9; j++)
        {
            switch (plateau->board[i][j])
            {
                case FREE:
                {
                    printf("|   ");
                    break;
                }
                case TAKEN:
                {
                    printf("| X ");
                    break;
                }
                case PAWN:
                {
                    for (int k=0; k<nb_player; k++)
                    {
                        if (player[k].position.ligne == i &&  player[k].position.colonne == j)
                        {
                            printf("| %d ", player[k].affichage);
                            
                        }
                    }
                    break;
                }
            }
        }
        printf("|%d  %c\n", i, nomJoueur4[curseur]);
        curseur++;

        display_lines(nomJoueur3[curseur], nomJoueur4[curseur]) ;
        curseur++;
    }
    display_abscisses(nomJoueur3[curseur], nomJoueur4[curseur]);
    curseur++;
    
    display_ligne_vide(nomJoueur3[curseur], nomJoueur4[curseur]);
    curseur++;
    
    display_name_player(player[1], nomJoueur3[curseur], nomJoueur4[curseur]);
    printf("\n\n");
}




void display_name_player (Player player, char c1, char c2)
{
    unsigned long longueur_name = strlen(player.name);
    int longueur_line = LG_LIGNE;
    unsigned long nb_blancs = (longueur_line-longueur_name)/2 + 1;
    
    printf("%c", c1);
    for (int i = 1; i < nb_blancs; i++) // 1er caractere = c1
    {
        printf(" ");
    }
    printf("%s", player.name);
    for (unsigned long i = nb_blancs + longueur_name ; i < LG_LIGNE -1 ; i++)
    {
        printf(" ");
    }
    printf ("%c\n", c2);
}




void display_abscisses(char c1, char c2)
{
    printf("%c   ", c1);
 for (int columns=0; columns<DIM_TAB; columns++)
    {
        int columnChar = NUMBER_ASCII(columns);
        printf("  %c ", columnChar);
    }
    printf("  %c\n", c2);
}




void display_lines (char c1, char c2)
{
    printf("%c   ", c1);
    for (int i=0; i<DIM_TAB; i++)
    {
        printf("|---");
    }
    printf("|   %c\n", c2);
}





void display_ligne_vide (char c1, char c2)
{
    printf("%c", c1);
    for (int i=1; i<(LG_LIGNE-1); i++)
    {
        printf(" ");
    }
    printf("%c\n",c2);
}





//point initialiserPointsAdjacentsPion (int ligne, int colonne, Plateau *plateau, Plateau *plateauOrdi)
//{
//    point point;
//
//    
//    if (BETWEEN_0_8(ligne) && BETWEEN_0_8(colonne))
//    {
//        point.ligne = ligne;
//        point.colonne = colonne;
//        
//        if (availability_Box(point, plateau) == EXIT_FAILURE || plateauOrdi->board[ligne][colonne]==BANNED)
//        {
//            point.ligne = -1;
//            point.colonne = -1;
//        }
//        
//    }
//    else
//    {
//        point.ligne = -1;
//        point.colonne = -1;
//    }
//    
//    return point;
//}

#endif /* Fonctions_reutilisable_h */
