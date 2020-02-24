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



enum {
  NBRCI = 2,
  MaxLigne = 1024,              // longueur max d'une ligne de commandes
  MaxMot = MaxLigne / 2,        // nbre max de mot dans la ligne
  MaxDirs = 100,		// nbre max de repertoire dans PATH
  MaxPathLength = 512,		// longueur max d'un nom de fichier*
};


/* Fonction qui découpe chaque mot d'une chaine et les stock dans un tableau */
int decoupe(char* ligne, char* separ, char* mot[], int maxmot);

//Commande interne au minishell
/* Commande interne pour changer de répertoire courant */
int moncd(int argc, char* argv[]);

/* Commande interne pour interrompre monShell */
int monexit(char** tabIntern);


//Fonction d'exécution
/* Fonction d'exécution classique lors d'une commande se trouvant dans PATH */
int m_exec(char** command, char** dirs);

/* Fonction d'exécution d'une commande interne */
int m_execIntern(char** command, char** dirs);


//Fonction d'analyse de ligne
/* Fonction renvoyant True si la commande est interne */
int internOrNot(char** mot, char** tabIntern, int nbrCI);