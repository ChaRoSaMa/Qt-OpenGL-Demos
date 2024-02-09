#version 450 core
in vec4 aColor;
out vec4 FragColor;

void main() {
    FragColor = aColor;
}

/* refer to the LearnOpenGL(https://learnopengl.com/Getting-started/Shaders):
 The image may not be exactly what you would expect,
 since we only supplied 3 colors, not the huge color
 palette we're seeing right now. This is all the result
 of something called fragment interpolation in the
 fragment shader. When rendering a triangle the
 rasterization stage usually results in a lot more
 fragments than vertices originally specified. The
 rasterizer then determines the positions of each of
 those fragments based on where they reside on the
 triangle shape.

 Based on these positions, it interpolates all the
 fragment shader's input variables. Say for example
 we have a line where the upper point has a green
 color and the lower point a blue color. If the
 fragment shader is run at a fragment that resides
 around a position at 70% of the line, its resulting
 color input attribute would then be a linear combination
 of green and blue; to be more precise: 30% blue and 70% green.

 This is exactly what happened at the triangle. We
 have 3 vertices and thus 3 colors, and judging from
 the triangle's pixels it probably contains around
 50000 fragments, where the fragment shader interpolated
 the colors among those pixels. If you take a good look
 at the colors you'll see it all makes sense: red to blue
 first gets to purple and then to blue. Fragment interpolation
 is applied to all the fragment shader's input attributes.
*/
