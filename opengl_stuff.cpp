#include "opengl_stuff.h"

void prefab_cube(Mesh *m, glm::vec3 p, glm::vec3 r, glm::vec3 s, GLuint *shader_id)
{
	// back face
	m->vertice_sz = 0;
	m->vertices[m->vertice_sz].position = glm::vec3(-0.5f,  0.5f, -0.5f);
	m->vertices[m->vertice_sz].normal = NZ;
	m->vertices[m->vertice_sz].color = RED;

	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f, -0.5f); 
	m->vertices[m->vertice_sz].normal = NZ;
	m->vertices[m->vertice_sz].color = RED;

	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.5f, -0.5f); 
	m->vertices[m->vertice_sz].normal = NZ;
	m->vertices[m->vertice_sz].color = RED;

	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.5f, -0.5f); 
	m->vertices[m->vertice_sz].normal = NZ;
	m->vertices[m->vertice_sz].color = RED;

	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f, -0.5f); 
	m->vertices[m->vertice_sz].normal = NZ;
	m->vertices[m->vertice_sz].color = RED;

	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f, -0.5f); 
	m->vertices[m->vertice_sz].normal = NZ;
	m->vertices[m->vertice_sz].color = RED;

	// right face
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.5f, -0.5f);
	m->vertices[m->vertice_sz].normal = PX;
	m->vertices[m->vertice_sz].color = BLUE;

	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f, -0.5f);
	m->vertices[m->vertice_sz].normal = PX;
	m->vertices[m->vertice_sz].color = BLUE;

	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = PX;
	m->vertices[m->vertice_sz].color = BLUE;

	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = PX;
	m->vertices[m->vertice_sz].color = BLUE;

	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f, -0.5f);
	m->vertices[m->vertice_sz].normal = PX;
	m->vertices[m->vertice_sz].color = BLUE;

	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = PX;
	m->vertices[m->vertice_sz].color = BLUE;

	// front face
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = PZ;
	m->vertices[m->vertice_sz].color = WHITE;

	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = PZ;
	m->vertices[m->vertice_sz].color = WHITE;

	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = PZ;
	m->vertices[m->vertice_sz].color = WHITE;

	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = PZ;
	m->vertices[m->vertice_sz].color = WHITE;

	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = PZ;
	m->vertices[m->vertice_sz].color = WHITE;

	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = PZ;
	m->vertices[m->vertice_sz].color = WHITE;


	// left face
	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = NX;
	m->vertices[m->vertice_sz].color = CYAN;

	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = NX;
	m->vertices[m->vertice_sz].color = CYAN;

	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.5f, -0.5f);
	m->vertices[m->vertice_sz].normal = NX;
	m->vertices[m->vertice_sz].color = CYAN;

	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.5f, -0.5f);
	m->vertices[m->vertice_sz].normal = NX;
	m->vertices[m->vertice_sz].color = CYAN;

	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = NX;
	m->vertices[m->vertice_sz].color = CYAN;

	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f, -0.5f);
	m->vertices[m->vertice_sz].normal = NX;
	m->vertices[m->vertice_sz].color = CYAN;


	// top face
	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = PY;
	m->vertices[m->vertice_sz].color = DARK_BLUE;

	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.5f, -0.5f);
	m->vertices[m->vertice_sz].normal = PY;
	m->vertices[m->vertice_sz].color = DARK_BLUE;

	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = PY;
	m->vertices[m->vertice_sz].color = DARK_BLUE;

	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = PY;
	m->vertices[m->vertice_sz].color = DARK_BLUE;

	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.5f, -0.5f);
	m->vertices[m->vertice_sz].normal = PY;
	m->vertices[m->vertice_sz].color = DARK_BLUE;

	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.5f, -0.5f);
	m->vertices[m->vertice_sz].normal = PY;
	m->vertices[m->vertice_sz].color = DARK_BLUE;


	// bottom face
	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f, -0.5f);
	m->vertices[m->vertice_sz].normal = NY;
	m->vertices[m->vertice_sz].color = BLACK;

	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = NY;
	m->vertices[m->vertice_sz].color = BLACK;

	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f, -0.5f);
	m->vertices[m->vertice_sz].normal = NY;
	m->vertices[m->vertice_sz].color = BLACK;

	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f, -0.5f);
	m->vertices[m->vertice_sz].normal = NY;
	m->vertices[m->vertice_sz].color = BLACK;

	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = NY;
	m->vertices[m->vertice_sz].color = BLACK;

	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f,  0.5f);
	m->vertices[m->vertice_sz].normal = NY;
	m->vertices[m->vertice_sz].color = BLACK;

	m->vertice_sz += 1;

	m->position = p;
	m->rotation = r;
	m->scale = s;
	m->shader_id = shader_id;

	// GLuint VAO;
	glGenVertexArrays(1, &m->VAO);
	glBindVertexArray(m->VAO);

	CurrentVertexArray = m->VAO;

	// GLuint VBO;
	glGenBuffers(1, &m->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m->VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*m->vertice_sz, (GLfloat *)&m->vertices[0], GL_STREAM_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, position)));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, normal)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, color)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);


}

void set_color(Mesh *m, glm::vec3 color)
{
	if(!m)
	{
		#ifdef DEBUG_BUILD
		std::cout << "The mesh pointer argument is null" << std::endl;
		#endif
		return;
	}

	for(int i = 0; i < m->vertice_sz; i++)
	{
		m->vertices[i].color = color;
	}

	if(m->VAO != CurrentVertexArray)
	{
		glBindVertexArray(m->VAO);
		CurrentVertexArray = m->VAO;
	}

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Vertex)*m->vertice_sz, (GLfloat *)&m->vertices[0]);

}


GLuint load_shader_program(std::string vertex_shader_path, std::string fragment_shader_path)
{
	GLuint vertex_shader_id = compile_shader_program(vertex_shader_path, GL_VERTEX_SHADER);
	GLuint fragment_shader_id = compile_shader_program(fragment_shader_path, GL_FRAGMENT_SHADER);

	if(vertex_shader_id == 0)
	{
		std::cerr << "Could not compile vertex shader." << std::endl;
		return 0;
	}

	if(fragment_shader_id == 0)
	{
		std::cerr << "Could not compile fragment shader." << std::endl;
		return 0;
	}

	GLuint program = glCreateProgram();
	glAttachShader(program, vertex_shader_id);
	glAttachShader(program, fragment_shader_id);
	glLinkProgram(program);

	GLint link_status = -1;
	glGetProgramiv(program, GL_LINK_STATUS, &link_status);
	if(link_status == GL_FALSE)
	{
		GLchar message[1024];
		glGetProgramInfoLog(program, sizeof(message), 0, &message[0]);
		std::cout << "[ERRRO " << __LINE__ << " ]: " << vertex_shader_path << "::" << fragment_shader_path << std::endl;
		std::cout << message << std::endl;
	}


	#ifdef DEBUG_BUILD
	std::cout << "Loaded the shader " << vertex_shader_path << "::" << fragment_shader_path << " -> " << program << std::endl;
	#endif

	return program;
}

GLuint compile_shader_program(std::string path, GLenum type)
{
	int file_sz = get_filesize(path);

	char *mem = (char *)malloc(sizeof(char) * file_sz);
	std::ifstream in(path, std::ios::binary);
	in.read(mem, file_sz);
	in.close();

	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, (const GLchar **)&mem, &file_sz);
	glCompileShader(shader);

	GLint compile_status = GL_TRUE;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_status);
	if(compile_status == GL_FALSE)
	{
		GLchar message[1024];
		glGetShaderInfoLog(shader, sizeof(message), 0, &message[0]);
		std::cerr << "[ERROR " << __LINE__ << "]: (" << path << "): " << std::endl << message << std::endl;
		return 0;
	}

	return shader;
}

std::ifstream::pos_type get_filesize(std::string filename)
{
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	if(!in)
	{
		return -2;
	}
	return in.tellg();
}
