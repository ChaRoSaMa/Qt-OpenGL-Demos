#version 450 core
layout (location = 0) in vec3 vertices;
out vec4 colorFromVertexShader;

void main() {
    gl_Position = vec4(vertices, 1.0f);
    colorFromVertexShader = vec4(0.5f, 0.8f, 0.9f, 1.0f);
}
