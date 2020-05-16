/*
 header.h
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 03/05/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



#ifndef header_h
#define header_h

///

#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "Fonctions_reutilisable.h"
#include "partie_jouer.h"
#include "Infos_start.h"
#include "random.h"
#include "unistd.h"

#include "BOT.h"
#include "One_player.h"

#include "two_Players.h"
#include "four_Players.h"

#define DIM_TAB 9
#define NB_CHAR 15
#define ASCII_A 65
#define NB_FENCE_MAX 10

#define LG_COLONNE ((DIM_TAB*2)+9)
#define LG_LIGNE ((DIM_TAB*4)+7)
#define NB_BLANCS(value, longueur_prenom) ((value - longueur_prenom)/2)

#define BETWEEN(value, min, max) (value <= max && value >= min)

#define ASCII_NUMBER(value) (value - ASCII_A)
#define NUMBER_ASCII(value) (value + ASCII_A)

#endif /* header_h */
