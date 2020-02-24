//////////////////////////////////////////////////////////////
/// Auteur : Lepiller Charly //////////// Date : 19/02/2020///
//////////////////////////////////////////////////////////////
#include "monShell.h"
void Prompt(){
  char* userName = getenv("USER");
  char* currentPath = malloc(sizeof(*currentPath)*1024);
  currentPath = getcwd(currentPath,1021);
  printf("%s: %s | $ ",userName,currentPath);
}

int main(int argc, char * argv[]){
  char ligne[MaxLigne];
  char * mot[MaxMot];
  char * dirs[MaxDirs];
  char** tabIntern = (char**) malloc(2*sizeof(char*));
	tabIntern[0] = "moncd";
	tabIntern[1] = "monexit";
	tabIntern[2] = "noCommand";
  /* Decouper UNE COPIE de PATH en repertoires */
  decoupe(strdup(getenv("PATH")), ":", dirs, MaxDirs);


  /* Lire et traiter chaque ligne de commande */
  for(Prompt(); fgets(ligne, sizeof ligne, stdin) != 0; Prompt()){
    decoupe(ligne, " \t\n", mot, MaxMot);
    if (mot[0] == 0){           // ligne vide 
		}
    if(internOrNot(mot,tabIntern,NBRCI) != -1){
      m_execIntern(mot,tabIntern);
    }
    else{
      m_exec(mot,dirs);
    }

  }
  printf("Sortie de monShell\n");
  return 0;
}
