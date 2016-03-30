#version 130

in vec3 fN,fL,fV;

out vec4 fragColor;

uniform vec3 materialDiffuse,materialSpecular;
uniform vec4 materialAmbient;

void main() {
    float diffuseIntensity, brillance = 50;
    float specularIntensity=0;
    vec3 N,L,V,R;
    vec4 color=vec4(0,0,0,0);

    L = normalize(fL);
    N = normalize(fN);
    V = normalize(fV);

    R = 2*(dot(L,N)) * N-L;
    R = normalize(R);

    specularIntensity = max(pow(dot(V,R), brillance) , 0.0);

    // notez le max pour ne pas éclairer lorsque le produit scalaire est négatif (il faudra faire la même chose lors du calcul du spéculaire)
    diffuseIntensity=max(dot(N,L),0.0);

    // rouge, vert,bleu de l'éclairement :
    color.rgb=diffuseIntensity*materialDiffuse + specularIntensity * materialSpecular +materialAmbient.xyz;
    // le alpha est porté uniquement par materialAmbient.a.:
    color.a=materialAmbient.a;

    fragColor=color;
}
