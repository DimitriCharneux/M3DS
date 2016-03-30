CHARNEUX Dimitri
LEPRETRE Rémy

Doit contenir :
- ce que vous n'avez pas fait (et pourquoi). Précisez explicitement "tout à été fait et fonctionne parfaitement" si c'est le cas.
- difficultés rencontrées.
- commentaires éventuels sur le TP (points à éclaircir, longueur du sujet, etc). 

-------------Exercice 1----------------------
Q1 : V est la position de l'oeil, L est la position de la lumière et N la normale. Et lorsque l'on normalise les 3 variables : on les place entre 0 et 1.
DiffuseIntensity l'intensité de lumière au point indiqué.
materialDiffuse la couleur

Q3: La position de l'image est fixe car définit une fois et non variable.
L'image apparait dans le coin en haut à droite car les coordonnées de gl_position sont comprises entre [0,1] alors que la fenêtre va de [-1,1]
On ne voit pas la texture sur le fond de la scène car c'est blanc sur blanc.



-------------Exercice 2----------------------
Q2: avec GL_REPEAT, les coordonnées peuvent être en dehors de [0,1] du coup l'image peut apparaitre dans les 4 coins, alors qu'avec CLAMP_TO_BORDER les valeurs de s et t sont comprises uniquement entre [0,1] ce qui explique sont apparition dans le coin en haut à droite.

Q4: Comme nous avons maintenant ramener les positions de la texture en [0,1] et que de base la position de l'image est également comprise entre [0,1] elle remplit donc tout l'espace.

Q5.1 : Ici l'image est posé à une position précise et si cette position bouge, l'image bouge avec cette position puisque greffer dessus.

Q5.2 : Ici par contre l'image n'est accroché à rien et juste fixe par rapport à la vue. L'image reste donc fixe alors que le décor derrière bouge.

Q7: L'image est translaté par rapport aux différents axes en fonction des valeurs fournies.

Q9: pour agrandir la taille par 2 il faut mettre 0.5, sinon on divise la taille par 2.
