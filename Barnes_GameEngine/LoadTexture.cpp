#include "LoadTexture.h"

/* load 2d image into OpenGL texture */
GLuint Load2DTexture(std::string file_location)
{
	GLuint tex;
	int width, height;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* image = SOIL_load_image(file_location.c_str(), &width, &height, 0, SOIL_LOAD_RGB);

	if(image == NULL)
	{
		float pixels[] = {
			0.0, 0.0, 0.0, 1.0, 0.0, 1.0,
			1.0, 0.0, 1.0, 0.0, 0.0, 0.0
		};
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);
	}
	else
	{
		glGenerateMipmap(GL_TEXTURE_2D);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	
	return tex;
}

/* load 6 images into an OpenGL cube map */
GLuint LoadCubeMap(std::vector<std::string> file_locations)
{
	//TODO: create variable arguments for SOIL flags

	if(file_locations.size() != 6)
	{
		std::cout << "Must pass 6 images to LoadCubeMap" << std::endl;
		return 0;
	}

	GLuint tex_cube = SOIL_load_OGL_cubemap
		(
			file_locations[0].c_str(),
			file_locations[1].c_str(),
			file_locations[2].c_str(),
			file_locations[3].c_str(),
			file_locations[4].c_str(),
			file_locations[5].c_str(),
			SOIL_LOAD_RGB,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS
		);

	if(tex_cube == 0)
	{
		std::cout << "Error loading images" << std::endl;
		return 0;
	}
	else
	{
		return tex_cube;
	}
}

/* 
load and split image into OpenGL cubemap,
faceOrder takes 1 character for order to load in
for example "ESWNUP" = East South West North Up Down
*/
GLuint LoadCubeMap(std::string file_location, std::string faceOrder)
{
	GLuint tex_cube = SOIL_load_OGL_single_cubemap
		(
			file_location.c_str(),
			faceOrder.c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS
		);

	if(tex_cube == 0)
	{
		std::cout << "Error loading cubemap" << std::endl;
		return 0;
	}
	else
	{
		return tex_cube;
	}
}