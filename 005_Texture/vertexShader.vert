#version 450 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexturePos;

out vec2 texPos;
void main() {
    gl_Position = vec4(aPos, 1.0f);
    texPos = aTexturePos;
}
