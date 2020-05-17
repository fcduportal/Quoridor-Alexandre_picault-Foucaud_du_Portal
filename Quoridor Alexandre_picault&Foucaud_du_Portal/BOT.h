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

enum TypeDeJoueur
{
    ORDI, JOUEUR
};
typedef enum TypeDeJoueur TypeDeJoueur;

int playBot (Player player[], Plateau *plateau, Plateau *plateauOrdi);

PointCalcul rechercheMeilleurPoint (Plateau *plateau, point point, PointCalcul meilleurPointActuel, Plateau *plateauOrdi);

void mAJPoint (Plateau *plateau, Player *player);


#endif /* BOT_h */
