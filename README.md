# ImagesTaches
Depôt pour le projet Image taches de M.Bourdin 

# Enoncé
Il faut sur, une image, trouver automatiquement toutes les "taches de couleur". </br> 
L'image est donnée comme **un grand tableau avec un octet par couleur par "pixel" (trois couleurs, R, G et B).** </br> 
C'est donc une vaste **matrice de (XMAX x YMAX x 3) octets**.
Trouver les taches consiste à trouver et numéroter les zones connexes ayant la même couleur.
Une bonne méthode consisterait à commencer par trouver tous les pixels connexes ayant une certaine couleur, ils forment une tache.
Puis à réitérer ce processus pour tous les pixels.
On a alors toutes les taches, si elles ont été listées, il est maintenant facile de leur **appliquer un traitement**.
Un traitement pourrait être de délimiter en noir les taches de couleur.
Enfin, une tache peut être une zone dont les pixels ont à peu près la même couleur. On définira cette approximation et on fera la délimitation de ces zones comme précédemment. 
Le rapport contiendra des explications sur les procédures mises en oeuvre, le mode d'emploi, le listing du programme et des traces d'utilisation.
Le programme devra tourner sur au moins une des machines en libre-service du Bocal et sera écrit en C, avec, si nécessaire, utilisation des librairies OpenGL, Glu, Glut et GL4D, seules librairies non standard autorisées. 
