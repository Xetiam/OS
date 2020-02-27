/* ba-echo.c
 Pour afficher le contenu de la ligne de commande

 jm@univ-paris8.fr, fevrier 2008
*/
# include <stdio.h>

int
main(int ac, char * av[]){
  int i;

  printf("Programme lance sous le nom %s avec %d arguments\n",
	 av[0], ac - 1);
  for(i = 1; i < ac; i++)
    printf("argument %d : %s\n", i, av[i]);
  return 0;
}