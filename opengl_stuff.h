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
#define PINK   glm::vec3(1.0f, 0.0f, 1.0f)
#define YELLOW glm::vec3(1.0f, 1.0f, 0.0f)

#define DARK_BLUE   glm::vec3(0.0f, 0.0f, 0.5f)

#define DARK_DARK_BLUE   glm::vec3(0.0f, 0.0f, 0.25f)
 
#define ZERO  glm::vec3(0.0f, 0.0f, 0.0f)

#define PI 3.14159265

static GLuint CurrentProgram;
static GLuint CurrentVertexArray;

typedef struct 
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
} Vertex;

typedef struct
{
	GLuint VAO;
	GLuint VBO;

	GLuint *shader_id;
	Vertex vertices[512];
	int vertice_sz;

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
} Mesh;

bool intersectPlane(const glm::vec3 &n, const glm::vec3 &p0, const glm::vec3& l0, const glm::vec3 &l, float &t);

glm::vec3 intersectionPlanePoint(const glm::vec3 &n, const glm::vec3 &p0, const glm::vec3 &l0, const glm::vec3 &l);

void prefab_cube(Mesh *m, glm::vec3 p, glm::vec3 r, glm::vec3 s, GLuint *shader_id);

void set_color(Mesh *m, glm::vec3 color);

GLuint load_shader_program(std::string vertex_shader_path, std::string fragment_shader_path);

GLuint compile_shader_program(std::string path, GLenum type);

static std::ifstream::pos_type get_filesize(std::string filename);

#endif