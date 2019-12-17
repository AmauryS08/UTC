#include "manipulationMatrice.h"


int **additionMatrice(int **matrice1, int **matrice2, int nbLignes, int nbColonnes){
    int **somme;
    somme = malloc(nbLignes * sizeof(int*));
    for (int k = 0; k < nbLignes; k++) {
        somme[k] = malloc(nbColonnes * sizeof(int));
    }
    for (int i = 0; i < nbLignes; i++) {
        for (int j = 0; j < nbColonnes; j++) {
            somme[i][j] = matrice1[i][j] + matrice2[i][j];
        }
    }
    afficherMatrice(somme, nbLignes, nbColonnes);
    return somme;
}