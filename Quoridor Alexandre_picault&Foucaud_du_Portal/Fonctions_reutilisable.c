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

void clearConsole (void)
{
    printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // To erase console, not great but its work.
}

//



/// -------------------------------------------  Fence



Fence enterCoordFence (void)
{
    Fence Barrier = {-1, -1, -1, -1};
    int test = -1;
    
    while (test != 0)
    {
        Barrier.A = enterLinesColumns();
        Barrier.B = enterLinesColumns();
        
        if (BETWEEN_0_8(Barrier.A.line) && BETWEEN_0_8(Barrier.A.column) && BETWEEN_0_8(Barrier.B.line) && BETWEEN_0_8(Barrier.B.column))
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


point enterLinesColumns (void)
{
    char letter = ' ';
    int number = 0;
    point point = {-1, -1};
    
    
    scanf("%c",&letter); // This line is used in order to retrieve a charactere that we identified as "\n" wich comes from a line of code before the appeal of the function, but we didn't understood why it is here.
    
    printf("Veuillez saisir les coordonees souhaitee. (ie : A 2)\t");
    scanf("%c %d", &letter, &number);
    letter = toupper(letter);
    
    point.column = ASCII_NUMBER(letter);
    point.line = number;
    
    return point;
}



//



/// end Fence -------------------------------------------  begin Pawn



point enter_coord_Pawn (void)
{
    point point = {-1, -1};
    int test = -1;
    
    while (test != 0)
    {
        point = enterLinesColumns();

        
            if (BETWEEN_0_8(point.line) && BETWEEN_0_8(point.column))
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



int availabilityBox (point M, Plateau *plateau)
{
    if (plateau->board[M.line][M.column] != FREE)
    {
        printf("Impossible la case (%d;%d) est déjà prise.\n", M.line, M.column);
        return EXIT_FAILURE;
    }
    else
    {
        return EXIT_SUCCESS;
    }
}

//

int testAdjacent (point M, point N)
{
    if (M.line == N.line && ((M.column - N.column) == -1 || (M.column - N.column) == 1))
    {
        return EXIT_SUCCESS;
    }
    else if (M.column == N.column && ( (M.line - N.line) == -1 || (M.line-N.line) == 1) )
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



int hourglass (int *duration, time_t startTime )
{
    time_t currentTime = (time(NULL));
    time_t lapsedTime = difftime(currentTime, startTime );
    
    if (lapsedTime > (*duration*60))
    {
        return EXIT_FAILURE;
    }
    else
    {
        return EXIT_SUCCESS;
    }
}

//

int winner (Player *player)
{
    int state = EXIT_FAILURE;
    if (player[0].position.line == 8)
    {
        printf("Le joueur %s a gagne.\n", player[0].name);
        state = EXIT_SUCCESS;
    }
    if (player[1].position.line == 0)
    {
        printf("Le joueur %s a gagne.\n", player[1].name);
        state = EXIT_SUCCESS;
    }
    if (player[2].position.column == 8)
    {
        printf("Le joueur %s a gagne.\n", player[2].name);
        state = EXIT_SUCCESS;
    }
    if (player[0].position.column == 0)
    {
        printf("Le joueur %s a gagne.\n", player[3].name);
        state = EXIT_SUCCESS;
    }
    return state;
}


void display_board (Plateau *plateau, Player player[], int nbPlayer)
{
    char Player3Name[LG_COLONNE+1];
    char Player4Name[LG_COLONNE+1];
    unsigned long p3 = 0, p4 = 0;
    unsigned long lg3 = strlen(player[2].name), lg4 = strlen(player[3].name);
    
    p3 = NB_BLANCS(LG_COLONNE, lg3);
    p4 = NB_BLANCS(LG_COLONNE, lg4);
    
    for (int i = 0; i < p3 ; i++)
    {
        Player3Name[i] = ' ';
    }
    for (unsigned long i = p3; i < (p3 + lg3) ; i++)
    {
        Player3Name[i] = player[2].name[i - p3];
    }
    for (unsigned long i = (p3 + lg3) ; i < LG_COLONNE ; i++)
    {
        Player3Name[i] = ' ';
    }

   Player3Name[LG_COLONNE] = '\0';
    
    
    for (int i = 0; i < p4 ; i++)
    {
        Player4Name[i] = ' ';
    }
    for (unsigned long i = p4; i < (p4 + lg4) ; i++)
    {
        Player4Name[i] = player[3].name[i - p4];
    }
    for (unsigned long i = (p4 + lg4) ; i < LG_COLONNE ; i++)
    {
        Player4Name[i] = ' ';
    }
    Player4Name[LG_COLONNE] = '\0';

    
    clearConsole();
    
    int cursor = 0 ;
    
    displayPlayerName(player[0], Player3Name[cursor], Player4Name[cursor]) ;
    cursor++;
    
    displayEmptyLine(Player3Name[cursor], Player4Name[cursor]);
    cursor++;
    
    displayAbscisses(Player3Name[cursor], Player4Name[cursor]);
    cursor++;
    
    displayLines(Player3Name[cursor],  Player4Name[cursor]);
    cursor++;
    
    for (int i = 0; i < 9; i++)
    {

        printf("%c  %d", Player3Name[cursor], i);
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
                    for (int k=0; k<nbPlayer; k++)
                    {
                        if (player[k].position.line == i &&  player[k].position.column == j)
                        {
                            printf("| %d ", player[k].affichage);
                        }
                    }
                    break;
                }
            }
        }
        printf("|%d  %c\n", i, Player4Name[cursor]);
        cursor++;

        displayLines(Player3Name[cursor], Player4Name[cursor]) ;
        cursor++;
    }
    displayAbscisses(Player3Name[cursor], Player4Name[cursor]);
    cursor++;
    
    displayEmptyLine(Player3Name[cursor], Player4Name[cursor]);
    cursor++;
    
    displayPlayerName(player[1], Player3Name[cursor], Player4Name[cursor]);
    printf("\n\n");
}




void displayPlayerName (Player player, char c1, char c2)
{
    unsigned long nameLength = strlen(player.name);
    int lineLength = LG_LIGNE;
    unsigned long nbSpaces = (lineLength - nameLength)/2 + 1;
    
    printf("%c", c1);
    for (int i = 1; i < nbSpaces; i++) // first caractere = c1
    {
        printf(" ");
    }
    printf("%s", player.name);
    for (unsigned long i = (nbSpaces + nameLength); i < (LG_LIGNE -1); i++)
    {
        printf(" ");
    }
    printf ("%c\n", c2);
}




void displayAbscisses(char c1, char c2)
{
    printf("%c   ", c1);
 for (int columns = 0; columns < DIM_TAB; columns++)
    {
        int columnChar = NUMBER_ASCII(columns);
        printf("  %c ", columnChar);
    }
    printf("  %c\n", c2);
}




void displayLines (char c1, char c2)
{
    printf("%c   ", c1);
    for (int i = 0; i < DIM_TAB; i++)
    {
        printf("|---");
    }
    printf("|   %c\n", c2);
}





void displayEmptyLine (char c1, char c2)
{
    printf("%c", c1);
    for (int i = 1; i < (LG_LIGNE-1); i++)
    {
        printf(" ");
    }
    printf("%c\n",c2);
}

#endif /* Fonctions_reutilisable_h */
