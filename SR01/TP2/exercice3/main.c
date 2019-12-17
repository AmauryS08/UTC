#include <stdio.h>
#include <stdlib.h>
#include "manipulationMatrice.h"

int main(){
    int selection;
    int **matrice1 = NULL, **matrice2 = NULL;
    int nbLignes=0, nbColonnes = 2;
    FILE *mat1File;
    FILE *mat2File;
    MENU:
    affichageSelection();
    scanf("%d",&selection);
    switch(selection){
        case 1:
            printf("Nombre de lignes : ");
            scanf("%d",&nbLignes);
            matrice1 = creationMatrice(nbLignes);
            mat1File = fopen("matrice1.bin", "wb");
            fwrite(matrice1, sizeof(matrice1), 1, mat1File);
            fclose(mat1File);
            goto MENU;
        case 2:
            printf("Nombre de lignes : ");
            scanf("%d",&nbLignes);
            matrice2 = creationMatrice(nbLignes);
            mat2File = fopen("matrice2.bin", "wb");
            fwrite(matrice2, sizeof(matrice2), 1, mat2File);
            fclose(mat2File);
            goto MENU;
        case 3:
            if (matrice1==NULL || matrice2==NULL){
                printf("Vous devez d'abord creer vos matrice. \n");
            }else {
                additionMatrice(matrice1, matrice2, nbLignes, nbColonnes);
            }
            goto MENU;
        case 5:
            if (matrice1 == NULL || matrice2 == NULL){
                printf("Vous devez d'abord creer vos matrice. \n");
            }else {
                afficherMatrice(matrice1, nbLignes, nbColonnes);
                afficherMatrice(matrice2, nbLignes, nbColonnes);
            }
            goto MENU;
        case 6:
            break;
        default :
            printf("Erreur de selection. \n");
            break;
    }
}
void affichageSelection(){
    printf("Outils de calcul de matrice : \n");
    printf("1 - Creer une matrice 1 \n");
    printf("2 - Creer une matrice 2 \n");
    printf("3 - Additionner les 2 matrices \n");
    printf("4 - Multiplier les 2 matrices \n");
    printf("5 - Afficher les matrice \n");
    printf("6 - Quitter \n");
    printf("Selection : ");
};
void afficherMatrice(int **matrice, int nbLignes, int nbColonnes){
    for (int i = 0; i < nbLignes; i++) {
        for (int j = 0; j < nbColonnes; j++) {
            printf(" %d |", matrice[i][j]);
        }
        printf("\n");
    }
}
int **creationMatrice(int nbLignes){
    int nbColonne;
    int **matrice;
    printf("Nombre de colonne : ");
    scanf("%d", &nbColonne);
    matrice = malloc(nbColonne * sizeof(int*));
    for (int k = 0; k < nbColonne; k++) {
        matrice[k] = malloc(nbLignes * sizeof(int));
    }
    for (int i = 0; i < nbLignes; i++) {
        for (int j = 0; j < nbColonne; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }
    return matrice;
}


