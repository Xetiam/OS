#include "fonctionsOS.h"


enum {
  MaxLigne = 1024,              // longueur max d'une ligne de commandes
  MaxMot = MaxLigne / 2,        // nbre max de mot dans la ligne
  MaxDirs = 100,		// nbre max de repertoire dans PATH
  MaxPathLength = 512,		// longueur max d'un nom de fichier
};



int main(int argc, char * argv[]){
  char ligne[MaxLigne];
  char pathname[MaxPathLength];
  char * mot[MaxMot];
  char * dirs[MaxDirs];
  int i, tmp;
  /* Decouper UNE COPIE de PATH en repertoires */
  decoupe(strdup(getenv("PATH")), ":", dirs, MaxDirs);
	for(int j = 0 ; j<MaxDirs ; j++){//rajout du répertoire de mes commandes personnel
		if(dirs[j] == 0){
			dirs[j] = "/mnt/d/Grenier/Programmation/Exercices/OS/Projet/monShell/commande";
			dirs[j+1] = 0;
			break;
		}
	}


  /* Lire et traiter chaque ligne de commande */
  for(printf("%s: %s | %s",getenv("USER"), getenv("PWD"), PROMPT); fgets(ligne, sizeof ligne, stdin) != 0; printf("%s : %s | %s",getenv("USER"), getenv("PWD"), PROMPT)){
    decoupe(ligne, " \t\n", mot, MaxMot);
    /* if (mot[0] == "env"){
      mondcd(2,mot+1);
    } *///Problème pointeur sur fonction
    if (mot[0] == 0){           // ligne vide 
		}
    tmp = fork();               // lancer le processus enfant
    if (tmp < 0){
      perror("fork");
    }

    else if (tmp != 0){             // parent : attendre la fin de l'enfant
      while(wait(0) != tmp)
        ;
    }

    else{
		// enfant : exec du programme
    for(i = 0; dirs[i] != 0; i++){
      snprintf(pathname, sizeof pathname, "%s/%s", dirs[i], mot[0]);
      execv(pathname, mot);
    }
		// aucun exec n'a fonctionne
    fprintf(stderr, "%s: not found\n", mot[0]);
    exit(1);
    }
  }

  printf("Sortie de monShell\n");
  return 0;

}