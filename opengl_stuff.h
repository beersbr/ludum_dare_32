#ifndef __OPENGL_STUFF__
#define __OPENGL_STUFF__

#include <iostream>
#include <string>
#include <fstream>
#include <SDL2/SDL_opengl.h>
#include <GL/glew.h>

GLuint load_shader_program(std::string vertex_shader_path, std::string fragment_shader_path);

GLuint compile_shader_program(std::string path, GLenum type);

static std::ifstream::pos_type get_filesize(std::string filename);

#endif