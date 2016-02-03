Charneux Dimitri
Lepretre Remy

Doit contenir :
Tout à été fait et fonctionne parfaitement.

Q7/
Comme le premier triangle est déssiné avant les autres, on ne voit pas de rouge dans l'image finale.
Concernant les parties verte et bleue,  on les dessinent avant le cyan pour que celui-ci aille cacher la partie droite de ces deux triangles.

Q8/
Si maintenant seuls les triangles rouge et bleu sont affichés, c'est car nous prenons maintenant en compte la profondeur des triangles déssinés.

Q9/
Avec GL_GREATER, on utilise la formule depth(src)>depth(dst). De ce fait, comme l'image est initialisée avec des pixels blanc ayant comme z 1, la formule va toujours nous retourner false et les pixels ne vont jamais changer.

Avec glClearDepth à 0, les triangles avec le z le plus élevé vont être affiché soit le vert et le cyan. 

Avec glClearDepth à 0.5, On obtient une image avec une sorte de gemme moitié verte, moitié cyan. Cela s'explique car les points gauche et droite ont une coordonnée z à -1. Comme le depth est réglé à 0.5, les coin gauche et droite vont être derrière le fond blanc.

Q13/
On modifie les coordonnées minimale et maximale de x et y ce qui nous permet de voir plus ou moins du décor en fonction des coordonnées qui sont référencés.

Q16/
Pour un cube avec une couleur par face il faudrait 24 sommets

