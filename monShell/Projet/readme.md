# monShell

### **Compilation :**
monShell est un **minishell**, il est compilable via un makefile :
* make : pour compiler le minishell
* clean : pour supprimer les .o
* cleanall : pour supprimer les .o et l'exécutable
<br/>

De plus ce miniShell est capable :
* de lancer n'importe qu'elle commande bash se trouvant dans le **$PATH**
* de lancer plusieurs commande dans l'ordre à l'aide de && 
<br/>

### **Commande interne :**
#### **monc** (commande permettant de changer de répertoire courant) // fonctionnel :
  ##### Usage :
  * moncd "path" permettra de se rendre à **"path"**
  * moncd permettra de se rendre dans le répertoire contenue dans **$HOME**
  * moncd ./"path" permettra de se rendre à **"path"** à partir du répertoire courant
  * moncd .. permettra de se rendre dans le dossier parent au répertoire courant
#### **monexit** (commande permettant de mettre fin proprement au minishell) // fonctionnel :
  ##### Usage :
  * monexit

### **Commande externe :**
#### Aucune pour l'instant

<br/>
<br/>

Projet de licence 2 informatique ied de paris8


* **Auteur :** Lepiller Charly
* **N°étudiant :** 18901883
* **Date de création : 24/02/2020** 