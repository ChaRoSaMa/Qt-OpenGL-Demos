#version 450 core
uniform sampler2D tex0;
uniform sampler2D tex1;
in vec2 texPos;
out vec4 outColor;

void main() {
    outColor = mix(
                texture(tex0, texPos),
                texture(tex1, texPos),
                0.5f
                );
}
