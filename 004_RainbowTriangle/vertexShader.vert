#version 450 core
out vec4 aColor;
layout (location = 0) in vec3 verticesPos;
layout (location = 1) in vec3 verticesColor;

void main() {
    aColor = vec4(verticesColor, 1.0f);
    gl_Position = vec4(verticesPos, 1.0f);
}
