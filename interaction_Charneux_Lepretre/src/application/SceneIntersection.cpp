#include "SceneIntersection.h"

#include "Plane.h"
#include "MeshObject3D.h"

using namespace p3d;
using namespace std;


SceneIntersection::~SceneIntersection() {
    clean();
}

SceneIntersection::SceneIntersection() {
    _result.clear();
}

void SceneIntersection::clean() {
    if (!_result.empty()) {
        for(unsigned int i=0;i<_result.size();i++) {
            delete _result[i];
        }
        _result.clear();
    }
}




void SceneIntersection::insert(Intersection *i) {
    bool found=false;
    int place=_result.size();
    _result.push_back(NULL);
    while(!found) {
        if (place==0 || _result[place-1]->lambda()<=i->lambda()) {
            found=true;
        }
        else {
            _result[place]=_result[place-1];
            place--;
        }
    }
    _result[place]=i;
}

/**
  l : pickingRay dans le repère local à l'objet. l.point() donne l'origine, l.direction() donne un vecteur directeur.
  s0,s1,s2 : sommets du triangle (repère local).
  Il faut :
  - d'abord déterminer si la droite intersecte le triangle (i.e. l passe du même coté des
    segments [s0s1],[s1s2],[s2s0]
  - si la droite intersecte, calculer le lambda de l'intersection (i.e. intersection entre le plan du triangle,
    I=l.point()+lambda*l.direction() ).
  Remarque : voir l'appelant intersect(MeshObject3D *mesh) pour les paramètres : traduit le rayon dans le repère local;
    passe les 3 sommets du triangle; s'il y a intersection, l'insère dans le tableau _result
 */
bool SceneIntersection::intersect(const Line &ray,const Vector3 &s0,const Vector3 &s1,const Vector3 &s2,double *lambdaRes) {
    bool res=false;
    double lambda=0.0;

    /*

    Très mal expliqué dans le cours, copié de :
    https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm

    */

    Vector3 e1, e2;  //Edge1, Edge2
    Vector3 P, Q, T;
    float det, inv_det, u, v;
    float t;

    //Find vectors for two edges sharing V1
    e1 = s1 - s0;
    e2 = s2 - s0;
    //Begin calculating determinant - also used to calculate u parameter
    P = ray.direction().cross(e2);
    //if determinant is near zero, ray lies in plane of triangle
    det = e1.dot(P);
    //NOT CULLING
    if(det > -EPSILON_PREC && det < EPSILON_PREC) return res;
    inv_det = 1.f / det;

    //calculate distance from V1 to ray origin
    T = ray.point() - s0;

    //Calculate u parameter and test bound
    u = T.dot(P) * inv_det;
    //The intersection lies outside of the triangle
    if(u < 0.f || u > 1.f) return res;

    //Prepare to test v parameter
    Q = T.cross(e1);

    //Calculate V parameter and test bound
    v = ray.direction().dot(Q) * inv_det;
    //The intersection lies outside of the triangle
    if(v < 0.f || u + v  > 1.f) return res;

    t = e2.dot(Q) * inv_det;

    if(t > EPSILON_PREC) { //ray intersection
        lambda = t;
        res = true;
    }


    *lambdaRes=lambda;
    return res;
}


void SceneIntersection::intersect(MeshObject3D *e) {
    Line rayLocal;
    rayLocal.point(e->pointTo(Coordinate_Local,_pickingRay.point()));
    rayLocal.direction(e->directionTo(Coordinate_Local,_pickingRay.direction()));
    double lambda;

    for(unsigned int i=0;i<e->nbFace();i++) {
        bool ok=intersect(rayLocal,e->positionVertexFace(i,0),e->positionVertexFace(i,1),e->positionVertexFace(i,2),&lambda);
        if (ok && lambda>1) {
            Intersection *inter=new Intersection();
            inter->mesh(e);
            inter->lambda(lambda);
            inter->rayWorld(_pickingRay);
            this->insert(inter);
        }
    }
}


void SceneIntersection::intersect(const std::vector<p3d::MeshObject3D *> &allObj, const p3d::Line &pickingRay) {
    _pickingRay=pickingRay;
    MeshObject3D *e;
    clean();
    for(vector<MeshObject3D *>::const_iterator i=allObj.begin();i!=allObj.end();i++) {
        e=*i;
        intersect(e);
    }
}


