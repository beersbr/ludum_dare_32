#include "opengl_stuff.h"

std::ostream& operator << (std::ostream& os, const glm::vec3& v)
{
	os << "( " << v.x << ", " << v.y << ", " << v.z << " )";
	return os;
}

// void prefab_diamond(Mesh *m, glm::vec3 p, glm::vec3 r, glm::vec3 s, GLuint *shader_id)
// {
// 	m->vertice_sz = 0;
// 	// front top
// 	m->vertices[m->vertice_sz].position   = glm::vec3( 0.0f,  0.5f,  0.0f);
// 	m->vertices[m->vertice_sz].color = YELLOW; 
// 	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.0f,  0.5f);
// 	m->vertices[m->vertice_sz].color = YELLOW;
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.0f,  0.5f);
// 	m->vertices[m->vertice_sz].color = YELLOW;

// 	glm::vec3 a = m->vertices[m->vertice_sz-1].position - m->vertices[m->vertice_sz-2].position;
// 	glm::vec3 b = m->vertices[m->vertice_sz-0].position - m->vertices[m->vertice_sz-2].position;
// 	glm::vec3 c = glm::normalize(glm::cross(a, b));

// 	m->vertices[m->vertice_sz-2].normal = c;
// 	m->vertices[m->vertice_sz-1].normal = c;
// 	m->vertices[m->vertice_sz-0].normal = c;

// 	// right top 
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f,  0.5f,  0.0f);
// 	m->vertices[m->vertice_sz].color = YELLOW;
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.0f,  0.5f);
// 	m->vertices[m->vertice_sz].color = YELLOW;
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.0f, -0.5f);
// 	m->vertices[m->vertice_sz].color = YELLOW;

// 	a = m->vertices[m->vertice_sz-1].position - m->vertices[m->vertice_sz-2].position;
// 	b = m->vertices[m->vertice_sz-0].position - m->vertices[m->vertice_sz-2].position;
// 	c = glm::normalize(glm::cross(a, b));

// 	m->vertices[m->vertice_sz-2].normal = c;
// 	m->vertices[m->vertice_sz-1].normal = c;
// 	m->vertices[m->vertice_sz-0].normal = c;

// 	// back top
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f,  0.5f,  0.0f);
// 	m->vertices[m->vertice_sz].color = YELLOW; 
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.0f, -0.5f);
// 	m->vertices[m->vertice_sz].color = YELLOW; 
// 	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.0f, -0.5f);
// 	m->vertices[m->vertice_sz].color = YELLOW; 

// 	a = m->vertices[m->vertice_sz-1].position - m->vertices[m->vertice_sz-2].position;
// 	b = m->vertices[m->vertice_sz-0].position - m->vertices[m->vertice_sz-2].position;
// 	c = glm::normalize(glm::cross(a, b));

// 	m->vertices[m->vertice_sz-2].normal = c;
// 	m->vertices[m->vertice_sz-1].normal = c;
// 	m->vertices[m->vertice_sz-0].normal = c;

// 	// left top
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f,  0.5f,  0.0f);
// 	m->vertices[m->vertice_sz].color = YELLOW; 
// 	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.0f, -0.5f);
// 	m->vertices[m->vertice_sz].color = YELLOW; 
// 	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.0f,  0.5f);
// 	m->vertices[m->vertice_sz].color = YELLOW; 

// 	a = m->vertices[m->vertice_sz-1].position - m->vertices[m->vertice_sz-2].position;
// 	b = m->vertices[m->vertice_sz-0].position - m->vertices[m->vertice_sz-2].position;
// 	c = glm::normalize(glm::cross(a, b));

// 	m->vertices[m->vertice_sz-2].normal = c;
// 	m->vertices[m->vertice_sz-1].normal = c;
// 	m->vertices[m->vertice_sz-0].normal = c;

// 	// front bottom
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f, -0.5f,  0.0f);
// 	m->vertices[m->vertice_sz].color = PINK;
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.0f,  0.5f);
// 	m->vertices[m->vertice_sz].color = PINK;
// 	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.0f,  0.5f);
// 	m->vertices[m->vertice_sz].color = PINK;

// 	a = m->vertices[m->vertice_sz-1].position - m->vertices[m->vertice_sz-2].position;
// 	b = m->vertices[m->vertice_sz-0].position - m->vertices[m->vertice_sz-2].position;
// 	c = glm::normalize(glm::cross(a, b));

// 	m->vertices[m->vertice_sz-2].normal = c;
// 	m->vertices[m->vertice_sz-1].normal = c;
// 	m->vertices[m->vertice_sz-0].normal = c;

// 	// right bottom
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f, -0.5f,  0.0f);
// 	m->vertices[m->vertice_sz].color = PINK;
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.0f, -0.5f);
// 	m->vertices[m->vertice_sz].color = PINK;
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.0f,  0.5f);
// 	m->vertices[m->vertice_sz].color = PINK;

// 	a = m->vertices[m->vertice_sz-1].position - m->vertices[m->vertice_sz-2].position;
// 	b = m->vertices[m->vertice_sz-0].position - m->vertices[m->vertice_sz-2].position;
// 	c = glm::normalize(glm::cross(a, b));

// 	m->vertices[m->vertice_sz-2].normal = c;
// 	m->vertices[m->vertice_sz-1].normal = c;
// 	m->vertices[m->vertice_sz-0].normal = c;

// 	// back bottom
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f, -0.5f,  0.0f);
// 	m->vertices[m->vertice_sz].color = PINK;
// 	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.0f, -0.5f);
// 	m->vertices[m->vertice_sz].color = PINK;
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f,  0.0f, -0.5f);
// 	m->vertices[m->vertice_sz].color = PINK;

// 	a = m->vertices[m->vertice_sz-1].position - m->vertices[m->vertice_sz-2].position;
// 	b = m->vertices[m->vertice_sz-0].position - m->vertices[m->vertice_sz-2].position;
// 	c = glm::normalize(glm::cross(a, b));

// 	m->vertices[m->vertice_sz-2].normal = c;
// 	m->vertices[m->vertice_sz-1].normal = c;
// 	m->vertices[m->vertice_sz-0].normal = c;

// 	// left bottom
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f, -0.5f,  0.0f);
// 	m->vertices[m->vertice_sz].color = PINK;
// 	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.0f,  0.5f);
// 	m->vertices[m->vertice_sz].color = PINK;
// 	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f,  0.0f, -0.5f);
// 	m->vertices[m->vertice_sz].color = PINK;

// 	a = m->vertices[m->vertice_sz-1].position - m->vertices[m->vertice_sz-2].position;
// 	b = m->vertices[m->vertice_sz-0].position - m->vertices[m->vertice_sz-2].position;
// 	c = glm::normalize(glm::cross(a, b));

// 	m->vertices[m->vertice_sz-2].normal = c;
// 	m->vertices[m->vertice_sz-1].normal = c;
// 	m->vertices[m->vertice_sz-0].normal = c;

// 	m->vertice_sz += 1;

// 	m->position = p;
// 	m->rotation = r;
// 	m->scale = s;
// 	m->shader_id = shader_id;

// 	// GLuint VAO;
// 	glGenVertexArrays(1, &m->VAO);
// 	glBindVertexArray(m->VAO);

// 	CurrentVertexArray = m->VAO;

// 	// GLuint VBO;
// 	glGenBuffers(1, &m->VBO);
// 	glBindBuffer(GL_ARRAY_BUFFER, m->VBO);

// 	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*m->vertice_sz, (GLfloat *)&m->vertices[0], GL_STREAM_DRAW);
// 	glEnableVertexAttribArray(0);
// 	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, position)));
// 	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, normal)));
// 	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, color)));

// 	glEnableVertexAttribArray(0);
// 	glEnableVertexAttribArray(1);
// 	glEnableVertexAttribArray(2);
// }


// void prefab_pyramid(Mesh *m, glm::vec3 p, glm::vec3 r, glm::vec3 s, GLuint *shader_id)
// {
// 	m->vertice_sz = 0;

// 	// front face
// 	m->vertices[m->vertice_sz].position   = glm::vec3( 0.0f,  0.5f,  0.0f);
// 	m->vertices[m->vertice_sz].color = WHITE;
// 	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f,  0.5f);
// 	m->vertices[m->vertice_sz].color = WHITE;
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f,  0.5f);
// 	m->vertices[m->vertice_sz].color = WHITE;

// 	// right face
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f,  0.5f,  0.0f);
// 	m->vertices[m->vertice_sz].color = BLUE;
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f,  0.5f);
// 	m->vertices[m->vertice_sz].color = BLUE;
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f, -0.5f);
// 	m->vertices[m->vertice_sz].color = BLUE;

// 	// back face
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f,  0.5f,  0.0f);
// 	m->vertices[m->vertice_sz].color = RED;
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f, -0.5f);
// 	m->vertices[m->vertice_sz].color = RED;
// 	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f, -0.5f);
// 	m->vertices[m->vertice_sz].color = RED;

// 	// left face
// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.0f,  0.5f,  0.0f);
// 	m->vertices[m->vertice_sz].color = CYAN;
// 	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f, -0.5f);
// 	m->vertices[m->vertice_sz].color = CYAN;
// 	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f,  0.5f);
// 	m->vertices[m->vertice_sz].color = CYAN;

// 	// bottom face
// 	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f, -0.5f);
// 	m->vertices[m->vertice_sz].normal = NY;
// 	m->vertices[m->vertice_sz].color = BLACK;

// 	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f,  0.5f);
// 	m->vertices[m->vertice_sz].normal = NY;
// 	m->vertices[m->vertice_sz].color = BLACK;

// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f, -0.5f);
// 	m->vertices[m->vertice_sz].normal = NY;
// 	m->vertices[m->vertice_sz].color = BLACK;

// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f, -0.5f);
// 	m->vertices[m->vertice_sz].normal = NY;
// 	m->vertices[m->vertice_sz].color = BLACK;

// 	m->vertices[++m->vertice_sz].position = glm::vec3(-0.5f, -0.5f,  0.5f);
// 	m->vertices[m->vertice_sz].normal = NY;
// 	m->vertices[m->vertice_sz].color = BLACK;

// 	m->vertices[++m->vertice_sz].position = glm::vec3( 0.5f, -0.5f,  0.5f);
// 	m->vertices[m->vertice_sz].normal = NY;
// 	m->vertices[m->vertice_sz].color = BLACK;
// 	m->vertice_sz += 1;

// 	m->position = p;
// 	m->rotation = r;
// 	m->scale = s;
// 	m->shader_id = shader_id;

// 	// GLuint VAO;
// 	glGenVertexArrays(1, &m->VAO);
// 	glBindVertexArray(m->VAO);

// 	CurrentVertexArray = m->VAO;

// 	// GLuint VBO;
// 	glGenBuffers(1, &m->VBO);
// 	glBindBuffer(GL_ARRAY_BUFFER, m->VBO);

// 	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*m->vertice_sz, (GLfloat *)&m->vertices[0], GL_STREAM_DRAW);
// 	glEnableVertexAttribArray(0);
// 	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, position)));
// 	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, normal)));
// 	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, color)));

// 	glEnableVertexAttribArray(0);
// 	glEnableVertexAttribArray(1);
// 	glEnableVertexAttribArray(2);
// }

void custom_mesh(Mesh *m, std::vector<Vertex> *verts, GLenum method, Shader *shader)
{
	m->shader = shader;
	m->draw_method = method;

	m->vertices = *verts;

	glGenVertexArrays(1, &m->VAO);
	glBindVertexArray(m->VAO);

	glGenBuffers(1, &m->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m->VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*m->vertices.size(), (GLfloat *)&m->vertices[0], GL_STREAM_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, position)));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, normal)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, color)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
}

void prefab_cube(Mesh *m, Shader *shader)
{
	m->shader = shader;

	// front face
	m->vertices.push_back({ glm::vec3(-0.5f,  0.5f, -0.5f), NZ, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3(-0.5f, -0.5f, -0.5f), NZ, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3( 0.5f,  0.5f, -0.5f), NZ, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3( 0.5f,  0.5f, -0.5f), NZ, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3(-0.5f, -0.5f, -0.5f), NZ, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3( 0.5f, -0.5f, -0.5f), NZ, WHITE, glm::vec2(0.f, 0.f) });
	
	// right face
	m->vertices.push_back({ glm::vec3( 0.5f,  0.5f, -0.5f), PX, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3( 0.5f, -0.5f, -0.5f), PX, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3( 0.5f,  0.5f,  0.5f), PX, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3( 0.5f,  0.5f,  0.5f), PX, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3( 0.5f, -0.5f, -0.5f), PX, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3( 0.5f, -0.5f,  0.5f), PX, WHITE, glm::vec2(0.f, 0.f) });

	// back face
	m->vertices.push_back({ glm::vec3( 0.5f,  0.5f,  0.5f), PZ, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3( 0.5f, -0.5f,  0.5f), PZ, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3(-0.5f,  0.5f,  0.5f), PZ, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3(-0.5f,  0.5f,  0.5f), PZ, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3( 0.5f, -0.5f,  0.5f), PZ, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3(-0.5f, -0.5f,  0.5f), PZ, WHITE, glm::vec2(0.f, 0.f) });

	// left face
	m->vertices.push_back({ glm::vec3(-0.5f,  0.5f,  0.5f), NX, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3(-0.5f, -0.5f,  0.5f), NX, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3(-0.5f,  0.5f, -0.5f), NX, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3(-0.5f,  0.5f, -0.5f), NX, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3(-0.5f, -0.5f,  0.5f), NX, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3(-0.5f, -0.5f, -0.5f), NX, WHITE, glm::vec2(0.f, 0.f) });

	// top face
	m->vertices.push_back({ glm::vec3(-0.5f,  0.5f,  0.5f), PY, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3(-0.5f,  0.5f, -0.5f), PY, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3( 0.5f,  0.5f,  0.5f), PY, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3( 0.5f,  0.5f,  0.5f), PY, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3(-0.5f,  0.5f, -0.5f), PY, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3( 0.5f,  0.5f, -0.5f), PY, WHITE, glm::vec2(0.f, 0.f) });

	// bottom face
	m->vertices.push_back({ glm::vec3(-0.5f, -0.5f, -0.5f), NY, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3(-0.5f, -0.5f,  0.5f), NY, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3( 0.5f, -0.5f, -0.5f), NY, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3( 0.5f, -0.5f, -0.5f), NY, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3(-0.5f, -0.5f,  0.5f), NY, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ glm::vec3( 0.5f, -0.5f,  0.5f), NY, WHITE, glm::vec2(0.f, 0.f) });

	m->draw_method = GL_TRIANGLES;

	glGenVertexArrays(1, &m->VAO);
	glBindVertexArray(m->VAO);

	glGenBuffers(1, &m->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m->VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*m->vertices.size(), (GLfloat *)&m->vertices[0], GL_STREAM_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, position)));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, normal)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, color)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
}

void prefab_diamond(Mesh *m, Shader *shader)
{
	m->shader = shader;
	m->draw_method = GL_TRIANGLES;

	// generate diamond with size of 1
	
	glm::vec3 zero = ZERO;

	// around the diamon
	glm::vec3 A = glm::vec3( -1.0f,  0.0f, -1.0f );
	glm::vec3 B = glm::vec3(  1.0f,  0.0f, -1.0f );
	glm::vec3 C = glm::vec3(  1.0f,  0.0f,  1.0f );
	glm::vec3 D = glm::vec3( -1.0f,  0.0f,  1.0f );

	// top and bottom
	glm::vec3 E = glm::vec3(  0.0f,  1.0f,  0.0f );
	glm::vec3 F = glm::vec3(  0.0f, -1.0f,  0.0f );

	/*
               E
		  D _______  C
	      /        /
		 /        /
		/_______ /
      A          B 
		    F
	*/

	// face top front
	m->vertices.push_back({ E, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ A, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ B, ZERO, WHITE, glm::vec2(0.f, 0.f) });

	std::cout << "Size of vector: " << m->vertices.size() << std::endl;
	std::cout << "vector 0: " << m->vertices[0].position.x << ", " << m->vertices[0].position.y << ", " << m->vertices[0].position.z << std::endl;
	std::cout << "vector 1: " << m->vertices[1].position.x << ", " << m->vertices[1].position.y << ", " << m->vertices[1].position.z << std::endl;
	std::cout << "vector 2: " << m->vertices[2].position.x << ", " << m->vertices[2].position.y << ", " << m->vertices[2].position.z << std::endl;

	glm::vec3 a = m->vertices[m->vertices.size()-2].position - m->vertices[m->vertices.size()-3].position;
	glm::vec3 b = m->vertices[m->vertices.size()-1].position - m->vertices[m->vertices.size()-3].position;
	glm::vec3 c = -glm::normalize(glm::cross(a, b));

	std::cout << "NORMAL: " << c.x << ", " << c.y << ", " << c.z << std::endl;

	m->vertices[m->vertices.size()-3].normal = c;
	m->vertices[m->vertices.size()-2].normal = c;
	m->vertices[m->vertices.size()-1].normal = c;

	// face top right
	m->vertices.push_back({ E, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ B, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ C, ZERO, WHITE, glm::vec2(0.f, 0.f) });

	a = m->vertices[m->vertices.size()-2].position - m->vertices[m->vertices.size()-3].position;
	b = m->vertices[m->vertices.size()-1].position - m->vertices[m->vertices.size()-3].position;
	c = -glm::normalize(glm::cross(a, b));

	m->vertices[m->vertices.size()-3].normal = c;
	m->vertices[m->vertices.size()-2].normal = c;
	m->vertices[m->vertices.size()-1].normal = c;

	// face top back
	m->vertices.push_back({ E, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ C, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ D, ZERO, WHITE, glm::vec2(0.f, 0.f) });

	a = m->vertices[m->vertices.size()-2].position - m->vertices[m->vertices.size()-3].position;
	b = m->vertices[m->vertices.size()-1].position - m->vertices[m->vertices.size()-3].position;
	c = -glm::normalize(glm::cross(a, b));

	m->vertices[m->vertices.size()-3].normal = c;
	m->vertices[m->vertices.size()-2].normal = c;
	m->vertices[m->vertices.size()-1].normal = c;

	// face top left
	m->vertices.push_back({ E, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ D, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ A, ZERO, WHITE, glm::vec2(0.f, 0.f) });

	a = m->vertices[m->vertices.size()-2].position - m->vertices[m->vertices.size()-3].position;
	b = m->vertices[m->vertices.size()-1].position - m->vertices[m->vertices.size()-3].position;
	c = -glm::normalize(glm::cross(a, b));

	m->vertices[m->vertices.size()-3].normal = c;
	m->vertices[m->vertices.size()-2].normal = c;
	m->vertices[m->vertices.size()-1].normal = c;

	// face bottom front
	m->vertices.push_back({ F, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ B, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ A, ZERO, WHITE, glm::vec2(0.f, 0.f) });

	a = m->vertices[m->vertices.size()-2].position - m->vertices[m->vertices.size()-3].position;
	b = m->vertices[m->vertices.size()-1].position - m->vertices[m->vertices.size()-3].position;
	c = -glm::normalize(glm::cross(a, b));

	m->vertices[m->vertices.size()-3].normal = c;
	m->vertices[m->vertices.size()-2].normal = c;
	m->vertices[m->vertices.size()-1].normal = c;

	// face bottom right
	m->vertices.push_back({ F, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ C, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ B, ZERO, WHITE, glm::vec2(0.f, 0.f) });

	a = m->vertices[m->vertices.size()-2].position - m->vertices[m->vertices.size()-3].position;
	b = m->vertices[m->vertices.size()-1].position - m->vertices[m->vertices.size()-3].position;
	c = -glm::normalize(glm::cross(a, b));

	m->vertices[m->vertices.size()-3].normal = c;
	m->vertices[m->vertices.size()-2].normal = c;
	m->vertices[m->vertices.size()-1].normal = c;

	// face bottom back
	m->vertices.push_back({ F, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ D, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ C, ZERO, WHITE, glm::vec2(0.f, 0.f) });

	a = m->vertices[m->vertices.size()-2].position - m->vertices[m->vertices.size()-3].position;
	b = m->vertices[m->vertices.size()-1].position - m->vertices[m->vertices.size()-3].position;
	c = -glm::normalize(glm::cross(a, b));

	m->vertices[m->vertices.size()-3].normal = c;
	m->vertices[m->vertices.size()-2].normal = c;
	m->vertices[m->vertices.size()-1].normal = c;

	// face bottom back
	m->vertices.push_back({ F, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ A, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	m->vertices.push_back({ D, ZERO, WHITE, glm::vec2(0.f, 0.f) });

	a = m->vertices[m->vertices.size()-2].position - m->vertices[m->vertices.size()-3].position;
	b = m->vertices[m->vertices.size()-1].position - m->vertices[m->vertices.size()-3].position;
	c = -glm::normalize(glm::cross(a, b));

	m->vertices[m->vertices.size()-3].normal = c;
	m->vertices[m->vertices.size()-2].normal = c;
	m->vertices[m->vertices.size()-1].normal = c;

	glGenVertexArrays(1, &m->VAO);
	glBindVertexArray(m->VAO);

	glGenBuffers(1, &m->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m->VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*m->vertices.size(), (GLfloat *)&m->vertices[0], GL_STREAM_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, position)));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, normal)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, color)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

}

void prefab_sphere(Mesh *m, Shader *shader)
{
	m->shader = shader;
	m->draw_method = GL_TRIANGLES;

	// generate diamond with size of 1
	
	glm::vec3 CENTER = ZERO;

	// around the diamon
	glm::vec3 A = glm::vec3( -1.0f,  0.0f, -1.0f );
	glm::vec3 B = glm::vec3(  1.0f,  0.0f, -1.0f );
	glm::vec3 C = glm::vec3(  1.0f,  0.0f,  1.0f );
	glm::vec3 D = glm::vec3( -1.0f,  0.0f,  1.0f );

	// top and bottom
	glm::vec3 E = glm::vec3(  0.0f,  1.0f,  0.0f );
	glm::vec3 F = glm::vec3(  0.0f, -1.0f,  0.0f );

	float radius = glm::distance(A-CENTER, CENTER);

	std::cout << "RADIUS: " << radius << std::endl;
	radius = 0.5f;

	// each element will have 3 vectors forming a triangle
	std::vector<std::vector<glm::vec3> > triangles;

	// top
	triangles.push_back({ E, A, B });
	triangles.push_back({ E, B, C });
	triangles.push_back({ E, C, D });
	triangles.push_back({ E, D, A });

	// bottom
	triangles.push_back({ F, A, B });
	triangles.push_back({ F, A, B });
	triangles.push_back({ F, A, B });
	triangles.push_back({ F, A, B });

	for(auto i = triangles.begin(); i < triangles.end(); ++i)
	{
		std::vector<glm::vec3> sub_divided = subdivide_triangle((*i)[0], (*i)[1], (*i)[2]);

	}

	/*
               E
		  D _______  C
	      /        /
		 /        /
		/_______ /
      A          B 
		    F
	*/

	int subs = 4;

	// top back face sub divided triangles
	std::vector<glm::vec3> triangle = {E, A, B};
	std::vector<glm::vec3> tries = sub_triangles(triangle, subs);
	for(auto i = tries.begin(); i != tries.end(); i += 3)
	{
		glm::vec3 vA = (*i);
		glm::vec3 vB = (*(i+1));
		glm::vec3 vC = (*(i+2));

		glm::vec3 normal_A = glm::normalize(vA - CENTER);
		glm::vec3 normal_B = glm::normalize(vB - CENTER);
		glm::vec3 normal_C = glm::normalize(vC - CENTER);

		glm::vec3 real_A = CENTER + (normal_A * radius);
		glm::vec3 real_B = CENTER + (normal_B * radius);
		glm::vec3 real_C = CENTER + (normal_C * radius);

		m->vertices.push_back({ real_A, normal_A, WHITE, glm::vec2(0.f, 0.f) });
		m->vertices.push_back({ real_B, normal_B, WHITE, glm::vec2(0.f, 0.f) });
		m->vertices.push_back({ real_C, normal_C, WHITE, glm::vec2(0.f, 0.f) });

		std::cout << std::endl;
	}


	// top right face sub divided triangles
	triangle = {E, B, C};
	tries = sub_triangles(triangle, subs);
	for(auto i = tries.begin(); i != tries.end(); i += 3)
	{
		glm::vec3 vA = (*i);
		glm::vec3 vB = (*(i+1));
		glm::vec3 vC = (*(i+2));

		glm::vec3 normal_A = glm::normalize(vA - CENTER);
		glm::vec3 normal_B = glm::normalize(vB - CENTER);
		glm::vec3 normal_C = glm::normalize(vC - CENTER);

		glm::vec3 real_A = CENTER + (normal_A * radius);
		glm::vec3 real_B = CENTER + (normal_B * radius);
		glm::vec3 real_C = CENTER + (normal_C * radius);

		m->vertices.push_back({ real_A, normal_A, WHITE, glm::vec2(0.f, 0.f) });
		m->vertices.push_back({ real_B, normal_B, WHITE, glm::vec2(0.f, 0.f) });
		m->vertices.push_back({ real_C, normal_C, WHITE, glm::vec2(0.f, 0.f) });
	}

	// top front
	triangle = {E, C, D};
	tries = sub_triangles(triangle, subs);
	for(auto i = tries.begin(); i != tries.end(); i += 3)
	{
		glm::vec3 vA = (*i);
		glm::vec3 vB = (*(i+1));
		glm::vec3 vC = (*(i+2));

		glm::vec3 normal_A = glm::normalize(vA - CENTER);
		glm::vec3 normal_B = glm::normalize(vB - CENTER);
		glm::vec3 normal_C = glm::normalize(vC - CENTER);

		glm::vec3 real_A = CENTER + (normal_A * radius);
		glm::vec3 real_B = CENTER + (normal_B * radius);
		glm::vec3 real_C = CENTER + (normal_C * radius);

		m->vertices.push_back({ real_A, normal_A, WHITE, glm::vec2(0.f, 0.f) });
		m->vertices.push_back({ real_B, normal_B, WHITE, glm::vec2(0.f, 0.f) });
		m->vertices.push_back({ real_C, normal_C, WHITE, glm::vec2(0.f, 0.f) });
	}

	// top left
	triangle = {E, D, A};
	tries = sub_triangles(triangle, subs);
	for(auto i = tries.begin(); i != tries.end(); i += 3)
	{
		glm::vec3 vA = (*i);
		glm::vec3 vB = (*(i+1));
		glm::vec3 vC = (*(i+2));

		glm::vec3 normal_A = glm::normalize(vA - CENTER);
		glm::vec3 normal_B = glm::normalize(vB - CENTER);
		glm::vec3 normal_C = glm::normalize(vC - CENTER);

		glm::vec3 real_A = CENTER + (normal_A * radius);
		glm::vec3 real_B = CENTER + (normal_B * radius);
		glm::vec3 real_C = CENTER + (normal_C * radius);

		m->vertices.push_back({ real_A, normal_A, WHITE, glm::vec2(0.f, 0.f) });
		m->vertices.push_back({ real_B, normal_B, WHITE, glm::vec2(0.f, 0.f) });
		m->vertices.push_back({ real_C, normal_C, WHITE, glm::vec2(0.f, 0.f) });
	}

	// bottom back
	triangle = {F, A, B};
	tries = sub_triangles(triangle, subs);
	for(auto i = tries.begin(); i != tries.end(); i += 3)
	{
		glm::vec3 vA = (*i);
		glm::vec3 vB = (*(i+1));
		glm::vec3 vC = (*(i+2));

		glm::vec3 normal_A = glm::normalize(vA - CENTER);
		glm::vec3 normal_B = glm::normalize(vB - CENTER);
		glm::vec3 normal_C = glm::normalize(vC - CENTER);

		glm::vec3 real_A = CENTER + (normal_A * radius);
		glm::vec3 real_B = CENTER + (normal_B * radius);
		glm::vec3 real_C = CENTER + (normal_C * radius);

		m->vertices.push_back({ real_A, normal_A, WHITE, glm::vec2(0.f, 0.f) });
		m->vertices.push_back({ real_B, normal_B, WHITE, glm::vec2(0.f, 0.f) });
		m->vertices.push_back({ real_C, normal_C, WHITE, glm::vec2(0.f, 0.f) });

		std::cout << std::endl;
	}

	// bottom right
	triangle = {F, B, C};
	tries = sub_triangles(triangle, subs);
	for(auto i = tries.begin(); i != tries.end(); i += 3)
	{
		glm::vec3 vA = (*i);
		glm::vec3 vB = (*(i+1));
		glm::vec3 vC = (*(i+2));

		glm::vec3 normal_A = glm::normalize(vA - CENTER);
		glm::vec3 normal_B = glm::normalize(vB - CENTER);
		glm::vec3 normal_C = glm::normalize(vC - CENTER);

		glm::vec3 real_A = CENTER + (normal_A * radius);
		glm::vec3 real_B = CENTER + (normal_B * radius);
		glm::vec3 real_C = CENTER + (normal_C * radius);

		m->vertices.push_back({ real_A, normal_A, WHITE, glm::vec2(0.f, 0.f) });
		m->vertices.push_back({ real_B, normal_B, WHITE, glm::vec2(0.f, 0.f) });
		m->vertices.push_back({ real_C, normal_C, WHITE, glm::vec2(0.f, 0.f) });
	}

	// bottom front
	triangle = {F, C, D};
	tries = sub_triangles(triangle, subs);
	for(auto i = tries.begin(); i != tries.end(); i += 3)
	{
		glm::vec3 vA = (*i);
		glm::vec3 vB = (*(i+1));
		glm::vec3 vC = (*(i+2));

		glm::vec3 normal_A = glm::normalize(vA - CENTER);
		glm::vec3 normal_B = glm::normalize(vB - CENTER);
		glm::vec3 normal_C = glm::normalize(vC - CENTER);

		glm::vec3 real_A = CENTER + (normal_A * radius);
		glm::vec3 real_B = CENTER + (normal_B * radius);
		glm::vec3 real_C = CENTER + (normal_C * radius);

		m->vertices.push_back({ real_A, normal_A, WHITE, glm::vec2(0.f, 0.f) });
		m->vertices.push_back({ real_B, normal_B, WHITE, glm::vec2(0.f, 0.f) });
		m->vertices.push_back({ real_C, normal_C, WHITE, glm::vec2(0.f, 0.f) });
	}

	// bottom left
	triangle = {F, D, A};
	tries = sub_triangles(triangle, subs);
	for(auto i = tries.begin(); i != tries.end(); i += 3)
	{
		glm::vec3 vA = (*i);
		glm::vec3 vB = (*(i+1));
		glm::vec3 vC = (*(i+2));

		glm::vec3 normal_A = glm::normalize(vA - CENTER);
		glm::vec3 normal_B = glm::normalize(vB - CENTER);
		glm::vec3 normal_C = glm::normalize(vC - CENTER);

		glm::vec3 real_A = CENTER + (normal_A * radius);
		glm::vec3 real_B = CENTER + (normal_B * radius);
		glm::vec3 real_C = CENTER + (normal_C * radius);

		m->vertices.push_back({ real_A, normal_A, WHITE, glm::vec2(0.f, 0.f) });
		m->vertices.push_back({ real_B, normal_B, WHITE, glm::vec2(0.f, 0.f) });
		m->vertices.push_back({ real_C, normal_C, WHITE, glm::vec2(0.f, 0.f) });
	}

	glGenVertexArrays(1, &m->VAO);
	glBindVertexArray(m->VAO);

	glGenBuffers(1, &m->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m->VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*m->vertices.size(), (GLfloat *)&m->vertices[0], GL_STREAM_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, position)));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, normal)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, color)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	// // top front
	// m->vertices.push_back({ E, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	// m->vertices.push_back({ A, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	// m->vertices.push_back({ B, ZERO, WHITE, glm::vec2(0.f, 0.f) });

	// // top right
	// m->vertices.push_back({ E, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	// m->vertices.push_back({ B, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	// m->vertices.push_back({ C, ZERO, WHITE, glm::vec2(0.f, 0.f) });

	// // top back
	// m->vertices.push_back({ E, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	// m->vertices.push_back({ C, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	// m->vertices.push_back({ D, ZERO, WHITE, glm::vec2(0.f, 0.f) });

	// // top left
	// m->vertices.push_back({ E, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	// m->vertices.push_back({ D, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	// m->vertices.push_back({ A, ZERO, WHITE, glm::vec2(0.f, 0.f) });

	// // bottom front
	// m->vertices.push_back({ F, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	// m->vertices.push_back({ B, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	// m->vertices.push_back({ A, ZERO, WHITE, glm::vec2(0.f, 0.f) });

	// // bottom right
	// m->vertices.push_back({ F, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	// m->vertices.push_back({ C, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	// m->vertices.push_back({ B, ZERO, WHITE, glm::vec2(0.f, 0.f) });

	// // bottom back
	// m->vertices.push_back({ F, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	// m->vertices.push_back({ D, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	// m->vertices.push_back({ C, ZERO, WHITE, glm::vec2(0.f, 0.f) });

	// // bottom left
	// m->vertices.push_back({ F, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	// m->vertices.push_back({ A, ZERO, WHITE, glm::vec2(0.f, 0.f) });
	// m->vertices.push_back({ D, ZERO, WHITE, glm::vec2(0.f, 0.f) });

}

std::vector<glm::vec3> sub_triangles(std::vector<glm::vec3> triangles, int levels)
{
	
	#ifdef DEBUG_BUILD
	std::cout << "level: " << levels << std::endl;
	#endif

	if(levels > 0)
	{
		std::vector<glm::vec3> new_verts;
		for(auto i = triangles.begin(); i != triangles.end(); i += 3)
		{
			std::vector<glm::vec3> verts = subdivide_triangle(*i, *(i+1), *(i+2));
			for(auto j = verts.begin(); j != verts.end(); ++j)
				new_verts.push_back(*j);
		}
		return sub_triangles(new_verts, --levels);
	}
	else
	{
		return triangles;
	}
}

std::vector<glm::vec3> subdivide_triangle(glm::vec3 A, glm::vec3 B, glm::vec3 C)
{
	glm::vec3 D = {};
	glm::vec3 E = {};
	glm::vec3 F = {};

	// get the sides
	glm::vec3 line_AB = B - A;
	glm::vec3 line_BC = C - B;
	glm::vec3 line_CA = A - C;

	glm::vec3 h_AB = line_AB / 2.f;
	glm::vec3 h_BC = line_BC / 2.f;
	glm::vec3 h_CA = line_CA / 2.f;

	D = A + h_AB;
	E = B + h_BC;
	F = C + h_CA;

	std::vector<glm::vec3> new_triangels;

	new_triangels.push_back(A);
	new_triangels.push_back(D);
	new_triangels.push_back(F);

	new_triangels.push_back(D);
	new_triangels.push_back(B);
	new_triangels.push_back(E);

	new_triangels.push_back(D);
	new_triangels.push_back(E);
	new_triangels.push_back(F);

	new_triangels.push_back(F);
	new_triangels.push_back(E);
	new_triangels.push_back(C);

	return new_triangels;
}


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

void reload_shader(Shader *shader, std::string uniforms[], int uniform_sz)
{
	if(uniform_sz == 0)
	{
		shader->id = load_shader_program(shader->vertex_path, shader->fragment_path);
		glUseProgram(shader->id);

		for(std::unordered_map<std::string, GLint>::iterator it = shader->uniforms.begin();
			it != shader->uniforms.end();
			++it)
		{
			GLint pos = glGetUniformLocation(shader->id, (GLchar *)(*it).first.c_str());

			#if DEBUG_BUILD
			std::cout << (*it).first << ": " << pos << std::endl;
			#endif
			shader->uniforms[(*it).first] = pos;
		}
	}
	else
	{
		for(int i = 0; i < uniform_sz; ++i)
		{
			shader->uniforms[uniforms[i].c_str()] = glGetUniformLocation(shader->id, uniforms[i].c_str());
		}
	}
}

void create_shader(Shader *shader, std::string vertex_path, std::string fragment_path, std::string uniforms[], int uniform_sz)
{
	shader->vertex_path = vertex_path;
	shader->fragment_path = fragment_path;
	shader->id = load_shader_program(vertex_path, fragment_path);
	reload_shader(shader, uniforms, uniform_sz);
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
		#ifdef DEBUG_BUILD
		std::cout << "[ERROR " << __FILE__ << ":" << __LINE__ << "] Could not read file to get the file size. " << std::endl;
		#endif
		return -2;
	}
	return in.tellg();
}
