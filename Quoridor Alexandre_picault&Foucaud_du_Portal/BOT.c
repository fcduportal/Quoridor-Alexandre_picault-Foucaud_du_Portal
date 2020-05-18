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
     This feature allows the computer to play alone and choose the action to be performed.
     Its first strategy is to go straight ahead if possible.
     If it cannot (barrier or pawn in front of it) it evaluates whether it is better to go right or left.
     he looks to see if there is an opening to go down.
     and checks that it is not a dead end.
     
     He chooses to go to the most interesting square if possible. ie: where the path is the shortest to go down 2 squares.
     If it is a pawn, he will put a barricade (behind him). it is not yet established.
     If it is a barrier he will move.
     
     If a pawn blocks his way, he chooses to put a barrier behind it.
     */
    
    // the computer sees if it can move forward. (The box in front of it is empty)
    
    player[Computer].temp.line = (player[Computer].position.line + 1); // We initialize the square the computer wants to go to.
    player[Computer].temp.column = (player[Computer].position.column);
    
    
    if (BETWEEN_0_8(player[Computer].temp.line) && BETWEEN_0_8(player[Computer].temp.column)) //Check box coordinates.
    {
        if (plateauComputer->board[player[Computer].temp.line][player[Computer].temp.column] == POSSIBLE && availabilityBox(player[Computer].temp, plateau) ==
            EXIT_SUCCESS)// If the square is clear and it's not a dead end.
        {
            updatePoint(plateau, player); // He's updating the set.
            
            return EXIT_SUCCESS;
        }
        else
        {
//We check that the square in front of him is a pawn...
            if (plateauComputer->board[player[Computer].temp.line][player[Computer].temp.column] == POSSIBLE && plateau->board[player[Computer].temp.line][player[Computer].temp.column] == PAWN)
            {
                /*
                 If it's a pawn, you put a fence behind the computer.
                 It chooses to take the first two free squares and adjacent two lines behind it.
                 */
                
                
                int linePoint1 = (player[Computer].position.line - 2);
                
                
                int columnPoint1 = 0;
                int columnPoint2 = 0;
                int linePoint2 = 0;
                
                int loopFence=-1, j=0;
                while (loopFence != 0)
                {
                    if (BETWEEN_0_8(linePoint1))
                    {
                        if (BETWEEN_0_8(j+1))
                        {
                            if (plateau->board[linePoint1][j] == FREE && (plateau->board[linePoint1][j+1] == FREE))
                            {
                                columnPoint1 = j;
                                columnPoint2 = j+1;
                                linePoint2 = linePoint1;
                                loopFence = 0;
                            }
                            else
                            {
                                j++;
                            }
                        }
                        else
                        {
                            j=0;
                            linePoint1++;
                        }
                    }
                    else
                    {
                        linePoint1++;
                    }
                    plateau->board[linePoint1][columnPoint1] = TAKEN;
                    plateau->board[linePoint2][columnPoint2] = TAKEN;
                    player[Computer].temp.line = -1;
                    player[Computer].temp.column = -1;
                    return EXIT_SUCCESS;
                }
            }
            
            
            /*
             The first step is to sweep to the left of the line to see if you can go down at least two spaces.
             The number of squares to be covered is used to calculate the score and then choose the path.
             If it's a dead end it marks these squares as 'Banned' in a virtual board so that you don't come back on it later.
             In this last case the score is equal to 100.
             */
            
            
            
            int scoreG = 0, loop = -1;
            int column = (player[Computer].position.column);
            int line = player[Computer].position.line;
            
            
            while (loop != 0) // We sweep to the left
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
            
            // He does the same thing on the right.
            
            loop = -1;
            int scoreD =0;
            column = (player[Computer].position.column);
            line = player[Computer].position.line;
            
            while (loop != 0) // we sweep to the right
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
            
            /*
             We compare the two scores to see which way to go.
             The lower score determines which side.
             If both scores are equal to 100, the square on which it is located becomes forbidden. And it goes up.
             */
            
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
            else // scoreD and scoreG = 100
            {
                plateauComputer->board[player[Computer].position.line][player[Computer].position.column] = BANNED;
                
                player[Computer].temp.line = (player[Computer].position.line - 1);
                player[Computer].temp.column = player[Computer].position.column;
                
                updatePoint(plateau, player);
            }
        }
    }
    return EXIT_SUCCESS;
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
