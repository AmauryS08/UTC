#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXFILE 1030
#define MAX 255


/*------------------
     Question 1
-------------------- */
typedef struct Restaurant{
    char nom_restaurant[MAX];
    char adresse_restaurant[MAX];
    char position_restaurant[MAX];
    char specialite[MAX];
}Restaurant;


/*------------------
     Question 2
-------------------- */
int lire_restaurant(char* chemin,Restaurant restaurants){
    FILE * rest;
    char buffer[MAXFILE] = "";
    int nombre_restaurant = 0;
    rest = fopen(chemin, "r");
    if(rest == NULL){
        printf("Impossible d'ouvrir le fichier !");
        exit(1);
    }else{
        printf("Liste des restaurants:\n");
        while(fgets(buffer, MAXFILE, rest)!= NULL){
            nombre_restaurant+=1;
            printf("%s",buffer);
        };
    };
    fclose(rest);
    return nombre_restaurant;
}


/*------------------
     Question 3
-------------------- */
void inserer_restaurant(Restaurant restaurant){
    FILE * rest;
    rest = fopen("restau.txt", "a");
    if(rest == NULL){
        printf("erreur !");
    }else{
        fputs(restaurant.nom_restaurant, rest);
        fputs("; ", rest);
        fputs(restaurant.adresse_restaurant, rest);
        fputs("; ( ", rest);
        fputs(restaurant.position_restaurant, rest);
        fputs(" ); ", rest);
        fputs(restaurant.specialite, rest);
        fputs(";\n", rest);
    };
    fclose(rest);
}


/*------------------
     Question 4
-------------------- */
void cherche_restaurant(double x, double y, double rayon_recherche,Restaurant restau[MAX]){
    FILE * rest;
    char buffer[MAXFILE]  = "";
    char * mot;
    double xpos, ypos;
    double dis=0;

    int nombre_restaurant = 0;
    char nom_restau[MAX] = ""; char adresse_restau[MAX] = ""; char position_restau[MAX] = ""; char specialite_restau[MAX] = "";
    int k =0;int j=0;
    rest = fopen("restau.txt", "r");
    if(rest == NULL){
        printf("Impossible d'ouvrir le fichier !");
        exit(1);
    }else{
        while(fgets(buffer, MAXFILE, rest) != NULL){
            mot = strstr(buffer, "(");
            if(mot == NULL){
                printf("erreur pas de coordonnee? \n");
            }else{
                sscanf(mot,"%*s %lf %*s%*s %lf",&xpos,&ypos);
                dis=0;
                dis=(xpos-x)*(xpos-x)+(ypos-y)*(ypos-y);
                dis=sqrt(dis);
                if(dis<rayon_recherche){
                        do
                        {
                            nom_restau[j] = buffer[k];
                            k++;
                            j++;
                        } while (buffer[k] != ';');
                        sprintf(restau[nombre_restaurant].nom_restaurant, "%s", nom_restau);
                        j=0;k++;
                        do
                        {
                            adresse_restau[j] = buffer[k];
                            k++;
                            j++;
                        } while (buffer[k] != ';');
                        sprintf(restau[nombre_restaurant].adresse_restaurant, "%s", adresse_restau);
                        j=0;k++;
                        do
                        {
                            position_restau[j] = buffer[k];
                            k++;
                            j++;
                        } while (buffer[k] != ';');
                        j=0;k++;
                        sprintf(restau[nombre_restaurant].position_restaurant, "%s", position_restau);
                        do
                        {
                            specialite_restau[j] = buffer[k];
                            k++;
                            j++;
                        } while (buffer[k] != ';');
                        sprintf(restau[nombre_restaurant].specialite, "%s", specialite_restau);
                        k=0; j=0;
                        for(int i=0;i<MAX;i++){
                            nom_restau[i]='\0';
                            adresse_restau[i]='\0';
                            position_restau[i]='\0';
                            specialite_restau[i]='\0';
                        };
                        nombre_restaurant+=1;

                };
            };
        };
    };
    printf("Liste des restaurants disponible :\n");
    for (int i = 0; i < nombre_restaurant; i++)
    {
        printf("------------------\n");
        printf("Nom du restaurant: %s \n",restau[i].nom_restaurant);
        printf("Adresse du restaurant: %s \n",restau[i].adresse_restaurant);
        printf("Position du restaurant: %s \n",restau[i].position_restaurant);
        printf("specialite du restaurant: %s \n",restau[i].specialite);
    };
    fclose(rest);
}


/*------------------
     Question 5
-------------------- */
void cherche_par_specialite(double x, double y, char *specialite[], Restaurant results[]){
    FILE * rest;
    char buffer[MAXFILE]  = "";
    char * mot=NULL;
    char * pos=NULL;
    double xpos, ypos;
    double dis;
    double min;
    int nmin;
    double inter;
    Restaurant interr;
    double distance[MAX];
    int nombre_restaurant = 0;
    char nom_restau[MAX] = ""; char adresse_restau[MAX] = ""; char position_restau[MAX] = ""; char specialite_restau[MAX] = "";
    int k =0;int j=0;int p=0;
    rest = fopen("restau.txt", "r");
    if(rest == NULL){
        printf("Impossible d'ouvrir le fichier !");
        exit(1);
    }else{
        while(fgets(buffer, MAXFILE, rest) != NULL){
            mot=NULL;
            p=0;
            while(specialite[p]!=NULL&&mot == NULL){
                mot = strstr(buffer, specialite[p]);
                p++;
            }
            if(mot != NULL){
                        pos = strstr(buffer, "(");
                        if(pos == NULL){
                            printf("erreur pas de coordonnee? \n");
                        }else{
                                sscanf(pos,"%*s %lf %*s%*s %lf",&xpos,&ypos);
                                dis=0;
                                dis=(xpos-x)*(xpos-x)+(ypos-y)*(ypos-y);
                                dis=sqrt(dis);
                                distance[nombre_restaurant]=dis;
                            }
                        do
                        {
                            nom_restau[j] = buffer[k];
                            k++;
                            j++;
                        } while (buffer[k] != ';');
                        sprintf(results[nombre_restaurant].nom_restaurant, "%s", nom_restau);
                        j=0;k++;
                        do
                        {
                            adresse_restau[j] = buffer[k];
                            k++;
                            j++;
                        } while (buffer[k] != ';');
                        sprintf(results[nombre_restaurant].adresse_restaurant, "%s", adresse_restau);
                        j=0;k++;
                        do
                        {
                            position_restau[j] = buffer[k];
                            k++;
                            j++;
                        } while (buffer[k] != ';');
                        j=0;k++;
                        sprintf(results[nombre_restaurant].position_restaurant, "%s", position_restau);
                        do
                        {
                            specialite_restau[j] = buffer[k];
                            k++;
                            j++;
                        } while (buffer[k] != ';');
                        sprintf(results[nombre_restaurant].specialite, "%s", specialite_restau);
                        k=0; j=0;
                        for(int i=0;i<MAX;i++){
                            nom_restau[i]='\0';
                            adresse_restau[i]='\0';
                            position_restau[i]='\0';
                            specialite_restau[i]='\0';
                        };
                        nombre_restaurant+=1;
                    };
                };
            };
    for(int w=0;w<nombre_restaurant;w++){
        min=distance[w];
        for(int u=w+1;u<nombre_restaurant;u++){
            if(min>distance[u]){
                min=distance[u];
                nmin=u;
            }
        }
        inter=distance[w];
        distance[w]=distance[nmin];
        distance[nmin]=inter;
        interr=results[w];
        results[w]=results[nmin];
        results[nmin]=interr;
    }


    printf("Liste des restaurant disponible :\n");
    for (int i = 0; i < nombre_restaurant; i++)
    {
        printf("------------------\n");
        printf("Nom du restaurant: %s \n",results[i].nom_restaurant);
        printf("Adresse du restaurant: %s \n",results[i].adresse_restaurant);
        printf("Position du restaurant: %s \n",results[i].position_restaurant);
        printf("specialite du restaurant: %s \n",results[i].specialite);
        printf("distance: %lf \n",distance[i]);
    };
    fclose(rest);
}


/*------------------
     Main + question 6
-------------------- */
int main(){
    int selec=0;
    double xpos=0; double ypos=0; int rayon=0;
    Restaurant restau;
    Restaurant restau_table[MAX];
    char nom_restau[MAX] = ""; char adresse_restau[MAX] = ""; char position_restau[MAX] = ""; char specialite_restau[MAX] = "";
    int k=0;int j=0;

    char *spec[255];
    printf("Selectionnez votre action:\n");
    printf("1 - afficher les restaurants\n");
    printf("2 - ajouter un restaurant\n");
    printf("3 - rechercher un/des restaurant(s)\n");
    printf("4 - rechercher un/des restaurant(s) par specialités\n");
    scanf("%d",&selec);
    char buffer[MAXFILE] = "";
    switch (selec)
    {
         case 1:
            printf("Nombre de restaurant: %d \n",lire_restaurant("restau.txt",restau));
            break;
        case 2:
            printf("Syntaxe: NOM; ADRESSE; (x= XPOS, y= YPOS ); {SPECIALITE1, SPECIALITE2} \n");
            fgets(buffer,MAXFILE,stdin);
            do{
                nom_restau[j] = buffer[k];
                k++;
                j++;
            } while (buffer[k] != ';');
            sprintf(restau.nom_restaurant, "%s", nom_restau);
            j=0;k++;
            do{
                adresse_restau[j] = buffer[k];
                k++;
                j++;
            } while (buffer[k] != ';');
            sprintf(restau.adresse_restaurant, "%s", adresse_restau);
            j=0;k++;
            do{
                position_restau[j] = buffer[k];
                k++;
                j++;
            } while (buffer[k] != ';');
            j=0;k++;
            sprintf(restau.position_restaurant, "%s", position_restau);
            do{
                specialite_restau[j] = buffer[k];
                k++;
                j++;
            } while (buffer[k] != ';');
            sprintf(restau.specialite, "%s", specialite_restau);
            k=0; j=0;
            for(int i=0;i<MAX;i++){
                nom_restau[i]='\0';
                adresse_restau[i]='\0';
                position_restau[i]='\0';
                specialite_restau[i]='\0';
            };
            inserer_restaurant(restau);
            break;
        case 3:
            printf("Indiquez votre position x:");
            scanf("%f",&xpos);
            printf("Indiquez votre position y:");
            scanf("%f",&ypos);
            printf("Indiquez un rayon de recherche:");
            scanf("%d",&rayon);
            cherche_restaurant(xpos,ypos,rayon,restau_table);
            break;
        case 4:
            printf("Indiquez votre position x:");
            scanf("%lf",&xpos);
            printf("Indiquez votre position y:");
            scanf("%lf",&ypos);
            printf("Indiquer la specialité:");
            scanf("%s",spec);
            cherche_par_specialite(xpos,ypos,spec,restau_table);
            break;
        default:
            printf("Erreur de selection");
            break;
    } 
}
