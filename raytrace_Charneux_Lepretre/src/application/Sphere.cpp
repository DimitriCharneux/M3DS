#include "Sphere.h"
#include <cmath>
#include <iostream>
#include "GLTool.h"
#include "IntersectionArray.h"

/**
@file
@author Fabrice Aubert
*/

using namespace p3d;
using namespace std;

Sphere::Sphere() : Primitive() {}


/**
  donne la liste croissante issus de l'intersection de ray=(A,u)  et de la sphere x^2+y^2+z^2=1
  (2 ou 0 intersection)
*/
void Sphere::intersection(const Ray &ray,IntersectionArray *result) {

    /**
   * A COMPLETER : il faut résoudre l'équation en lambda (cf cours), puis créer dans le résultat les intersections correspondantes aux lambda  :
   * !! pour ajouter une intersection à la fin de la liste result, utilisez uniquement : result->addIntersection(lambda)
   * ray est déjà dans le repère local de la sphere unitaire centrée à l'origine :
   *   - ray.point() : donne l'origine du rayon (Vector3)
   *   - ray.direction() : donne le vecteur directeur (Vector3)
   * il faut impérativement retourner 0 ou 2 intersections pour assurer une cohérence dans l'intersection.
   * il faut que les intersections soient triées (ordre croissant) pour assurer le fonctionnement avec l'algorithme général d'intersection avec le CSG
   *
   *  rappel : a.dot(b) donne le produit scalaire de a par b
   */

    // on doit résoudre u²λ² + 2Auλ + A²-1 = 0

    result->clear(); // initialisation : liste d'intersection vide
    Vector3 a = ray.point(), u = ray.direction();
    //delta = b² - 4ac
    double delta = (2*a.dot(u))*(2*a.dot(u))  - 4 * u.dot(u) * (a.dot(a) -1);

    if(delta > 0){
        /*2 solutions :
         * x1 = (-b + racine(delta)) / 2a
         * x2 = (-b - racine(delta)) / 2a
         *
         * */
        double x1 = (-2*a.dot(u) + sqrt(delta)) / 2*u.dot(u);
        double x2 = (-2*a.dot(u) - sqrt(delta)) / 2*u.dot(u);
        result->addIntersection(x1);
        result->addIntersection(x2);
    }


}


/** ****************************************************** **/
/** ****************************************************** **/
/** ****************************************************** **/
/** ****************************************************** **/

Vector3 Sphere::computeNormal(const Vector3 &p) {
    return p;
}


void Sphere::drawGL() {
    p3d::shaderLightPhong();
    materialGL();
    p3d::drawSphere();
}

