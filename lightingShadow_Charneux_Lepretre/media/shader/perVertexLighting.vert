#version 130

in vec3 position;  // in Local coordinates
in vec3 normal;    // in Local coordinates

uniform mat4 modelviewMatrix; // M_Eye->Local
uniform mat3 normalMatrix;
uniform mat4 mvp;             // mvp = Projection * M_Eye->Local = M_ClipCoordinates->Local

uniform vec3 lightPosition;   // in Eye coordinates.

uniform vec3 materialDiffuse,materialSpecular;
uniform vec4 materialAmbient;

out vec4 fColor;

void main() {
  float diffuseIntensity,  brillance = 50;
  float specularIntensity=0;
  vec4 positionEye;
  vec3 L,V,N, R;

  positionEye=modelviewMatrix*vec4(position,1);

  V=-positionEye.xyz/positionEye.w;
  L=lightPosition+V;
  N=normalMatrix*normal;

  L=normalize(L);
  V=normalize(V);
  N=normalize(N);

  R = 2*(dot(L,N)) * N-L;
  R = normalize(R);

  specularIntensity = max(pow(dot(V,R), brillance) , 0.0);

  // notez le max pour ne pas éclairer lorsque le produit scalaire est négatif (il faudra faire la même chose lors du calcul du spéculaire)
  diffuseIntensity=max(dot(N,L),0.0);

  // rouge, vert,bleu de l'éclairement :
  fColor.rgb=diffuseIntensity*materialDiffuse + specularIntensity * materialSpecular +materialAmbient.xyz;
  // le alpha est porté uniquement par materialAmbient.a.:
  fColor.a=materialAmbient.a;

  gl_Position=mvp*vec4(position,1);
}
