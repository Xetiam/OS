#include "fonctionsOs.h"


int main(int argc, char* argv[]){
    /* Initialisation des variables */
    char** tab1 = (char**) malloc(100);
    char** tab2 = (char**) malloc(100);
    int nbrArg1, nbrArg2, t, pid, etat = 0;
    tab1 = decoupe(argv[1],&nbrArg1);
    tab2 = decoupe(argv[2],&nbrArg2);
    char* path1 = prepaPath(tab1);
    char* path2 = prepaPath(tab2);
     /* Création du processus enfant */
     t = fork();
     if(t == -1){
         perror("fork");
         return 1;
     }
     else if(t == 0){
        execv(path1,tab1);
        perror("execv enfant");
        exit(1);
     }
     else {
        while(pid!= t){
            pid = wait(&etat);
            if(pid == -1 ){
                perror("wait");
            }
        }
        printf("EXIT STATUS : %d\n",WEXITSTATUS(etat));
        assert(pid == t);
        if(WEXITSTATUS(etat) != 0){
            free(tab1);
            free(tab2);
            printf("Le processus enfant ayant échoué, la commande dans le processus parent ne sera pas lancer.\n");
            return 1;
        }
        execv(path2,tab2);
        perror("execv parent");
        free(tab1);
        free(tab2);
        return 0;
    }
}