#ifndef __OPENGL_STUFF__
#define __OPENGL_STUFF__

#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <SDL2/SDL_opengl.h>
#include <SDL2/sdl_opengl.h>
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>
#include <map>
#include <unordered_map>

#define GOLDEN ((sqrt(5.f)-1.f)/2.f)
#define SQRT1  (sqrtf(1.f))

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
#define DARK_RED    glm::vec3(0.5f, 0.0f, 0.0f)

#define DARK_DARK_BLUE   glm::vec3(0.0f, 0.0f, 0.25f)
 
#define ZERO  glm::vec3(0.0f, 0.0f, 0.0f)

#define PI 3.14159265f

static GLuint CurrentProgram;
static GLuint CurrentVertexArray;

typedef struct
{
	GLuint id;
	std::string vertex_path;
	std::string fragment_path;
	std::unordered_map<std::string, GLint> uniforms;
} Shader;

static GLuint current_shader_id;

typedef struct 
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 uv;
} Vertex;

typedef struct
{
	std::vector<Vertex> vertices;
} Face;

typedef struct 
{
	GLuint VAO;
	GLuint VBO;

	Shader *shader;

	// std::vector<Face> faces;
	std::vector<Vertex> vertices;
	int vertice_sz;

	GLenum draw_method;

} Mesh;

typedef struct
{
	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 rotation;

	glm::vec3 vel;
	glm::vec3 scale_vel;
	glm::vec3 rotation_vel;

	Mesh mesh;

	// Entity *parent;
	// std::list<Entity *> children;
} Entity;

// typedef struct
// {
// 	GLuint VAO;
// 	GLuint VBO;

// 	GLuint *shader_id;
// 	Vertex vertices[512];
// 	int vertice_sz;

// 	glm::vec3 position;
// 	glm::vec3 rotation;
// 	glm::vec3 scale;
// } Mesh;


typedef void (*MeshPrefabFn)(Mesh *m, glm::vec3, glm::vec3, glm::vec3, GLuint *);

bool intersectPlane(const glm::vec3 &n, const glm::vec3 &p0, const glm::vec3& l0, const glm::vec3 &l, float &t);

glm::vec3 intersectionPlanePoint(const glm::vec3 &n, const glm::vec3 &p0, const glm::vec3 &l0, const glm::vec3 &l);

// void prefab_cube(Mesh *m, glm::vec3 p, glm::vec3 r, glm::vec3 s, GLuint *shader_id);

// void set_color(Mesh *m, glm::vec3 color);

std::vector<glm::vec3> sub_triangles(std::vector<glm::vec3> triangles, int levels);

std::vector<glm::vec3> subdivide_triangle(glm::vec3 A, glm::vec3 B, glm::vec3 C);

void reload_shader(Shader *shader, std::string uniforms[], int uniform_sz = 0);

void create_shader(Shader *shader, std::string vertex_path, std::string fragment_path, std::string uniforms[], int uniform_sz);

GLuint load_shader_program(std::string vertex_shader_path, std::string fragment_shader_path);

GLuint compile_shader_program(std::string path, GLenum type);

GLuint load_image_1d(std::string image);

GLuint load_image_2d(std::string image);

static std::ifstream::pos_type get_filesize(std::string filename);

#endif