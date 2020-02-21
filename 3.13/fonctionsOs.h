//////////////////////////////////////////////////////////////
/// Auteur : Lepiller Charly //////////// Date : 19/02/2020///
//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#define TAILLE_MAX 100



/* Fonction qui créer un processus enfant puis lance un execv */
char* prepaPath(char* tab[]);

/* Fonction qui découpe chaque mot d'une chaine et les stock dans un tableau */
int decoupe(char* ligne, char* separ, char* mot[], int maxmot);

/* Fonction qui compte le nombre d'occurence de deux_mot dans prem_mot */
int my_strstrs(const char* prem_mot, const char* deux_mot);

/* Fonction qui créer un processus enfant puis lance un execv */
int spawn(char* path, char*tab[]);