/************************************************************/
/*            PIERRE FEUILLE CISEAUX (console)              */
/*   Le joueur essaye de deviner une combinaison de         */
/*  chiffres en un minimum de coups.                        */
/*   Le joueur enrre une lettre au clavier puis on affiche  */
/* les lettres qui ont été trouvées.                        */
/*   Jeu pour Windows, aucune librairie nécessaire.         */
/*                                                          */
/************************************************************/

/************************************************************/
/*                         main.c                           */
/*   Ce fichier contient la fonction main ainsi que :       */
/*      - une fonction qui choisit un élément aléatoirement.*/
/*      - une fonction qui affiche le nom de l'élément.     */
/*   Auteur : Alex Barféty                                  */
/*   Date de création : 27/12/2007                          */
/*   Date de modification : 06/11/2008                      */
/*                                                          */
/************************************************************/

#include "main.h"

#ifndef LINUX
	#define CLEAR system("CLS")
#elif
	#define CLEAR system("clear")
#endif

/*Programme qui permet de jouer à pierre feuille ciseaux contre l'ordinateur.
-sans triche-*/

int main(int argc, char *argv[])
{
	//     DECLARATION DES VARIABLES ET DES CONSTANTES

	const char e = '\x82', ee = '\x8A', a = '\x85' ;
	/* e <=> 'é' ; ee <=> 'è' ; a <=> 'ê'*/

	int nb_manches, nb_manches_tot, nb_manchesJ, nb_manchesO ;
	char choix, elementJ, elementO, match, eltJ[11], eltO[11] ;

	//     INITIALISATION

	srand(time(NULL)) ;

	//     ON COMMENCE A JOUER
	do
	{
		do
		{
			CLEAR ;
			printf("\t\t\tPIERRE | FEUILLE | CISEAUX") ;
			printf("\n\n\n\tBienvenue dans pierre, feuille, ciseaux !!") ;
			printf("\n\n\tR%cgles du jeu :\nLe joueur choisis l'un des trois %cl%cments pour l'opposer %c celui de l'adversaireCelui qui remporte l'affrontement marque un point.", ee, e, e, a) ;
			printf("\n\nRappel :\tLa feuille enveloppe la pierre.\n\t\tLa pierre casse les ciseaux.\n\t\tLes ciseaux coupent la feuille.") ;
			printf("\n\n\n\tEn combien de manches gagnantes voulez-vous jouer ? ") ;
			scanf("%d", &nb_manches_tot) ;
		} while (nb_manches_tot < 1) ; //On vérifie si le nombre de manches gagnantes est valide.
		nb_manchesJ = 0 ; //On met le nombre de manches gagnées par le joueur à 0.
		nb_manchesO = 0 ; //On met le nombre de manches gagnées par l'ordinateur à 0.
		nb_manches = 0 ; //On met le compteur de manches à zéro.
		while ((nb_manchesJ != nb_manches_tot) && (nb_manchesO != nb_manches_tot))
		{
			nb_manches++ ;
			do
			{
				CLEAR ;
				printf("\t\t\t\tMANCHE N\xF8%d", nb_manches) ;
				printf("\n\n\n\tScores (%d manches gagnantes) :\n\t\tVous : %d\t\t\tOrdinateur : %d\n\n", nb_manches_tot, nb_manchesJ, nb_manchesO) ;
				if (nb_manchesJ - nb_manchesO == 0) {printf("\t\t\t\tEgalit%c !!", e) ;}
				else if (nb_manchesJ - nb_manchesO < 0) {printf("\t\t\tL'ordinateur gagne !!") ;}
				else {printf("\t\t\tVous gagnez !!") ;}
				printf("\n\n\n\n\tQue choisissez vous (entrez la premi%cre lettre de l'%cl%cment) ? ", ee, e, e) ;
				while (getchar() != '\n') ;
				scanf("%c", &elementJ) ;
			} while ((elementJ!='p') && (elementJ!='f') && (elementJ!='c')) ; //On vérifie la réponse donnée.
			elementO = int_art() ; //On donne une valeur aléatoire à elementO.
			if (elementO == elementJ) {match = 'n' ;} //en cas d'égalité.
			else if ((elementO=='p' && elementJ=='c') || (elementO=='f' && elementJ=='p') || (elementO=='c' && elementJ=='f')) {match = 'O' ;} //Si l'ordinateur gagne.
			else {match = 'J' ;} //Si le joueur gagne.
			print_element(elementO, eltO) ; //On écrit dans une chaîne de caractères le nom complet de l'élément.
			print_element(elementJ, eltJ) ;
			system("CLS") ; //Affichage du résumé de la manche en cours.
			printf("\t\t\tRapport de combat :") ;
			printf("\n\n\n\tVous avez jou%c : %s.\n\n\tL'ordinateur a d%ccid%c d'opposer %s.", e, eltJ, e, e, eltO) ;
			printf("\n\n") ;
			//On affiche le r�sultat du 'combat' entre les deux �l�ments.
			if (elementO == elementJ) {printf("Pas de vainqueur : les %cl%cments sont identiques (%s).", e, e, eltO) ;}
			else if ((elementO == 'p' && elementJ == 'f') || (elementO == 'f' && elementJ == 'p')) {printf("La feuille enveloppe la pierre.") ;}
			else if ((elementO == 'f' && elementJ == 'c') || (elementO == 'c' && elementJ == 'f')) {printf("Les ciseaux coupent la feuille.") ;}
			else {printf("La pierre casse les ciseaux.") ;}
			printf("\n\n") ;
			switch (match) //Le vainqueur de la manche est...
			{
				case 'n' : printf("Match nul : aucun point attribu%c.", e) ;
						   break ;
				case 'O' : printf("L'ordinateur remporte la manche !") ;
						   nb_manchesO++ ;
						   break ;
				case 'J' : printf("Vous remportez cette manche !! Bravo !!") ;
						   nb_manchesJ++ ;
						   break ;
			}
			printf("\n\n\n\t\t\t\tFIN DE LA MANCHE N\xF8%d\n\n\t", nb_manches) ;
			system("pause") ;
		}
		do
		{
			CLEAR ;
			printf("\n\n\n\t\t\t\tFIN DU JEU\n\n\n\t") ;
			if (nb_manchesJ == nb_manches_tot)
			{
				printf("Vous gagnez par %d %c %d !! F%clicitations !!", nb_manches_tot, a, nb_manchesO, e) ;
			}
			else
			{
				printf("L'ordinateur vous a battus par %d %c %d. Pas de chance !!", nb_manches_tot, a, nb_manchesJ) ;
			}
			printf("\n\n\n\n") ;
			printf("\n\nEncore une partie ('o' ou 'n') ? ") ;
			while (getchar() != '\n') ;
			scanf("%c", &choix) ;
		} while ((choix!='o') && (choix!='n')) ; //On vérifie la réponse donnée.
	} while (choix == 'o') ; //Le joueur veut-il recommencer ?
	printf("\n\n\n\n\n\t\tJeu cr%c%c par Alex Barf%cty le 28/12/2007.\n\n\n", e, e, e) ;
	system("pause") ;
	return 0 ;
}

//Fonction qui renvoie un élément aléatoire :
char int_art (void)
{
		char element = ' ' ;
		int n ;
		n = rand()%(3) ;
		switch (n)
		{
			case 0 : element = 'p' ; //Pierre.
					 break ;
			case 1 : element = 'f' ; //Feuille.
					 break ;
			case 2 : element = 'c' ; //Ciseaux.
					 break ;
		}
		return element ;
}

//Fonction qui écrit le nom de l'élément correspondant dasn une chaîne de caractères :
void print_element (char element, char elt[11])
{
	switch (element)
	{
		case 'p' : sprintf(elt, "la pierre") ;
				   break ;
		case 'f' : sprintf(elt, "la feuille") ;
				   break ;
		case 'c' : sprintf(elt, "les ciseaux") ;
				   break ;
	}
}
