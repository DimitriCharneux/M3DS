#version 130

in vec3 fN,fL,fV;

out vec4 fragColor;

uniform vec3 materialDiffuse,materialSpecular;
uniform vec4 materialAmbient;

out vec4 fColor;

void main() {
  vec3 N,V,L,R;
  vec4 color=vec4(0,0,0,0);

  fL=normalize(L);
  fV=normalize(V);
  fN=normalize(N);

  R= 2 * (dot(L,N)) * N - L;
  R= normalize(R);

  specularIntensity = pow(dot(V,R), 50.0);

  // notez le max pour ne pas éclairer lorsque le produit scalaire est négatif (il faudra faire la même chose lors du calcul du spéculaire)
  diffuseIntensity=max(dot(N,L),0.0);

  // rouge, vert,bleu de l'éclairement :
  fragColor.rgb=diffuseIntensity*materialDiffuse+materialAmbient.xyz + specularIntensity;

  //car Ks c'est materialSpecular et qu'il est initialisé tout seul
  fragColor.rgb = fragColor.rgb + materialSpecular * specularIntensity;

  fragColor=color;
}
