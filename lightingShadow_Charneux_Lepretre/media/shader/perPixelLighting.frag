#version 130

in vec3 fN,fL,fV;

out vec4 fragColor;

uniform vec3 materialDiffuse,materialSpecular;
uniform vec4 materialAmbient;

out vec4 fColor;

void main() {
    float diffuseIntensity;
  float specularIntensity=0;
  vec4 positionEye;
  vec3 L,V,N,R;
  vec4 color=vec4(0,0,0,0);

  L=normalize(fL);
  V=normalize(fV);
  N=normalize(fN);

  R= 2 * (dot(L,N)) * N - L;
  R= normalize(R);

  specularIntensity = pow(dot(V,R), 50.0);

  // notez le max pour ne pas éclairer lorsque le produit scalaire est négatif (il faudra faire la même chose lors du calcul du spéculaire)
  diffuseIntensity=max(dot(N,L),0.0);

  // rouge, vert,bleu de l'éclairement :
  fragColor.rgb=diffuseIntensity*materialDiffuse+materialAmbient.xyz;

  //car Ks c'est materialSpecular et qu'il est initialisé tout seul
  fragColor.rgb = fragColor.rgb + materialSpecular * specularIntensity;

  fragColor.a = materialAmbient.a;

}
