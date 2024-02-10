#version 450 core
uniform sampler2D tex0;
in vec2 texPos;
out vec4 outColor;

void main() {
    outColor = texture(tex0, texPos);
}
