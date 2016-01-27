#version 130

in vec4 fColor;
in vec2 fTexCoord;

uniform sampler2D texture;
uniform float coeff;

out vec4 fragColor;
        
void main() {
    //fragColor=fColor;
    //fragColor=texture2D(texture, fTexCoord);
    //fragColor=texture2D(texture, fTexCoord)*fColor;
    fragColor=texture2D(texture, fTexCoord)*fColor.b;
    fragColor.g*=(1.0-coeff);
}
