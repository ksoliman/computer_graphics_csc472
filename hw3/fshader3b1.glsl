#version 330

// PUT YOUR CODE HERE
// Interpolated values from vertex shader
in vec2 v_TexCoord;

// Uniform constant variables
uniform sampler2D u_Sampler;

// Outputs
out vec4 fragColor;

void main()
{
	// PUT YOUR CODE HERE
	// Material properties. Only need base color of the picture/texture
	vec3 MaterialDiffuseColor = texture(u_Sampler, v_TexCoord).xyz;

	fragColor = vec4(MaterialDiffuseColor, 1.0);
}
