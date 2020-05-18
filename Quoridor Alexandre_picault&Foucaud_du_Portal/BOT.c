//
//  BOT.c
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Foucaud de Bouët du Portal on 16/05/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//

#include "header.h"

int playBot (Player player[], Plateau *plateau, Plateau *plateauComputer)
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
    
    
    
    player[Computer].temp.line = (player[Computer].position.line + 1);
    player[Computer].temp.column = (player[Computer].position.column);
    
    
    if (BETWEEN_0_8(player[Computer].temp.line) && BETWEEN_0_8(player[Computer].temp.column))
    {
        if (plateauComputer->board[player[Computer].temp.line][player[Computer].temp.column] == POSSIBLE && availabilityBox(player[Computer].temp, plateau) ==
                EXIT_SUCCESS)
        {
            updatePoint(plateau, player);
            
            return EXIT_SUCCESS;
        }
        else
        {
            printf("Case interdite. ou pas dispo\n");
            
            int scoreG = 0, loop = -1;
            int column = (player[Computer].position.column);
            int line = player[Computer].position.line;
            
            
            while (loop != 0) // on balaie vers la gauche
            {
                if (BETWEEN_0_8(column))
                {
                    if (plateauComputer->board[line][column] != BANNED && plateau->board[line][column] != TAKEN )
                    {
                        if (BETWEEN_0_8(line))
                        {
                            scoreG ++;
                            if (BETWEEN_0_8(line + 1))
                            {
                                if (plateauComputer->board[line + 1][column] != BANNED && plateau->board[line + 1][column] != TAKEN )
                                {
                                    if (BETWEEN_0_8(line+2))
                                    {
                                        if (plateauComputer->board[line + 2][column] != BANNED && plateau->board[line + 2][column] != TAKEN )
                                        {
                                            scoreG+=2;
                                            loop = 0;
                                        }
                                    }
                                    else
                                    {
                                        scoreG++;
                                        loop = 0;
                                    }
                                }
                            }
                            else
                            {
                                scoreG++;
                                loop = 0;
                            }
                        }
                    }
                    else
                    {
                        scoreG = 100;
                        loop = 0;
                        for (int j = (player[Computer].position.column - 1) ; j > column; j--)
                        {
                            
                            plateauComputer->board[line][j] = BANNED;
                        }
                    }
                }
                else
                {
                    scoreG = 100;
                    loop = 0;
                    for (int j = (player[Computer].position.column - 1) ; j > column; j--)
                    {
                        plateauComputer->board[line][j] = BANNED;
                    }
                }
                column--;
            }
            
            
            
            loop = -1;
            int scoreD =0;
            column = (player[Computer].position.column);
            line = player[Computer].position.line;
            
            while (loop != 0) // on balaie vers la droite
            {
                if (BETWEEN_0_8(column))
                {
                    if (plateauComputer->board[line][column] != BANNED && plateau->board[line][column] != TAKEN )
                    {
                        if (BETWEEN_0_8(line))
                        {
                            scoreD ++;
                            if (BETWEEN_0_8(line + 1))
                            {
                                if (plateauComputer->board[line + 1][column] != BANNED && plateau->board[line + 1][column] != TAKEN )
                                {
                                    if (BETWEEN_0_8(line+2))
                                    {
                                        if (plateauComputer->board[line + 2][column] != BANNED && plateau->board[line + 2][column] != TAKEN )
                                        {
                                            scoreD+=2;
                                            loop = 0;
                                        }
                                    }
                                    else
                                    {
                                        scoreD++;
                                        loop = 0;
                                    }
                                }
                            }
                            else
                            {
                                scoreD++;
                                loop = 0;
                            }
                        }
                    }
                    else
                    {
                        scoreD = 100;
                        loop = 0;
                        for (int j = (player[Computer].position.column + 1) ; j > column; j++)
                        {
                            plateauComputer->board[line][j] = BANNED;
                        }
                    }
                }
                else
                {
                    scoreD = 100;
                    loop = 0;
                    for (int j = (player[Computer].position.column + 1) ; j > column; j++)
                    {
                        plateauComputer->board[line][j] = BANNED;
                    }
                }
                column++;
            }
            
            if (scoreG <= scoreD && scoreG < 100)
            {
                player[Computer].temp.line = player[Computer].position.line;
                player[Computer].temp.column = player[Computer].position.column - 1;
                
                updatePoint(plateau, player);
            }
            else if (scoreG >= scoreD && scoreD < 100)
            {
                player[Computer].temp.line = player[Computer].position.line;
                player[Computer].temp.column = player[Computer].position.column + 1;
                
                updatePoint(plateau, player);
            }
            else // scoreD et scoreG = 100
            {
                plateauComputer->board[player[Computer].position.line][player[Computer].position.column] = BANNED;
                
                player[Computer].temp.line = (player[Computer].position.line - 1);
                player[Computer].temp.column = player[Computer].position.column;
                
                updatePoint(plateau, player);
            }
        }
    }
    
    else
    {
        printf("erreur ordi\n");
        player[Computer].temp.line = (player[Computer].position.line);
        player[Computer].temp.column = (player[Computer].position.column);
    }
    return EXIT_FAILURE;
}





PointCalculation searchBestPoint (Plateau *plateau, point point, PointCalculation bestCurrentPoint, Plateau *plateauComputer)
{
    PointCalculation temp;
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
    if (score > bestCurrentPoint.ValeurAssigneeOrdi)
    {
        temp.p = point;
        temp.ValeurAssigneeOrdi = score;
        return temp;
    }
    else
    {
        return bestCurrentPoint;
    }
}


void updatePoint (Plateau *plateau, Player *player)
{
    plateau->board[player[Computer].temp.line][player[Computer].temp.column] = PAWN;
    plateau->board[player[Computer].position.line][player[Computer].position.column] = FREE;
    player[Computer].position = player[Computer].temp;
    player[Computer].temp.line = -1;
    player[Computer].temp.column = -1;
}


void displayMessage (void)
{
const char *mots[NB_CHAR] = {"Je reflechis.", "2 petites secondes.", "Tu ne m'auras pas.", "uhm uhm", "Floor gang", "GRRR", "PEEKABOO"};
    
    time_t temps = time(NULL);
    unsigned long i = temps % 7;
    
    printf("\n%s", mots[i]);
    usleep(100000);
    usleep(100000);
    usleep(100000);
    printf(".");
    usleep(100000);
    usleep(100000);
    usleep(100000);
    printf(".");
    usleep(100000);
    usleep(100000);
    usleep(100000);
    printf(".\n");
    usleep(1000000);
}
