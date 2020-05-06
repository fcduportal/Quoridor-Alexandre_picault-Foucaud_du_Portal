/*
 IA.c
 Quoridor Alexandre_picault&Foucaud_du_Portal
 
 Created by Foucaud de Bouët du Portal on 03/05/2020.
 Copyright © 2020 Foucaud de Bouët du Portal&Alexandre Picault. All rights reserved.
 */


/*
 Main
 nb_bots = 0,
 
 fonction info start (&nb_bots,)
 
 
 
 fonction start
 
 printf ("Combien d'IA vont jouer ?\n"); // Get the number of bots.
 scanf("%d",&*nb_bots);
 printf("Il y a %d IA.\n\n",*nb_bots);
 
 nb_tot = *nb_players + *nb_bots; // Have the total number of players.
 
 
 
 
 if(nb_tot <= 4) // Verifing that the number of players is less than 4.
 {
 good = 1; // Exit while.
 }
 else // Loop.
 {
 printf("Desole, vous etes trop nombreux, le total de joueurs doit etre inferieur ou egale a 4.\n");
 }
 
 
 
 
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



