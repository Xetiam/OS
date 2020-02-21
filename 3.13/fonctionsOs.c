//////////////////////////////////////////////////////////////
/// Auteur : Lepiller Charly //////////// Date : 19/02/2020///
//////////////////////////////////////////////////////////////
#include "fonctionsOs.h"
/* Fonction qui prépare le path d'une commande pour un execv */
char* prepaPath(char* tab[]){
    /* Initialisation des variables */
    //Initialisation de path
    char *commande = tab[0];
    char* pathTemp = "/bin/";
    size_t fullSize = strlen(pathTemp)+strlen(commande);
    char* path = (char*) malloc(fullSize);
    strcpy(path,pathTemp);
    strcat(path,commande);
    return path;
}

/* Fonction qui créer un processus enfant puis lance un execv */
int spawn(char* path, char*tab[]){    
    /* Processus enfant */
    int t;
    t=fork();
    if(t<0){
        free(path);
        /* perror("Erreur lors de la création d'un nouveau processus"); */
        return -1;
    }
    if(t == 0){
        execv(path, tab);
        free(path);
        exit(1);
    }
    return t;
}

/* Fonction qui découpe chaque mot d'une chaine et les stock dans un tableau */
int decoupe(char* ligne, char* separ, char* mot[], int maxmot){
    mot[0] = strtok(ligne, separ);
    for(int i = 1 ; mot[i-1] != 0 ; i++){
        if(i==maxmot){
            fprintf(stderr, "Erreur dans la fonction doucpe : trop de mot\n");
            mot[i-1] = 0;
            break;
        }
        mot[i] = strtok(NULL,separ);
    }
    return i;
}


/* Fonction qui compte le nombre d'occurence de deux_mot dans prem_mot */
int my_strstrs(const char* prem_mot, const char* deux_mot){
    /* Définition de variables */
    int tailChainPrem = strlen(prem_mot);
    int tailChainDeux = strlen(deux_mot); 
    int cur =0;
    int compteur =0;

    /* Double boucle de recherche */
    for(int i = 0 ; i<tailChainDeux ; i++){
        for(int j = 0 ; j < tailChainPrem ; j++){
            if (prem_mot[j] == deux_mot[i+j]){
                cur++;
                if(cur == tailChainPrem){//Condition d'occurence trouvé
                    compteur++;
                }
            }
            else{
                cur = 0;
            }
        }
    }
        return compteur;
    }