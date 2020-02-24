//////////////////////////////////////////////////////////////
/// Auteur : Lepiller Charly //////////// Date : 24/02/2020///
//////////////////////////////////////////////////////////////
#include "monShell.h"

/* Fonction d'exécution classique lors d'une commande se trouvant dans PATH */
int m_exec(char** command,char** dirs){
	int pid, x, etat,i;
	char pathname[MaxPathLength];
	pid = fork();
	if(pid<0){
		perror("fork m_exec");
		return -1;
	}
	if(pid != 0){//parent
		for(;;){
			x = wait(&etat);
			if( x==pid){
				return etat;
			}
		}
	}
	else{//enfant
		// enfant : exec du programme
		for(i = 0; dirs[i] != 0; i++){
			snprintf(pathname, sizeof pathname, "%s/%s", dirs[i], command[0]);
			execv(pathname, command);
		}
			// aucun exec n'a fonctionne
		fprintf(stderr, "%s: not found\n", command[0]);
		exit(1);
	}
}


/* Fonction d'exécution d'une commande interne */
int m_execIntern(char** command, char** tabIntern){
	int cur = internOrNot(command,tabIntern,NBRCI);
	if(cur == 0){//moncd
		moncd(2,command);
	}
	else if(cur == 1){//monexit
		monexit(tabIntern);
	}
	return 0;
}
