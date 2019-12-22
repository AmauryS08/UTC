#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 255

int **creationMatrice(int nbLignes, int nbColonnes);
int **generationMatriceAleatoire(int nbLignes, int nbColonnes, int valeurMin, int valeurMax);
void afficherMatrice(int **matrice, int nbLignes, int nbColonnes);
void affichageSelection();

int main(){
    int selection;
    int **matrice1 = NULL, **matrice2 = NULL;
    int nbLignes=0, nbColonnes = 0;
    int valeurMin = 0, valeurMax = 10;
    char ncolonne[MAX];
    char nligne[MAX];
    pid_t execfils;
    FILE *mat1File;
    FILE *mat2File;
    char *argAddition[6] = {"./somme", "matrice1.bin", "matrice2.bin",  NULL,  NULL, NULL};
    char *argProduit[6] = {"./produit", "matrice1.bin", "matrice2.bin", NULL, NULL, NULL};
    MENU:
    affichageSelection();
    scanf("%d",&selection);
    switch(selection){
        case 1:
            printf("Nombre de lignes : ");
            scanf("%d",&nbLignes);
            printf("Nombre de colonne : ");
            scanf("%d", &nbColonnes);
            sprintf(nligne, "%d", nbLignes);
            sprintf(ncolonne, "%d", nbColonnes);
            argAddition[3] = nligne; argAddition[4] = ncolonne;
            argProduit[3] = nligne; argProduit[4] = ncolonne;
            matrice1 = creationMatrice(nbLignes, nbColonnes);
            mat1File = fopen("matrice1.bin", "wb");
            for (int i = 0; i < nbLignes; ++i) {
                fwrite(matrice1[i], sizeof(int), nbColonnes, mat1File);
            }
            fclose(mat1File);
            free(matrice1);
            goto MENU;
        case 2:
            printf("Nombre de lignes : ");
            scanf("%d",&nbLignes);
            printf("Nombre de colonne : ");
            scanf("%d", &nbColonnes);
            sprintf(nligne, "%d", nbLignes);
            sprintf(ncolonne, "%d", nbColonnes);
            argAddition[3] = nligne; argAddition[4] = ncolonne;
            argProduit[3] = nligne; argProduit[4] = ncolonne;
            matrice2 = creationMatrice(nbLignes, nbColonnes);
            mat2File = fopen("matrice2.bin", "wb");
            for (int i = 0; i < nbLignes; ++i) {
                fwrite(matrice2[i], sizeof(int), nbColonnes, mat2File);
            }
            fclose(mat2File);
            free(matrice2);
            goto MENU;
        case 3:
            printf("Nombre de lignes : ");
            scanf("%d",&nbLignes);
            printf("Nombre de colonne : ");
            scanf("%d", &nbColonnes);
            printf("Valeur Min : ");
            scanf("%d",&valeurMin);
            printf("Valeur Max : ");
            scanf("%d", &valeurMax);
            sprintf(nligne, "%d", nbLignes);
            sprintf(ncolonne, "%d", nbColonnes);
            argAddition[3] = nligne; argAddition[4] = ncolonne;
            argProduit[3] = nligne; argProduit[4] = ncolonne;
            matrice1 = generationMatriceAleatoire(nbLignes, nbColonnes, valeurMin, valeurMax);
            mat1File = fopen("matrice1.bin", "wb");
            for (int i = 0; i < nbLignes; ++i) {
                fwrite(matrice1[i], sizeof(int), nbColonnes, mat1File);
            }
            fclose(mat1File);
            free(matrice1);
            matrice2 = generationMatriceAleatoire(nbLignes, nbColonnes, valeurMin, valeurMax);
            mat2File = fopen("matrice2.bin", "wb");
            for (int i = 0; i < nbLignes; ++i) {
                fwrite(matrice2[i], sizeof(int), nbColonnes, mat2File);
            }
            fclose(mat2File);
            free(matrice2);
            goto MENU;
        case 4:
            if (matrice1==NULL || matrice2==NULL){
                printf("Vous devez d'abord creer vos matrice. \n");
            }else {
                execfils = fork();
                if(execfils == 0) {
                    //Addition
                    printf("Addition des matrices : \n");
                    execv(argAddition[0], argAddition);
                } else{
                    wait(0);
                }
            }
            goto MENU;
        case 5:
            if (matrice1==NULL || matrice2==NULL){
                printf("Vous devez d'abord creer vos matrice. \n");
            }else {
                execfils = fork();
                if(execfils == 0) {
                    //Multiplication
                    printf("Multiplication des matrices : \n");
                    execv(argProduit[0], argProduit);
                }else{
                    wait(0);
                }
            }
            goto MENU;
        case 6:
            if (matrice1 == NULL || matrice2 == NULL){
                printf("Vous devez d'abord creer vos matrice. \n");
            }else {
                printf("Matrice 1: \n");
                afficherMatrice(matrice1, nbLignes, nbColonnes);
                printf("Matrice 2 : \n");
                afficherMatrice(matrice2, nbLignes, nbColonnes);
            }
            goto MENU;
        case 7:
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
    printf("3 - Creer des matrices Aléatoires \n");
    printf("4 - Additionner les 2 matrices \n");
    printf("5 - Multiplier les 2 matrices \n");
    printf("6 - Afficher les matrice \n");
    printf("7 - Quitter \n");
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
int **creationMatrice(int nbLignes, int nbColonnes){
    int **matrice;
    matrice = malloc(nbColonnes * sizeof(int*));
    for (int k = 0; k < nbColonnes; k++) {
        matrice[k] = malloc(nbLignes * sizeof(int));
    }
    for (int i = 0; i < nbLignes; i++) {
        for (int j = 0; j < nbColonnes; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }
    return matrice;
}
int **generationMatriceAleatoire(int nbLignes, int nbColonnes, int valeurMin, int valeurMax){
    int **matrice;
    matrice = malloc(nbColonnes * sizeof(int*));
    for (int k = 0; k < nbColonnes; k++) {
        matrice[k] = malloc(nbLignes * sizeof(int));
    }
    for (int i = 0; i < nbLignes; i++) {
        for (int j = 0; j < nbColonnes; j++) {
            matrice[i][j] = (rand() % (valeurMax - valeurMin + 1)) + valeurMin;
        }
    }
    return matrice;
}


