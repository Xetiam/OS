//////////////////////////////////////////////////////////////
/// Auteur : Lepiller Charly //////////// Date : 19/02/2020///
//////////////////////////////////////////////////////////////
#include "monShell.h"

/* Commande interne pour changer de répertoire courant */
int moncd(int argc, char* argv[]){
	char* dir = malloc(sizeof(*dir)*1024);
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
	else if(argc == 2){
		if(argv[1][0] == '.' && argv[1][1] != '.'){
			char* currentPath = malloc(sizeof(*currentPath)*1024);
  		currentPath = getcwd(currentPath,1021);
			dir = strcat(dir,currentPath);
			dir = strcat(dir,argv[1]+1);
			free(currentPath);
		}
		else if(argv[1][0] == '.' && argv[1][1] == '.'){
			char* currentPath = malloc(sizeof(*currentPath)*1024);
			char** tabPath = malloc(sizeof(**tabPath)*1024);
  		currentPath = getcwd(currentPath,1021);
			decoupe(currentPath,"/",tabPath,MaxMot);
			
			for(int i = 0 ; tabPath[i+1] != NULL; i++){
				dir=strcat(dir,"/");
				dir=strcat(dir,tabPath[i]);
			}
		}
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