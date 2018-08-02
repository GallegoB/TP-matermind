/* mastermind
 * auteur : Baptiste G
 * date : 26/10/2011
 */

//--- bibliothèques nécessaires ---
#include <stdio.h>
#include <conio.h>
#include <myconio.h>

typedef	char typFormule[5]; // vecteur de caractére de 5 cases



//--- fonction test couleur
bool caracValide(char c){
	char tab[7]={'B', 'R', 'V', 'N', 'J', 'O', 'G'}; // tab avec les couleur autoriser
	int k;

	for (k = 0; k <= 6; k++){
		if (tab[k]==c){
			return true; // si C egal une couleur alors retourne vrai
		}

	}
	return false; // si c n'est pas egal a une couleur retourne faux
}

//--- fonction saisie couleur
char saisieCouleur(int x, int y){
	char c;
	do{
	gotoxy(x, y);
	c = getche();
	}while( caracValide(c) != TRUE);
	return c;
}

//---fontion Calcul des bien placés
int calculBP(typFormule &vec1, typFormule &vec2){
	int i, BP=0;
	for(i=0; i<=4; i++){
		if (vec1[i] == vec2[i]){
			BP++;
			vec1 [i] = 'x';
			vec2 [i] = 'y';
		}
	}
	return BP;
}

//--- fonction Calcul des mals placés
int calculMP(typFormule &vec1,typFormule &vec2){
	int i, k, MP=0;

	for(i=0; i<=4; i++){
		for(k=0; k<=4; k++){
			if(vec1[i]==vec2[k]){
				MP++;
				vec1[i] = 'x' ;
				vec2[k] = 'y' ;
			}
		}
	}
	return MP;
}

//--- fonction affiche du nombre de biens et placés
void afficheValeur(int x,int  y,int  val){
	gotoxy(x, y);
	printf("%d", val);
}


//--- programme principale ---
int main() {

	typFormule varOriginal, varCopie, varEssai ;
	int BP , MP ; // Pour compter les biens et les mal placés
	int	nbEssai = 0; // pour compter le nombre d'essai
	int	i ; // une indice i de parcours de vecteurs

	// saisie de la formule d'origine joureur 1
	printf("1ere joueur:");

	for (i=0 ; i<=4 ; i++){ // boucle pour renplie les 5 couleur dans varOriginal

		varOriginal[i]= saisieCouleur((20+i*4), 1);

	}

	system("cls"); // efface l'ecran avan que le joueur 2 joue
	printf("2eme joueur:                               Bien plac\x82        Mal plac\x82");

	// boucle pour les essais
	do{
		nbEssai++;
		gotoxy(1, nbEssai+1);
		printf("Essai %d", nbEssai);
		// boucle pour la saisie des essai + copie de varOriginal dans varCopie
		for(i=0; i<=4; i++){

			varEssai[i] = saisieCouleur((20+i*4), nbEssai+1);
			varCopie[i] = varOriginal[i];
 		}

		// calcul des biens placés
		BP = calculBP(varCopie , varEssai);
		MP = calculMP(varCopie , varEssai);

		afficheValeur(45, nbEssai+1, BP);
		afficheValeur(60, nbEssai+1, MP);

	}while (5 > BP); // jusqu'a ce qu'il y ait 5 bien placés
	// la réponse est trouver donne le nb d'essai et bravo si -6 correct -11 et décevant +11
	gotoxy(1 , nbEssai+2);
	printf("La formule a \x82t\x82 trouvee\x82 en %d essais : ", nbEssai);

	if (nbEssai < 6){
		printf("Bravo !");
	}
	if (nbEssai > 6 && nbEssai < 11){
		printf("Correct !");
	}
	if (nbEssai > 11){
		printf("Decevant !");
	}
	getch();
    return 0;
}
