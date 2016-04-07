Charneux Dimitri
Leprêtre Rémy

Doit contenir :
- ce que vous n'avez pas fait (et pourquoi). Précisez explicitement "tout à été fait et fonctionne parfaitement" si c'est le cas.
- difficultés rencontrées.
- commentaires éventuels sur le TP (points à éclaircir, longueur du sujet, etc). 

Ex2Q1/

Nous avons l'équation d'une spère x² + y² + z² = 1 
et l'équation du rayon de cette sphère P = A + λu

La variable A correspond à l'origine du rayon et u à sa direction, c'est 2 paramètres sont donné par ray.pont() et ray.direction().

Nous avons donc le système d'équation suivant : 
    x = A.x + λ * u.x
    y = A.y + λ * u.y
    z = A.z + λ * u.z

On a donc l'équation de spère suivantes :
    (A + λu)² = 1
    
En développant, on obtient l'équation du second degré (uλ)² + 2Auλ + A²-1 = 0

Nous avons plus qu'à résoudre cette équation du second degré.
    
