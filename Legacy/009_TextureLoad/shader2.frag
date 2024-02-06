#version 450 core


in vec3 myColor;
in vec2 textureCord;
uniform sampler2D texture0;
out vec4 outColor;

void main() {
   outColor = texture(texture0, textureCord) * vec4(0.6f, 0.6f, 1.0f, 1.0f);
}
