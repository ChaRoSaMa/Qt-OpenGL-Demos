#version 450 core


in vec3 myColor;
out vec4 outColor;
void main() {
   outColor = vec4(myColor, 1.0f);
}

