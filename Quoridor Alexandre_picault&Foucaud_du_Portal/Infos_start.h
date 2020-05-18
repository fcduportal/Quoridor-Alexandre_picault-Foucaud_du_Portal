/* 
 Infos_start.h
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 04/04/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */



#ifndef Infos_start_h
#define Infos_start_h

///

void startingInfos(int *nb_players, int *duration, Player *player);

//request for the number of players

void demandNbPlayer (int *nb_players);

// request name player

void demandNamePlayer (int digit_player, Player player[]);

//request for party time

int demandTime (void);

///



#endif /* Infos_start_h */

