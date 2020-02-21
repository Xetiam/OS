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
#include "commande/cp-moncd.h"
#define PROMPT "?? "

/* Fonction qui découpe chaque mot d'une chaine et les stock dans un tableau */
int decoupe(char* ligne, char* separ, char* mot[], int maxmot);
