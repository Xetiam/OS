############################################################
### Auteur: Charly Lepiller / replace / Date: 03/02/2020 ###
############################################################

#Variables
TEST = no
CC=gcc
ifeq ($(TEST),yes)
	CCFLAG= -g -Wall -DTEST
else
	CCFLAG = -g -Wall
endif
EXEC = monShell
SRC=$(wildcard *.c)
OBJ= $(SRC:.c=.o)

All: $(EXEC)
ifeq ($(TEST),yes)
	@echo "Génération en mode test"
else
	@echo "Génération en mode classique"
endif
#Génération d'executables
monShell: $(OBJ)
	@$(CC) -o $@ $^ $(CCFLAG) 
	@echo $@ "generated"

monShell.o : fonctionsOs.h
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