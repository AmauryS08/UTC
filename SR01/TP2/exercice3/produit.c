#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if (argc < 5) {   // Test de la commande (verification du bon nombre de paramètre
        printf("Usage : produit {matrice1.bin} {matrice2.bin} nbligne nbcolonne \n");
    }else {
        // Initialisation variables
        int **somme;
        int i=0,j;
        FILE *mat1File;
        FILE *mat2File;
        int nbLignes = atoi(argv[3]);
        int nbColonnes = atoi(argv[4]);
        int matrice1[nbLignes][nbColonnes];
        int matrice2[nbLignes][nbColonnes];
        pid_t PID[nbLignes];
        int pidPipe[nbLignes][2];
        for (int numpid = 0; numpid < nbLignes; numpid++) {
            pipe(pidPipe[numpid]);
        }

        //ouverture des fichier binaire
        mat1File = fopen(argv[1], "rb");
        mat2File = fopen(argv[2], "rb");

        // On test si les fichiers ont bien été ouvert
        if (mat1File == NULL){
            printf("Impossible de lire le fichier matrice1\n");
            exit(1);
        }
        if (mat2File == NULL){
            printf("Impossible de lire le fichier matrice2\n");
            exit(1);
        }

        // On attribu la mémoire suffisante à notre matrice résultat
        somme = malloc(nbLignes * sizeof(int *));
        for (int k = 0; k < nbLignes; k++) {
            somme[k] = malloc(nbColonnes * sizeof(int));
        }

        // Lecture des fichiers binaires
        fread(matrice1, nbLignes*sizeof(int), nbColonnes, mat1File);
        fread(matrice2, nbLignes*sizeof(int), nbColonnes, mat2File);
        // On les referme directement pour ne pas les laisser ouvert
        fclose(mat1File);
        fclose(mat2File);

        // creation des processus fils pour les N lignes
        for (j = 0; j <nbLignes; j++) {
            PID[i] = fork();
            if (PID[i] > 0) {
                i++;
            } else if (PID[i] == 0) {
                break;
            } else {
                printf("Erreur de creation de processus \n");
            }
        }
        if (i == nbLignes) {
            i = nbLignes-1;
        }

        // Calcul des lignes pour les nbLignes fils
        if (PID[i] == 0) {
            for (int l = 0; l < nbColonnes; l++) {
                for (int k = 0; k < nbLignes; k++) {
                    somme[i][l] += matrice1[i][k] * matrice2[k][l];
                }
            }

            close(pidPipe[i][0]);
            write(pidPipe[i][1], somme[i], nbLignes * sizeof(int));
        } else { // Attente du père pour le résultat et affichage de la matrice finale
            wait(0);
            for (int k = 0; k < nbLignes; k++) {
                close(pidPipe[k][1]);
                read(pidPipe[k][0], somme[k], nbLignes * sizeof(int));
                for (int l = 0; l < nbColonnes; l++) {
                    printf("| %d ", somme[k][l]);
                }
                printf("|\n");
            }
        }

        // on n'oublie pas de libérer la mémoire réservé
        free(somme);
    }
}