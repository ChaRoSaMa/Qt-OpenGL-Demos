#version 450 core

out vec4 testColor;
uniform vec4 rainbowColor;
void main() {
   testColor = rainbowColor;
}
