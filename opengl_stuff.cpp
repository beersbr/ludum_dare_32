#include "opengl_stuff.h"

bool intersectPlane(const glm::vec3 &n, const glm::vec3 &p0, const glm::vec3& l0, const glm::vec3 &l, float &t)
{
	// assuming vectors are all normalized
	float denom = glm::dot(n, l);
	if (denom > 1e-6) {
		glm::vec3 p0l0 = p0 - l0;
		t = glm::dot(p0l0, n) / denom;
		return (t >= 0);
	}
	return false;
}

glm::vec3 intersectionPlanePoint(const glm::vec3 &n, const glm::vec3 &p0, const glm::vec3 &l0, const glm::vec3 &l)
{
	float t = 0;
	if(intersectPlane(n, p0, l0, l, t))
	{	
		glm::vec3 newL = l * t;
		float d = glm::length(newL);

		#ifdef DEBUG_BUILD
		std::cout << "NEW L " << newL.x << ", " << newL.y << ", " << newL.z << std::endl;
		std::cout << "MAGNITUDE: " << d << std::endl;
		std::cout << l0.x << ", " << l0.y << ", " << l0.z << std::endl;
		#endif

		return (l0 + newL);
	}
	return ZERO;
}

void prefab_diamond(Mesh *m, glm::vec3 p, glm::vec3 r, glm::vec3 s, GLuint *shader_id)
{
	m->vertice_sz = 0;
	// front top
	m->vertices[m->vertice_sz].position   = glm::vec3( 0.0f,  0.5f,  0.0f);
	m->vertices[m->vertice_sz].color = YELLOW; 
	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.0f,  0.5f);
	m->vertices[m->vertice_sz].color = YELLOW;
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.0f,  0.5f);
	m->vertices[m->vertice_sz].color = YELLOW;

	glm::vec3 a = m->vertices[m->vertice_sz-1].position - m->vertices[m->vertice_sz-2].position;
	glm::vec3 b = m->vertices[m->vertice_sz-0].position - m->vertices[m->vertice_sz-2].position;
	glm::vec3 c = glm::normalize(glm::cross(a, b));

	m->vertices[m->vertice_sz-2].normal = c;
	m->vertices[m->vertice_sz-1].normal = c;
	m->vertices[m->vertice_sz-0].normal = c;

	// right top 
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f,  0.5f,  0.0f);
	m->vertices[m->vertice_sz].color = YELLOW;
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.0f,  0.5f);
	m->vertices[m->vertice_sz].color = YELLOW;
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.0f, -0.5f);
	m->vertices[m->vertice_sz].color = YELLOW;

	a = m->vertices[m->vertice_sz-1].position - m->vertices[m->vertice_sz-2].position;
	b = m->vertices[m->vertice_sz-0].position - m->vertices[m->vertice_sz-2].position;
	c = glm::normalize(glm::cross(a, b));

	m->vertices[m->vertice_sz-2].normal = c;
	m->vertices[m->vertice_sz-1].normal = c;
	m->vertices[m->vertice_sz-0].normal = c;

	// back top
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f,  0.5f,  0.0f);
	m->vertices[m->vertice_sz].color = YELLOW; 
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.0f, -0.5f);
	m->vertices[m->vertice_sz].color = YELLOW; 
	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.0f, -0.5f);
	m->vertices[m->vertice_sz].color = YELLOW; 

	a = m->vertices[m->vertice_sz-1].position - m->vertices[m->vertice_sz-2].position;
	b = m->vertices[m->vertice_sz-0].position - m->vertices[m->vertice_sz-2].position;
	c = glm::normalize(glm::cross(a, b));

	m->vertices[m->vertice_sz-2].normal = c;
	m->vertices[m->vertice_sz-1].normal = c;
	m->vertices[m->vertice_sz-0].normal = c;

	// left top
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f,  0.5f,  0.0f);
	m->vertices[m->vertice_sz].color = YELLOW; 
	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.0f, -0.5f);
	m->vertices[m->vertice_sz].color = YELLOW; 
	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.0f,  0.5f);
	m->vertices[m->vertice_sz].color = YELLOW; 

	a = m->vertices[m->vertice_sz-1].position - m->vertices[m->vertice_sz-2].position;
	b = m->vertices[m->vertice_sz-0].position - m->vertices[m->vertice_sz-2].position;
	c = glm::normalize(glm::cross(a, b));

	m->vertices[m->vertice_sz-2].normal = c;
	m->vertices[m->vertice_sz-1].normal = c;
	m->vertices[m->vertice_sz-0].normal = c;

	// front bottom
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f, -0.5f,  0.0f);
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.0f,  0.5f);
	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.0f,  0.5f);

	a = m->vertices[m->vertice_sz-1].position - m->vertices[m->vertice_sz-2].position;
	b = m->vertices[m->vertice_sz-0].position - m->vertices[m->vertice_sz-2].position;
	c = glm::normalize(glm::cross(a, b));

	m->vertices[m->vertice_sz-2].normal = c;
	m->vertices[m->vertice_sz-1].normal = c;
	m->vertices[m->vertice_sz-0].normal = c;

	// right bottom
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f, -0.5f,  0.0f);
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.0f, -0.5f);
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.0f,  0.5f);

	a = m->vertices[m->vertice_sz-1].position - m->vertices[m->vertice_sz-2].position;
	b = m->vertices[m->vertice_sz-0].position - m->vertices[m->vertice_sz-2].position;
	c = glm::normalize(glm::cross(a, b));

	m->vertices[m->vertice_sz-2].normal = c;
	m->vertices[m->vertice_sz-1].normal = c;
	m->vertices[m->vertice_sz-0].normal = c;

	// back bottom
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f, -0.5f,  0.0f);
	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.0f, -0.5f);
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.0f, -0.5f);

	a = m->vertices[m->vertice_sz-1].position - m->vertices[m->vertice_sz-2].position;
	b = m->vertices[m->vertice_sz-0].position - m->vertices[m->vertice_sz-2].position;
	c = glm::normalize(glm::cross(a, b));

	m->vertices[m->vertice_sz-2].normal = c;
	m->vertices[m->vertice_sz-1].normal = c;
	m->vertices[m->vertice_sz-0].normal = c;

	// left bottom
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f, -0.5f,  0.0f);
	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.0f,  0.5f);
	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.0f, -0.5f);


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


void prefab_pyramid(Mesh *m, glm::vec3 p, glm::vec3 r, glm::vec3 s, GLuint *shader_id)
{
	m->vertice_sz = 0;

	// front face
	m->vertices[m->vertice_sz].position   = glm::vec3( 0.0f,  0.5f,  0.0f);
	m->vertices[m->vertice_sz].color = WHITE;
	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f,  0.5f);
	m->vertices[m->vertice_sz].color = WHITE;
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f,  0.5f);
	m->vertices[m->vertice_sz].color = WHITE;

	// right face
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f,  0.5f,  0.0f);
	m->vertices[m->vertice_sz].color = BLUE;
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f,  0.5f);
	m->vertices[m->vertice_sz].color = BLUE;
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f, -0.5f);
	m->vertices[m->vertice_sz].color = BLUE;

	// back face
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f,  0.5f,  0.0f);
	m->vertices[m->vertice_sz].color = RED;
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f, -0.5f);
	m->vertices[m->vertice_sz].color = RED;
	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f, -0.5f);
	m->vertices[m->vertice_sz].color = RED;

	// left face
	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f,  0.5f,  0.0f);
	m->vertices[m->vertice_sz].color = CYAN;
	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f, -0.5f);
	m->vertices[m->vertice_sz].color = CYAN;
	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f,  0.5f);
	m->vertices[m->vertice_sz].color = CYAN;

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
		// glBindVertexArray(m->VAO);
		// CurrentVertexArray = m->VAO;
		glBindBuffer(GL_ARRAY_BUFFER, m->VBO);
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
