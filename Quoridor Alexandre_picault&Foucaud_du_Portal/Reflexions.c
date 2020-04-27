//
//  Reflexions.c
//  Quoridor Alexandre_picault&Foucaud_du_Portal
//
//  Created by Foucaud de Bouët du Portal on 04/04/2020.
//  Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
//



/*
 REFLEXION PRELIMINAIRES :
 
 
 
 BUT : Avancer son pion jusqu'au bout du plateau avant son adversaire.
 
 Présentation :
 - Un plateau de jeu
 - 2 zones de stockages
 - 20 barières et 4 pions
 
 Sous programmes nécessaires  :
 
 
 - Début :
 ( Enoncer les règles )
    infos nécéssaires
        
        Demander le nombre de joueurs humains;
        Demander le nombre de joueurs IA;
        Demander la durée de la partie ( entre 10 à 20 min )
 
    Présentation
A        Placer le plateau;
F        Placer les joueurs humains et IA dans leur emplacement de départ;
F        Placer les barrières dans leurs espaces de stockage;
A        Determiner par un tirage au sort qui commence;
A        Commencer le décompte;
 
 
 
 Fonctions à faire :
 
 Rentrer coordonées pion
 rentrer cooordonnées barrières
 
 struct barière 20
 {
 player
 n° barière
 cooordonées
 }
 
 struct pion 4
{
 Numéro player
 Nb barrière restant
 cooordonées
 }
 
 
 
 
 - Jouer :
    Commencer par le joueur choisi;
        fonction random
 
 
        Joueur humain
        Lui demander s'il veut jouer une barière ou son pion;
  si
        Barrière
                Regarder s'il lui reste des barières;
                    si il lui en reste;
                        Demander où placer sa barière (coordonnées des deux cases de la barière);
                    si les deux cases sont à coté horizontement ou verticalement;
                    si la case est libre;
                        alors accepter l'emplacement
                    sinon
                        lui dire le problème et lui demander de rentrer d'autres coordonées
                        Appel fonction rentrer coordonnées
 
                    Sinon lui annoncer qu'il ne lui en reste pas

 
 sinon
        Pion
Lui rappeler ou il est
 Demander où placer son pion (coordonnées de la cases);
 si la case du pion et celle souhaitée sont à coté horizontement ou verticalement;
 si la case est libre;
 alors accepter l'emplacement
 sinon
 lui dire le problème et lui demander de rentrer d'autres coordonées
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 Comment faire l'IA:
 
 
 struct jeubot
 {
 toutes les actions qu'il peut faire
 Pour chacunes des ces actions il doit determiner toute les actions que peut faire le joueur
 Calcul des toute les actions qu'il peut faire
 
 }
 
 
 Quand c'est au tour de l'IA, il doit pouvoir déterminer toute les possibilitées de jeu qu'il peut faire ainsi que toute les possibilitées de jeu du joueur après avoir lui même joué et enfin une dernière fois ses possibilitées de jeu.
 (on peut améliorer pour qu'il fasse cela le nombre de fois qu'on détermine au début de la partie)
 
 Pour cela on doit créer un tableau contenant pour chaque possibilitées de jeu : les actions / les coordonées (C1 et C2 : C1 pour un pion, C1 et C2 pour une barrière; nombres compis entre 00 et 99 : xX -> x N° ligne, X -> n° colonne) / le nombre de lignes qui lui reste jusqu'a la fin / l'adresse du tableau de possibilités suivant
 
 On peut commencer pour determiner quelle action qu'il va faire plutôt qu'une autre par determiner le nombre de lignes qu'il lui reste jusqu'à la fin et choisir l'action qui l'amenera le plus vite au plus petit nombre (dans ce cas il va toujours avancer et jamais mettre de barrières)
 on peut sinon determiner par le chemin qui utilise le moins d'actions possibles pour arriver au résultat attendu.
 ou encore la solution qui propose le plus de résultats satisfaisants.
 
 Le mieux serait d'attribuer des coefficients à chaque action exemple : 2 pour avancer, 1 pour ralentir le joueuer adverse ... et choisir l'action qui a la meilleure somme pondéré de ces valeurs. Les coefficients pourraient varier en fonction de l'avancement du pion adverse.

 */





