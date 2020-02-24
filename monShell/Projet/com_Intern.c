//////////////////////////////////////////////////////////////
/// Auteur : Lepiller Charly //////////// Date : 19/02/2020///
//////////////////////////////////////////////////////////////
#include "monShell.h"

/* Commande interne pour changer de répertoire courant */
int moncd(int argc, char* argv[]){
	char* dir;
	int t;
	if(argc<2){
		dir = getenv("HOME");
		if(dir == 0){
			dir = "/tmp";
		}
	}
	else if (argc > 2){
		fprintf(stderr, "usage : %s [dir]\n",argv[0]);
		return 1;
	}
	else{
		dir = argv[1];
	}
	t = chdir(dir);
	if(t<0){
		perror(dir);
		return 1;
	}
	return 0;
}

/* Commande interne pour interrompre monShell */
int monexit(char** tabIntern){
	printf("Sortie de monShell\n");
	free(tabIntern);
	exit(EXIT_SUCCESS);
}