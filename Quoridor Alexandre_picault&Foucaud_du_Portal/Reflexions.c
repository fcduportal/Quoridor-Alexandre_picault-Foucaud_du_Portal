/*
 Reflexions.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 04/04/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */


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
 
 
    Si il y a un pion devant lui vérifier la case derriere le pion 
 
 
 
 */












/*
 enumeration : partie
 en_cours / terminé / non_debuté
 
 tant que la partie est pas termine
    jouer tout les joueurs un a un
    
 
 
 
 menu recommencer
 printf ("voulze recommencer )
 printf (1OUI 2non )
 
 switch
 1
 {
 printf ("voulez allez recommencer,si oui tapez 1,sinon tapez 2:);
 scanf(%d,&fin)
 clear console
 main ();
 }
 
 2
 {
 au revoir bonne nuit
 exit 0;
 }
 
 default
 {
 vous devez
 clear console 
 menu recomencer();
 }
 

 
 
 pour alterner les joueurs :
 while la partie est pas terminée
 joueurs = (+1%2)
 permet d'alterner entre les joueurs
 
 
 */
