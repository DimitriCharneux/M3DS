#version 130

in vec3 position;
in vec3 color;
uniform mat4 transform;

out vec3 fColor;

uniform mat4 projection;

void main() {
    vec4 eyePosition=vec4(position,1); // passage en coordonnées homogènes

    vec4 clipPosition=projection*eyePosition; // transformation par la matrice de projection

    eyePosition=transform*eyePosition; // application de la rotation
    clipPosition=projection*eyePosition; // puis application de la matrice de projection

    fColor=color;

    gl_Position=clipPosition; // gl_Position doit être donné en clip coordinates
}
