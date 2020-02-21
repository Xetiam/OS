############################################################
### Auteur: Charly Lepiller / replace / Date: 03/02/2020 ###
############################################################

#Variables
EXEC = mon-if
CC=gcc
CCFLAG=-Wall
SRC=$(wildcard *.c)
OBJ= $(SRC:.c=.o)

All: $(EXEC)

#Génération d'executables
mon-if: $(OBJ)
	@$(CC) -o $@ $^ $(CCFLAG) 
	@echo $@ "generated"

mon-if.o : fonctionsOs.h
#Génération des .o
%.o: %.c
	@$(CC) -o $@ -c $< $(CCFLAG) 
	@echo $@ "generated"

#Clean and Cleanall
.PHONY: clean cleanall

clean: 
	@rm -rf *.o
	@echo ".o supprimer"

cleanall: clean
	@rm -rf $(EXEC)
	@echo "exec supprimer"