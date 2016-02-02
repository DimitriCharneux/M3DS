Charneux Dimitri
Leprêtre Rémy


Tout à été fait et fonctionne parfaitement et nous n'avons pas rencontré de difficultés particulières.


Q8/
Quel est le rôle d’un VBO ?
Il sert à copier les données de l'application dans les buffers d'OpenGL. Plus concrètement, c'est une méthode qui permet d'envoyer les données de l'application à la carte graphique pour que celle-ci ne doit pas aller chercher les données dans la RAM ce qui prendrait plus de temps.

d’un VAO ?
Un VAO permet de faire le lien entre les attributs du vertex shader et les VBOs utilisés par ces attributs.

d’un Program Shader ?
Le Progam Sharder est un programme exécuter par la carte graphique qui sert à calculer les pixels de l'image.


Q9/ 
voir Q9.jpg


Q11/
L'interpolation linéaire est utilisé pour calculer les couleurs d'un pixel. La couleur de chaque pixel sera calculé en fesant une variation de couleur entre les 3 points constituant le triagle. Les variables varying sont calculées entre le vertex shader (avec out) et le fragment shader (avec in).


Q13/
[0; 3; 2; 5; 1; 4]


Q15/
On constate une différence de couleur par rapport aux triangles précédents. Cela s'explique par le fait que l'on a modifié l'ordre des points des triangles mais pas l'ordre des couleurs associées à leurs sommets.


Q16/
Les couleurs proviennent du fait que le sommet vert est utilisé 2 fois alors que précédemment, il y avait un sommet vert et un rouge.


Q19/
Avec GL_TRIANGLE_STRIP, les triangles sont tracés de la manière suivantes : le premier triangle est tracé avec les 3 premier points du tableau, ensuite, pour chaque points, un triangle va être tracé entre ce point et les 2 derniers points utilisé. Un tableau de 4 points produira donc 2 triangles alors qu'avec GT_TRIANGLE, il en faudrait 6. 


Q27/
Les coordonnées de textures associés à chaque sommet permettent de savoir, pour chaque sommet, à quel point de l'image il va correspondre. Chaque sommet pourra donc être associé à n'importe quel points de l'image.

