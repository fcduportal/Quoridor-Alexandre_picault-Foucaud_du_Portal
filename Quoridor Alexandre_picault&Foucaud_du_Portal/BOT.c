//
//  BOT.c
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Foucaud de Bouët du Portal on 16/05/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//

#include "header.h"

int playBot (Player player[], Plateau *plateau)
{
    /*
     Cette fonction permet à l'ordinateur de jouer seul et de choisir l'action à effectuer.
     Sa première stratégie est d'avancer tout droit si possible.
     s'il ne peut pas (barrière ou pion devant lui) il evalue l'interet d'aller sur chacune des cases qui l'entourent.
     Il choisi d'aller sur la case la plus interessante si possible.
     Si c'est un pion, il va poser une barière (derrière lui).
     Si c'est une barrière il va se déplacer.
     */
    
    // l'ordi regarde s'il peut avancer. (La case devant lui est vide)
    int test = -1;
    player[ORDI].temp.ligne = (player[ORDI].position.ligne+1);
    player[ORDI].temp.colonne = (player[ORDI].position.colonne);
    if (BETWEEN(player[ORDI].temp.ligne, 0, 8) && BETWEEN(player[ORDI].temp.colonne, 0, 8))
    {
        test = 0;
    }
    else
    {
        printf("erreur ordi\n");
    }
    
    if (test == 0)
    {
        test = availability_Box(player[ORDI].temp, plateau);
        if (test == EXIT_SUCCESS)
        {
            mAJPoint(plateau, player);

            return EXIT_SUCCESS;
        }
        else
        {
            
            PointsAdjacents pointsAdjacents;
            PointCalcul meilleurPoint;
            meilleurPoint.p.ligne=-1;
            meilleurPoint.p.colonne=-1;
            meilleurPoint.ValeurAssigneeOrdi=-1;
            
            
            pointsAdjacents.droite.p = initialiserPointsAdjacentsPion (player[ORDI].position.ligne, (player[ORDI].position.colonne + 1), plateau);
            if (pointsAdjacents.droite.p.colonne != -1)
            {
                meilleurPoint = rechercheMeilleurPoint(plateau, pointsAdjacents.droite.p, meilleurPoint);
            }
            
            
            pointsAdjacents.gauche.p = initialiserPointsAdjacentsPion (player[ORDI].position.ligne, (player[ORDI].position.colonne - 1), plateau);
            if (pointsAdjacents.gauche.p.colonne != -1)
            {
                meilleurPoint = rechercheMeilleurPoint(plateau, pointsAdjacents.gauche.p, meilleurPoint);
            }
            
            
            pointsAdjacents.devant.p = initialiserPointsAdjacentsPion ((player[ORDI].position.ligne+1), player[ORDI].position.colonne, plateau);
            if (pointsAdjacents.devant.p.colonne != -1)
            {
                meilleurPoint = rechercheMeilleurPoint(plateau, pointsAdjacents.devant.p, meilleurPoint);
            }
            
            
            pointsAdjacents.derriere.p = initialiserPointsAdjacentsPion (player[ORDI].position.ligne-1, player[ORDI].position.colonne, plateau);
            if (pointsAdjacents.derriere.p.colonne != -1)
            {
                meilleurPoint = rechercheMeilleurPoint(plateau, pointsAdjacents.derriere.p, meilleurPoint);
            }
            
            
            
                        printf("droit : (%d;%d) -> %d \t gauche : (%d;%d)-> %d\t devant : (%d;%d)-> %d\t derriere : (%d;%d)-> %d\n",pointsAdjacents.droite.p.ligne, pointsAdjacents.droite.p.colonne,pointsAdjacents.droite.ValeurAssigneeOrdi, pointsAdjacents.gauche.p.ligne, pointsAdjacents.gauche.p.colonne, pointsAdjacents.gauche.ValeurAssigneeOrdi, pointsAdjacents.devant.p.ligne, pointsAdjacents.devant.p.colonne, pointsAdjacents.devant.ValeurAssigneeOrdi, pointsAdjacents.derriere.p.ligne, pointsAdjacents.derriere.p.colonne, pointsAdjacents.derriere.ValeurAssigneeOrdi);
            printf("meilleur point (%d;%d) -> %d\n",meilleurPoint.p.ligne, meilleurPoint.p.colonne,meilleurPoint.ValeurAssigneeOrdi);
            
            
            
            player[ORDI].temp = meilleurPoint.p;
            
        }
    }
    return EXIT_FAILURE;
}





PointCalcul rechercheMeilleurPoint (Plateau *plateau, point point, PointCalcul meilleurPointActuel)
{
    PointCalcul temporaire;
    int score = 0, boucle =-1, ligne = (point.ligne+1);
    while (boucle != 0)
    {
        if (ligne == DIM_TAB)
        {
            boucle = 0;
        }
        else
        {
            if (plateau->board[ligne][point.colonne] != TAKEN)
            {
                score++;
                ligne++;
            }
            else
            {
                boucle = 0;
            }
        }
    }
    if (score > meilleurPointActuel.ValeurAssigneeOrdi)
    {
        temporaire.p = point;
        temporaire.ValeurAssigneeOrdi = score;
        return temporaire;
    }
    else
    {
        return meilleurPointActuel;
    }
}





void mAJPoint (Plateau *plateau, Player *player)
{
    
    plateau->board[player[ORDI].temp.ligne][player[ORDI].temp.colonne] = PAWN;
    plateau->board[player[ORDI].position.ligne][player[ORDI].position.colonne] = FREE;
    player[ORDI].position = player[ORDI].temp;
    player[ORDI].temp.ligne = -1;
    player[ORDI].temp.colonne = -1;
}
