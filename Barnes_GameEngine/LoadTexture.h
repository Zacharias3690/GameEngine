#ifndef LOADTEXTURE_H
#define LOADTEXTURE_H
#include <SOIL.h>
#include <string>
#include <gl/glew.h>
#include <iostream>
#include <vector>

GLuint Load2DTexture(std::string);
GLuint LoadCubeMap(std::string, std::string);
GLuint LoadCubeMap(std::vector<std::string>);

#endif