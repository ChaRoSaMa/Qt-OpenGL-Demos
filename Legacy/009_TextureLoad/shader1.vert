#version 450 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTextureCord;
out vec3 myColor;
out vec2 textureCord;

void main() {
   gl_Position = vec4(aPos.x, -aPos.y, aPos.z, 1.0);
   myColor = aColor;
   textureCord = aTextureCord;
}
