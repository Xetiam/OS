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
  /* Initialisation des variables */
  int i = 0;
  char ligne[MaxLigne];
  char * dirs[MaxDirs];
  char* mot[MaxMot];
  char** tabIntern = (char**) malloc(2*sizeof(char*));
	tabIntern[0] = "moncd";
	tabIntern[1] = "monexit";
	tabIntern[2] = "noCommand";
  char* monPath = malloc(sizeof(*monPath)*1024);
  monPath = getcwd(monPath,1021);
  strcat(monPath,"/commandes_externes");
  /* Decouper UNE COPIE de PATH en repertoires */
  decoupe(strdup(getenv("PATH")), ":", dirs, MaxDirs);
  for(i = 0 ; dirs[i] != 0 ; i++){//rajout du répertoire contenant mes commandes externe
  }
  dirs[i] = monPath;
  dirs[i+1] = 0;


  /* Lire et traiter chaque ligne de commande */
  for(Prompt(); fgets(ligne, sizeof ligne, stdin) != 0; Prompt()){
    decoupe(ligne, " \t\n", mot, MaxMot);
    if (mot[0] == 0){           // ligne vide 
    }
    else if(mot[0] != 0){
      if(findAnd(ligne) == 0){//Aucun && présent
        if(internOrNot(mot,tabIntern,NBRCI) != -1){//Test indiquant l'appartenance de la commande utilisateur aux commandes internes.
          m_execIntern(mot,tabIntern);
        }
        else{
          m_exec(mot,dirs);
        }
      }
      else if(findAnd(ligne) == 1){// au moins un && est présent
        m_execMulti(ligne,tabIntern,dirs);
      }

    }
  }
  printf("Sortie de monShell\n");
  return 0;
}
