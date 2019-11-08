#include <stdio.h>
#include <stdlib.h>

/*------------------
     Question 1 
-------------------- */
int * lecturenote(int N){
    int * NOTES;
    NOTES = malloc(N * sizeof(*NOTES));
    int val;
    for(int i=0;i<N;i++){
        printf("Introduire la note du %ieme eleve:",i+1);
        scanf("%d",&val);
        NOTES[i]=val;
    };
    return NOTES;
};
/*------------------
     Question 2 
-------------------- */
int notemax(int N, int *NOTES){
    int val=0;
    for(int i=0;i<N;i++){
        if(NOTES[i]>val) val=NOTES[i];
    };
    printf("Valeur maximal: %d \n",val);
    return 0;

};
int notemin(int N, int *NOTES){
    int val=NOTES[0];
    for(int i=0;i<N;i++){
        if(NOTES[i]<val) val=NOTES[i];
    };
    printf("Valeur minimal: %d \n",val);
    return 0;

};
int notemoy(int N, int *NOTES){
    float sum;float moy;
    for(int i=0;i<N;i++){
        sum+=NOTES[i];
    }
    moy=sum/N;
    printf("Moyenne des notes: %f \n",moy);
    return 0;
};
/*------------------
     Question 3 
-------------------- */
int * pointetu(int N, int *nte, int NOTESC[7]){
    for(int i=0;i<N;i++){
        if(nte[i]==60){
            NOTESC[6]+=1;
        }else if (nte[i]>=50 && nte[i]<60){
            NOTESC[5]+=1;
        }else if (nte[i]>=40 && nte[i]<50){
            NOTESC[4]+=1;
        }else if (nte[i]>=30 && nte[i]<40){
            NOTESC[3]+=1;
        }else if (nte[i]>=20 && nte[i]<30){
            NOTESC[2]+=1;
        }else if (nte[i]>=10 && nte[i]<20){
            NOTESC[1]+=1;
        }else {
            NOTESC[0]+=1;
        }
    }
}
/*------------------
     Question 4 
-------------------- */
int graphnuage(int NOTES[7]){
    int MAXN = 0;
    for(int i=0;i<7;i++){
        if(NOTES[i]>MAXN) MAXN=NOTES[i];
    };
    printf("MAXN = %d\n",MAXN);
    for(int j=MAXN;j>=0;j--){
        printf("%d > ",j);
        for(int k=0;k<7;k++){
            if(NOTES[k]==j){
                printf("   o  ");
            }else{
                printf("      ");
            }
        }
        printf("\n");
    };
    printf("    +-----+-----+-----+-----+-----+-----+-----+\n");
    printf("      0-9  10-19 20-29 30-39 40-49 50-59   60\n");
    return 0;
}
/*------------------
     Question 5
-------------------- */
int graphbaton(int *NOTES){
    int MAXN = 0;
    for(int i=0;i<7;i++){
        if(NOTES[i]>MAXN) MAXN=NOTES[i];
    };
    printf("MAXN = %d\n",MAXN);
    for(int j=MAXN;j>=0;j--){
        printf("%d > ",j);
        for(int k=0;k<7;k++){
            if(NOTES[k]>=j){
                printf(" #### ");
            }else{
                printf("      ");
            }
        }
        printf("\n");
    };
    printf("    +-----+-----+-----+-----+-----+-----+-----+\n");
    printf("      0-9  10-19 20-29 30-39 40-49 50-59   60\n");
    return 0;
}

/*------------------
       Main 
-------------------- */
int main(){
    int nb=0;
    int *note; int *noteclasse;
    printf("Nombre d'eleve:");
    scanf("%d",&nb);
    note = lecturenote(nb);
    notemax(nb, note);
    notemin(nb, note);
    notemoy(nb, note);
    int NOTESC[7] = {0,0,0,0,0,0,0};
    pointetu(nb, note,NOTESC);
    graphnuage(NOTESC);
    graphbaton(NOTESC);
    free(note);
    return 0;
};
