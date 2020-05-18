//
//  BOT.c
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Foucaud de Bouët du Portal on 16/05/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//

#include "header.h"

int playBot (Player player[], Plateau *plateau, Plateau *plateauOrdi)
{
    /*
     Cette fonction permet à l'ordinateur de jouer seul et de choisir l'action à effectuer.
     Sa première stratégie est d'avancer tout droit si possible.
     s'il ne peut pas (barrière ou pion devant lui) il evalue l'interet d'aller sur chacune des cases qui l'entourent.
     Il choisi d'aller sur la case la plus interessante si possible.
     Si c'est un pion, il va poser une barière (derrière lui).
     Si c'est une barrière il va se déplacer.
     */
    
    // l'ordi regarde s'il peut avancer. (La case devant lui est vide)
    
    
    player[ORDI].temp.line = (player[ORDI].position.line+1);
    player[ORDI].temp.column = (player[ORDI].position.column);
    
    
    if (BETWEEN_0_8(player[ORDI].temp.line) && BETWEEN_0_8(player[ORDI].temp.column))
    {
        if (plateauOrdi->board[player[ORDI].temp.line][player[ORDI].temp.column] == POSSIBLE && availability_Box(player[ORDI].temp, plateau) ==
                EXIT_SUCCESS)
        {
            mAJPoint(plateau, player);
            
            return EXIT_SUCCESS;
        }
        else
        {
            printf("Case interdite. ou pas dispo\n");
            
            int scoreG = 0, boucle = -1;
            int colonne = (player[ORDI].position.column);
            int ligne = player[ORDI].position.line;
            
            
            while (boucle != 0) // on balaie vers la gauche
            {
                if (BETWEEN_0_8(colonne))
                {
                    if (plateauOrdi->board[ligne][colonne] != BANNED && plateau->board[ligne][colonne] != TAKEN )
                    {
                        if (BETWEEN_0_8(ligne))
                        {
                            scoreG ++;
                            if (BETWEEN_0_8(ligne+1))
                            {
                                if (plateauOrdi->board[ligne+1][colonne] != BANNED && plateau->board[ligne+1][colonne] != TAKEN )
                                {
                                    if (BETWEEN_0_8(ligne+2))
                                    {
                                        if (plateauOrdi->board[ligne+2][colonne] != BANNED && plateau->board[ligne+2][colonne] != TAKEN )
                                        {
                                            scoreG+=2;
                                            boucle = 0;
                                        }
                                    }
                                    else
                                    {
                                        scoreG++;
                                        boucle = 0;
                                    }
                                }
                            }
                            else
                            {
                                scoreG++;
                                boucle = 0;
                            }
                        }
                    }
                    else
                    {
                        scoreG = 100;
                        boucle = 0;
                        for (int j = (player[ORDI].position.column-1) ; j > colonne; j--)
                        {
                            
                            plateauOrdi->board[ligne][j] = BANNED;
                        }
                    }
                }
                else
                {
                    scoreG = 100;
                    boucle = 0;
                    for (int j = (player[ORDI].position.column-1) ; j > colonne; j--)
                    {
                        plateauOrdi->board[ligne][j] = BANNED;
                    }
                }
                colonne--;
            }
            
            
            
            boucle = -1;
            int scoreD =0;
            colonne = (player[ORDI].position.column);
            ligne = player[ORDI].position.line;
            
            while (boucle != 0) // on balaie vers la droite
            {
                if (BETWEEN_0_8(colonne))
                {
                    if (plateauOrdi->board[ligne][colonne] != BANNED && plateau->board[ligne][colonne] != TAKEN )
                    {
                        if (BETWEEN_0_8(ligne))
                        {
                            scoreD ++;
                            if (BETWEEN_0_8(ligne+1))
                            {
                                if (plateauOrdi->board[ligne+1][colonne] != BANNED && plateau->board[ligne+1][colonne] != TAKEN )
                                {
                                    if (BETWEEN_0_8(ligne+2))
                                    {
                                        if (plateauOrdi->board[ligne+2][colonne] != BANNED && plateau->board[ligne+2][colonne] != TAKEN )
                                        {
                                            scoreD+=2;
                                            boucle = 0;
                                        }
                                    }
                                    else
                                    {
                                        scoreD++;
                                        boucle = 0;
                                    }
                                }
                            }
                            else
                            {
                                scoreD++;
                                boucle = 0;
                            }
                        }
                    }
                    else
                    {
                        scoreD = 100;
                        boucle = 0;
                        for (int j = (player[ORDI].position.column+1) ; j > colonne; j++)
                        {
                            plateauOrdi->board[ligne][j] = BANNED;
                        }
                    }
                }
                else
                {
                    scoreD = 100;
                    boucle = 0;
                    for (int j = (player[ORDI].position.column+1) ; j > colonne; j++)
                    {
                        plateauOrdi->board[ligne][j] = BANNED;
                    }
                }
                colonne++;
            }
            
            if (scoreG <= scoreD && scoreG < 100)
            {
                player[ORDI].temp.line = player[ORDI].position.line;
                player[ORDI].temp.column = player[ORDI].position.column - 1;
                
                printf("à gauche toute G : %d  D : %d\n", scoreG, scoreD);
                
                mAJPoint(plateau, player);
            }
            else if (scoreG >= scoreD && scoreD < 100)
            {
                player[ORDI].temp.line = player[ORDI].position.line;
                player[ORDI].temp.column = player[ORDI].position.column + 1;
                
                printf("A droite G : %d  D : %d\n", scoreG, scoreD);
                
                mAJPoint(plateau, player);
            }
            else // scoreD et scoreG = 100
            {
                plateauOrdi->board[player[ORDI].position.line][player[ORDI].position.column] = BANNED;
                
                player[ORDI].temp.line = (player[ORDI].position.line - 1);
                player[ORDI].temp.column = player[ORDI].position.column;
                
                
                
                printf("On remonte G : %d  D : %d\n", scoreG, scoreD);
                
                mAJPoint(plateau, player);
            }
            
        }
    }
    
    else
    {
        printf("erreur ordi\n");
        player[ORDI].temp.line = (player[ORDI].position.line);
        player[ORDI].temp.column = (player[ORDI].position.column);
    }
    return EXIT_FAILURE;
}





PointCalcul rechercheMeilleurPoint (Plateau *plateau, point point, PointCalcul meilleurPointActuel, Plateau *plateauOrdi)
{
    PointCalcul temporaire;
    int score = 0, boucle =-1, ligne = (point.line+1);
    while (boucle != 0)
    {
        if (ligne == DIM_TAB)
        {
            boucle = 0;
        }
        else
        {
            if (plateau->board[ligne][point.column] != TAKEN)
            {
                score++;
                ligne++;
            }
            else
            {
                boucle = 0;
            }
        }
        
        
    }
    if (score > meilleurPointActuel.ValeurAssigneeOrdi)
    {
        temporaire.p = point;
        temporaire.ValeurAssigneeOrdi = score;
        return temporaire;
    }
    else
    {
        return meilleurPointActuel;
    }
}







void mAJPoint (Plateau *plateau, Player *player)
{
    
    plateau->board[player[ORDI].temp.line][player[ORDI].temp.column] = PAWN;
    plateau->board[player[ORDI].position.line][player[ORDI].position.column] = FREE;
    player[ORDI].position = player[ORDI].temp;
    player[ORDI].temp.line = -1;
    player[ORDI].temp.column = -1;
}
