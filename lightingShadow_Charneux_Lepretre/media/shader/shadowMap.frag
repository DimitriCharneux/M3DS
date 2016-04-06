#version 130

uniform sampler2D depthTexture;

in vec4 fTexCoord;

out vec4 fragColor;

void main() {
    vec4 texCoord=fTexCoord;

    texCoord.xyz/=texCoord.w; // clip coordinates => ndc
    texCoord.xyz = (texCoord.xyz+1)/2;

    //fragColor=texture(depthTexture,texCoord.xy);
    fragColor=1.0-clamp(50.0*(1.0-fragColor),0,1);
}
