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
  NBRCI = 2,                    // nombre de commande interne implémentées
  MaxLigne = 1024,              // longueur max d'une ligne de commandes
  MaxMot = MaxLigne / 2,        // nbre max de mot dans la ligne
  MaxDirs = 100,		            // nbre max de repertoire dans PATH
  MaxPathLength = 512,		      // longueur max d'un nom de fichier
  MaxComDif = 10,               // Nombre de commande utilisateur entré en une seule fois
};



//Fonction d'analyse de ligne (fonctionsOs.c)
/* Fonction qui découpe chaque mot d'une chaine et les stock dans un tableau */
int decoupe(char* ligne, char* separ, char* mot[], int maxmot);

/* Fonction renvoyant True si la commande est interne */
int internOrNot(char** mot, char** tabIntern, int nbrCI);

/* Fonction détectant la présence d'un && */
int findAnd(char* ligne);


//Commande interne au minishell (com_intern.c)
/* Commande interne pour changer de répertoire courant */
int moncd(int argc, char* argv[]);

/* Commande interne pour interrompre monShell */
int monexit(char** tabIntern);


//Fonction d'exécution (exec.c)
/* Fonction d'exécution classique lors d'une commande se trouvant dans PATH */
int m_exec(char** command, char** dirs);

/* Fonction d'exécution d'une commande interne */
int m_execIntern(char** command, char** dirs);

/* Fonction pour exécuter plusieurs commande avec des && */
int m_execMulti(char* ligne, char**tabIntern, char** dirs);

