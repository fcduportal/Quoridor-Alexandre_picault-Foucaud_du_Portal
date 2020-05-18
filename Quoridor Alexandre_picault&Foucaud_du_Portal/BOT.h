//
//  BOT.h
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Foucaud de Bouët du Portal on 16/05/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//

#ifndef BOT_h
#define BOT_h

#include <stdio.h>

enum TypeOfPlayer
{
    Computer, Gamer
};
typedef enum TypeOfPlayer TypeOfPlayer;

int playBot (Player player[], Plateau *plateau, Plateau *plateauComputer);

PointCalculation searchBestPoint (Plateau *plateau, point point, PointCalculation bestCurrentPoint, Plateau *plateauComputer);

void updatePoint (Plateau *plateau, Player *player);

void displayMessage (void);

#endif /* BOT_h */
