//////////////////////////////////////////////////////////////
/// Auteur : Lepiller Charly //////////// Date : 19/02/2020///
//////////////////////////////////////////////////////////////
#include "monShell.h"

/* Fonction qui découpe chaque mot d'une chaine et les stock dans un tableau */
int decoupe(char* ligne, char* separ, char* mot[], int maxmot){
	int i;
	mot[0] = strtok(ligne, separ);
	for(i = 1 ; mot[i-1] != 0 ; i++){
		if(i==maxmot){
			fprintf(stderr, "Erreur dans la fonction decoupe : trop de mot\n");
			mot[i-1] = 0;
			break;
		}
		mot[i] = strtok(NULL,separ);
	}
	return i;
}


/* Fonction renvoyant True si la commande est interne */
int internOrNot(char** mot, char** tabIntern, int nbrCI){;
	int i = 0;
	for(i = 0 ; i<=nbrCI ; i++){
		if(strcmp(mot[0],tabIntern[i])==0){
			return i;
		}
	}
	return -1;
}

/* Fonction détectant la présence d'un && */
int findAnd(char* ligne){

  for(int i=0; ligne[i+1] != 0; i++){
		
    if(ligne[i] == '&'){
			if(ligne[i+1] == '&'){
      	return 1;
			}
    }
  }
  return 0;
}


#ifdef TEST
int main(int argc, char* argv[]){
	char* element[10];
	int and;
	if(argc<3){
		fprintf(stderr,"usage : %s phrase separ\n",argv[0]);
		return 1;
	}
	printf("On decoupe '%s' suivant les '%s' : \n",argv[1],argv[2]);
	decoupe(argv[1],argv[2], element, 10);
	and = findAnd(element);
	for(int i = 0 ; element[i] != 0 ; i++){
		printf("%d : %s\n", i, element[i]);
	}
		printf("&& présent : %d\n",and);
	return 0;
}
#endif