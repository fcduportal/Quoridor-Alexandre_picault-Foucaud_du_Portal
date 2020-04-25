//
//  Fonctions_reutilisable.h
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Foucaud de Bouët du Portal on 31/03/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//

#include <time.h>

#define Fonctions_reutilisable_h

#define NB_CHAR 20

void clear_console (void);

void delay (void);

struct coordinates
{
    int x;
    int y;
};
typedef struct coordinates coordinates;


struct pion
{
    char name[NB_CHAR];
    int number_player;
    int number_fence;
    coordinates coord;
};
typedef struct pion pion;


struct fence
{
    coordinates coord;
};
typedef struct fence fence;

void saisir_coord_Pion (coordinates *point);
void afficher_coord_Pion (coordinates *point);

