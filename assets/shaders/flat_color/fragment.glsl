#version 450 core

out vec4 frag_color;

uniform vec3 color = vec3(1.0);

void main()
{
    // Apply gamma correction to the uniform color
    frag_color = vec4(pow(color, vec3(1.0 / 2.2)), 1.0);
}