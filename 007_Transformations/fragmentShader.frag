#version 450 core
in vec2 texCoord;
uniform sampler2D tex0;
uniform sampler2D tex1;

out vec4 outColor;

void main() {
    outColor = mix(
                texture(tex0, texCoord),
                texture(tex1, texCoord),
                0.5f);
}
