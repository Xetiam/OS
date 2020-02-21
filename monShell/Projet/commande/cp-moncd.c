//////////////////////////////////////////////////////////////
/// Auteur : Lepiller Charly //////////// Date : 19/02/2020///
//////////////////////////////////////////////////////////////
#include "cp-moncd.h"
/* Fonction cd à la main */
int moncd(int argc, char* argv[]){
	char* dir;
	int t;
	printf("La commande moncd s'est bien lancé \n");
	if(argc<2){
		dir = getenv("HOME");
		if (dir == 0){
			dir ="/mnt";
		}
	}
	else if (argc > 2){
		fprintf(stderr, "usage : %s [dir]\n",argv[0]);
		return 1;
	}
	else{
		dir = argv[1];
	}
	printf("%s\n", dir);
	t = chdir(dir);
	if(t<0){
		perror(dir);
		return 1;
	}
	return 0;
}