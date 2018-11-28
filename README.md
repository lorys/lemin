# lem_in
Lem-in est un projet de la branche Algorithmie du cursus de l'école 42.
## Principe
Le principe de ce projet est de faire traverser une fourmillière composée de salles reliées par des tubes à des fourmis. Une salle peut être connecté a une infinité de tubes mais un tube ne peut relier que deux salles entres elles. Pour construire une fourmilière, le programme lis sur l'entrée standard du texte formatté comme suis:
```
nombre_de_fourmis
les_salles
les_tubes
```
Voici un exemple de `map` valide:
```c
##start
1 23 3
2 16 7
# rooms
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
# links
4-2
2-1
7-6
7-2
7-4
6-5
#autre commentaire
```
 ## Règles du jeu
 - Au début du jeu, toutes les fourmis sont sur la salle indiquée par la commande `##start`. Le but est de les amener sur la salle indiquée par la commande `##end` en prenant le moins de tours possible.
 - Chaque salle ne peut contenir qu'une seule fourmi à la fois (sauf `##start` et `##end` qui peuvent en contenir autant qu’il le faut).
 - On considère que les fourmis sont toutes dans la salle `##start` au démarrage.
 - Il faut afficher à chaque tour uniquement les fourmis qui ont bougé.
 
## Format de sortie
```
La-i Lb-j Lc-k
```
Où `a`, `b` et `c` sont les noms des fourmis et `i`, `j` et `k` sont les numéros des salles dans lesquelles vont les fourmis.
## Utilisation :

```
$>make
...
$>./lem-in < map_pour_lemin
Le résultat s'affichera ici.
```
