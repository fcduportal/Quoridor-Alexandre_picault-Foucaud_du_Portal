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
#include <stdlib.h>
#include <string.h>

#include "Fonctions_reutilisable.h"
#include "partie_jouer.h"
#include "Infos_start.h"
#include "random.h"
#include "unistd.h"

#include "One_player.h"
#include "two_Players.h"
#include "four_Players.h"

#define DIM_TAB 9
#define NB_CHAR 15
#define NB_FENCE_MAX 10
#define BETWEEN(value, min, max) (value <= max && value >= min)

///

#endif /* header_h */
