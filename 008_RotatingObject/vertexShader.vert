#version 450 core
layout (location = 0) in vec3 vertexCoord;
layout (location = 1) in vec2 textureCoord;

out vec2 texCoord;

uniform mat4 transMat;

void main() {
    gl_Position = transMat * vec4(vertexCoord, 1.0f);
    texCoord = textureCoord;
}
