/*
 partie_jouer.h
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Alexandre Picault on 25/04/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



#ifndef partie_jouer_h
#define partie_jouer_h

///

#include <stdio.h>

// 


//play a Fence

int playFence (Player *player, int digitPlayer, Plateau *plateau);


//play a pawn

int playPawn (Player *player, Plateau *plateau);

///

#endif /* partie_jouer_h */
