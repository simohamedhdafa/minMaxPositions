#include <stdio.h>
#include <stdlib.h>

// fonction de saisie d un tablau
void saisirTableau(int *, int, char *);
// fonction d affichage d un tableau
void afficherTableau(int *, int, char *);
// trouver les toutes les pos de min et max dans un tableeau
void minMaxPositions(int *, int *, int *, int, int *, int *);

void main(){
    int n, * Tab, * t_min, * t_max, nbr_min, nbr_max;

    // saisie de n
    do{
        printf("entrer la taille du tableau : ");
        scanf("%d", &n);
    }while(n<=1);

    // allouer n * sizeof(int)
    Tab = (int*) malloc(n * sizeof(int)); 
    t_min = (int*) malloc(n*sizeof(int));
    t_max = (int*) malloc(n*sizeof(int));

    if(!(Tab==NULL || t_min==NULL || t_max==NULL)){
        // saisie du tableau
        saisirTableau(Tab, n, "Tab");

        // affichage
        afficherTableau(Tab, n, "Tab");

        // calculer les pos ds mins et ds max
        minMaxPositions(Tab, t_min, t_max, n, &nbr_min, &nbr_max);

        // les afficher (t_min et t_max)
        afficherTableau(t_min, nbr_min, "t_min");
        afficherTableau(t_max, nbr_max, "t_max");

        // liberer les ressources
        free(Tab);
        // aussi pour t_min t t_max
    }

    printf("fin du programme!\n");
}

void afficherTableau(int * t, int n, char * nom){
    int * p;
    printf("affichage du tableau %s\n", nom);
    for(p=t; p<t+n; p++)
        printf("\t%d", *p);
    printf("\n");
}

void saisirTableau(int * t, int n, char * nom){
    int * p=t;
    while(p<t+n){
        printf("%s[%d] : ", nom, p-t);
        scanf("%d", p);
        // mettr a jour p
        p++;
    }

    
}

void minMaxPositions(int * T, int * t_min, int * t_max, int n, int * compt_min, int * compt_max){
    // preparatio declar de vars
    int min, max; 
    int * p;
    max = *T;
    min = *T;
    *compt_min = 1;
    *compt_max=1;

    *t_min = *t_max = 0;
    for(p=T+1; p<T+n; p++){
        
        if(*p==min){ // calcul relatif au min
            *(t_min+(*compt_min)) = p-T;
            (*compt_min)++;
        }else if(*p<min){
            min = *p;
            *compt_min=0;
            *t_min = p-T;
        } // ne pas se brancher ici : vecteur d'une seule valeur
        if(*p==max){ // calcul rlatif au max
            *(t_max+(*compt_max)) = p-T;
            (*compt_max)++;
        }else if(*p>max){
            max = *p;
            *compt_max=0;
            *t_max = p-T;
        }
    }

}
