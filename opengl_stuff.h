#ifndef __OPENGL_STUFF__
#define __OPENGL_STUFF__

#include <iostream>
#include <string>
#include <fstream>
#include <SDL2/SDL_opengl.h>
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>

#define PX glm::vec3( 1.0f,  0.0f,  0.0f)
#define NX glm::vec3(-1.0f,  0.0f,  0.0f)
#define PY glm::vec3( 0.0f,  1.0f,  0.0f)
#define NY glm::vec3( 0.0f, -1.0f,  0.0f)
#define PZ glm::vec3( 0.0f,  0.0f,  1.0f)
#define NZ glm::vec3( 0.0f,  0.0f, -1.0f)

#define WHITE  glm::vec3(1.0f, 1.0f, 1.0f)
#define BLACK  glm::vec3(0.0f, 0.0f, 0.0f)
#define BLUE   glm::vec3(0.0f, 0.0f, 1.0f)
#define RED    glm::vec3(1.0f, 0.0f, 0.0f)
#define GREEN  glm::vec3(0.0f, 1.0f, 0.0f)
#define CYAN   glm::vec3(0.0f, 1.0f, 1.0f)
 
#define ZERO  glm::vec3(0.0f, 0.0f, 0.0f)

typedef struct 
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
} Vertex;

typedef struct
{
	GLuint *shader_id;
	Vertex vertices[512];
	int vertice_sz;
	// std::vector<Vertex> vertices;

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
} Mesh;

void prefab_cube(Mesh *m, glm::vec3 p, glm::vec3 r, glm::vec3 s, GLuint *shader_id);

GLuint load_shader_program(std::string vertex_shader_path, std::string fragment_shader_path);

GLuint compile_shader_program(std::string path, GLenum type);

static std::ifstream::pos_type get_filesize(std::string filename);

#endif