#version 130

in vec3 position;
in vec3 normal;
uniform mat4 transform;

out vec4 fColor;

uniform mat4 projection;
uniform vec3 lightPosition;
uniform vec3 diffuseColor;

void main() {
    /*vec3 N = normal, L = lightPosition - position;
    N=normalize(N);
    L=normalize(L);
    float intensity = max(dot(N,L),0.0);*/

    vec4 N = transform*vec4(normal,0), L = transform * vec4(lightPosition,0) -vec4(position, 0);
    N=normalize(N);
    L=normalize(L);
    float intensity = max(dot(N,L),0.0);


    vec4 eyePosition=vec4(position,1); // passage en coordonnées homogènes

    vec4 clipPosition=projection*eyePosition; // transformation par la matrice de projection

    eyePosition=transform*eyePosition; // application de la rotation
    clipPosition=projection*eyePosition; // puis application de la matrice de projection

    fColor=vec4(intensity* diffuseColor, 1);


    gl_Position=clipPosition; // gl_Position doit être donné en clip coordinates

}
