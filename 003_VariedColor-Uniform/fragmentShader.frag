#version 450 core
uniform vec3 aColor;
out vec4 FragColor;

void main() {
    FragColor = vec4(aColor, 1.0f);
}
