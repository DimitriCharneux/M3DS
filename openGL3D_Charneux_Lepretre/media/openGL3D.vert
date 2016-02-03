#version 130

in vec3 position;
in vec3 normal;
uniform mat4 transform;

out vec3 fColor;

uniform mat4 projection;
uniform vec3 lightPosition;
uniform vec3 diffuseColor;

void main() {
    vec3 N = normal, L = lightPosition - position;
    N=normalize(N);
    L=normalize(L);
    float intensity = max(dot(N,L),0.0);

    vec4 eyePosition=vec4(position,1); // passage en coordonnées homogènes

    vec4 clipPosition=projection*eyePosition; // transformation par la matrice de projection

    eyePosition=transform*eyePosition; // application de la rotation
    clipPosition=projection*eyePosition; // puis application de la matrice de projection

    fColor=vec3(intensity, intensity, intensity) * diffuseColor;


    gl_Position=clipPosition; // gl_Position doit être donné en clip coordinates

}
