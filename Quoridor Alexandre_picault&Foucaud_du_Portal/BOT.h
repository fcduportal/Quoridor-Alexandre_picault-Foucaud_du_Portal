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

int playBot (Player player[], Plateau *plateau);

#endif /* BOT_h */
