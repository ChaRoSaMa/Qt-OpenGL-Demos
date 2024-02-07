#version 450 core
in vec4 colorFromVertexShader;
out vec4 FragColor;

void main() {
    FragColor = colorFromVertexShader;
}
