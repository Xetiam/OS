//////////////////////////////////////////////////////////////
/// Auteur : Lepiller Charly //////////// Date : 19/02/2020///
//////////////////////////////////////////////////////////////
#include "monShell.h"


int main(int argc, char * argv[]){
  char ligne[MaxLigne];
  char pathname[MaxPathLength];
  char * mot[MaxMot];
  char * dirs[MaxDirs];
  int i, tmp;
  /* Decouper UNE COPIE de PATH en repertoires */
  decoupe(strdup(getenv("PATH")), ":", dirs, MaxDirs);


  /* Lire et traiter chaque ligne de commande */
  for(printf("%s: %s | %s",getenv("USER"), getenv("PWD"), PROMPT); fgets(ligne, sizeof ligne, stdin) != 0; printf("%s : %s | %s",getenv("USER"), getenv("PWD"), PROMPT)){
    decoupe(ligne, " \t\n", mot, MaxMot);
    if (mot[0] == 0){           // ligne vide 
		}
    if(mot[0] == "moncd"){
      moncd(2,mot);
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