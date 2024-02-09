#version 450 core
layout (location = 0 ) in vec3 thePos;

void main() {
    gl_Position = vec4(thePos, 1.0f);
}
