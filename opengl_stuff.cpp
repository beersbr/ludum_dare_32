#include "opengl_stuff.h"

std::ostream& operator << (std::ostream& os, const glm::vec3& v)
{
	os << "( " << v.x << ", " << v.y << ", " << v.z << " )";
	return os;
}

std::ostream& operator << (std::ostream& os, const glm::vec2& v)
{
	os << "( " << v.x << ", " << v.y << " )";
	return os;
}



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
	glm::vec3 A = glm::vec3( -GOLDEN,  0.0f, -GOLDEN );
	glm::vec3 B = glm::vec3(  GOLDEN,  0.0f, -GOLDEN );
	glm::vec3 C = glm::vec3(  GOLDEN,  0.0f,  GOLDEN );
	glm::vec3 D = glm::vec3( -GOLDEN,  0.0f,  GOLDEN );

	// top and bottom
	glm::vec3 E = glm::vec3(  0.0f,  GOLDEN,  0.0f );
	glm::vec3 F = glm::vec3(  0.0f, -GOLDEN,  0.0f );

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
	glm::vec3 A = glm::normalize(glm::vec3( -cosf(45.f * PI/180.f),  0.0f, -sinf(45.f * PI/180.f) ) );
	glm::vec3 B = glm::normalize(glm::vec3(  cosf(45.f * PI/180.f),  0.0f, -sinf(45.f * PI/180.f) ) );
	glm::vec3 C = glm::normalize(glm::vec3(  cosf(45.f * PI/180.f),  0.0f,  sinf(45.f * PI/180.f) ) );
	glm::vec3 D = glm::normalize(glm::vec3( -cosf(45.f * PI/180.f),  0.0f,  sinf(45.f * PI/180.f) ) );

	std::cout << "LENGTH: " << glm::length2(A) << std::endl;

	// top and bottom
	glm::vec3 E = glm::normalize(glm::vec3(  0.0f,  1.f,  0.0f ) );
	glm::vec3 F = glm::normalize(glm::vec3(  0.0f, -1.f,  0.0f ) );

	float radius = glm::distance(A-CENTER, CENTER);

	std::cout << "RADIUS: " << radius << std::endl;
	radius = 1.f;

	// for(auto i = triangles.begin(); i < triangles.end(); ++i)
	// {
	// 	std::vector<glm::vec3> sub_divided = subdivide_triangle((*i)[0], (*i)[1], (*i)[2]);

	// }

	/*
               E
		  D _______  C
	      /        /
		 /        /
		/_______ /
      A          B 
		    F
	*/

	int subs = 6;

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

		glm::vec3 real_A = CENTER + (normal_A);
		glm::vec3 real_B = CENTER + (normal_B);
		glm::vec3 real_C = CENTER + (normal_C);

		glm::vec2 uvA = {atan2f(normal_A.z, normal_A.x)/(2.f*PI), (normal_A.y + 1.f)/2.f};
		glm::vec2 uvB = {atan2f(normal_B.z, normal_B.x)/(2.f*PI), (normal_B.y + 1.f)/2.f};
		glm::vec2 uvC = {atan2f(normal_C.z, normal_C.x)/(2.f*PI), (normal_C.y + 1.f)/2.f};

		m->vertices.push_back({ vA, normal_A, WHITE, uvA });
		m->vertices.push_back({ vB, normal_B, WHITE, uvB });
		m->vertices.push_back({ vC, normal_C, WHITE, uvC });
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

		glm::vec2 uvA = {atan2f(normal_A.z, normal_A.x)/(2.f*PI), (normal_A.y + 1.f)/2.f};
		glm::vec2 uvB = {atan2f(normal_B.z, normal_B.x)/(2.f*PI), (normal_B.y + 1.f)/2.f};
		glm::vec2 uvC = {atan2f(normal_C.z, normal_C.x)/(2.f*PI), (normal_C.y + 1.f)/2.f};

		m->vertices.push_back({ vA, normal_A, WHITE, uvA });
		m->vertices.push_back({ vB, normal_B, WHITE, uvB });
		m->vertices.push_back({ vC, normal_C, WHITE, uvC });
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

		glm::vec2 uvA = {atan2f(normal_A.z, normal_A.x)/(2.f*PI), (normal_A.y + 1.f)/2.f};
		glm::vec2 uvB = {atan2f(normal_B.z, normal_B.x)/(2.f*PI), (normal_B.y + 1.f)/2.f};
		glm::vec2 uvC = {atan2f(normal_C.z, normal_C.x)/(2.f*PI), (normal_C.y + 1.f)/2.f};

		m->vertices.push_back({ vA, normal_A, WHITE, uvA });
		m->vertices.push_back({ vB, normal_B, WHITE, uvB });
		m->vertices.push_back({ vC, normal_C, WHITE, uvC });
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

		glm::vec2 uvA = {atan2f(normal_A.z, normal_A.x)/(2.f*PI), (normal_A.y + 1.f)/2.f};
		glm::vec2 uvB = {atan2f(normal_B.z, normal_B.x)/(2.f*PI), (normal_B.y + 1.f)/2.f};
		glm::vec2 uvC = {atan2f(normal_C.z, normal_C.x)/(2.f*PI), (normal_C.y + 1.f)/2.f};

		m->vertices.push_back({ vA, normal_A, WHITE, uvA });
		m->vertices.push_back({ vB, normal_B, WHITE, uvB });
		m->vertices.push_back({ vC, normal_C, WHITE, uvC });
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

		glm::vec2 uvA = {atan2f(normal_A.z, normal_A.x)/(2.f*PI), (normal_A.y + 1.f)/2.f};
		glm::vec2 uvB = {atan2f(normal_B.z, normal_B.x)/(2.f*PI), (normal_B.y + 1.f)/2.f};
		glm::vec2 uvC = {atan2f(normal_C.z, normal_C.x)/(2.f*PI), (normal_C.y + 1.f)/2.f};

		m->vertices.push_back({ vA, normal_A, WHITE, uvA });
		m->vertices.push_back({ vB, normal_B, WHITE, uvB });
		m->vertices.push_back({ vC, normal_C, WHITE, uvC });
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

		glm::vec2 uvA = {atan2f(normal_A.z, normal_A.x)/(2.f*PI), (normal_A.y + 1.f)/2.f};
		glm::vec2 uvB = {atan2f(normal_B.z, normal_B.x)/(2.f*PI), (normal_B.y + 1.f)/2.f};
		glm::vec2 uvC = {atan2f(normal_C.z, normal_C.x)/(2.f*PI), (normal_C.y + 1.f)/2.f};

		m->vertices.push_back({ vA, normal_A, WHITE, uvA });
		m->vertices.push_back({ vB, normal_B, WHITE, uvB });
		m->vertices.push_back({ vC, normal_C, WHITE, uvC });
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

		glm::vec2 uvA = {atan2f(normal_A.z, normal_A.x)/(2.f*PI), (normal_A.y + 1.f)/2.f};
		glm::vec2 uvB = {atan2f(normal_B.z, normal_B.x)/(2.f*PI), (normal_B.y + 1.f)/2.f};
		glm::vec2 uvC = {atan2f(normal_C.z, normal_C.x)/(2.f*PI), (normal_C.y + 1.f)/2.f};

		m->vertices.push_back({ vA, normal_A, WHITE, uvA });
		m->vertices.push_back({ vB, normal_B, WHITE, uvB });
		m->vertices.push_back({ vC, normal_C, WHITE, uvC });
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

		glm::vec2 uvA = {atan2f(normal_A.z, normal_A.x)/(2.f*PI), (normal_A.y + 1.f)/2.f};
		glm::vec2 uvB = {atan2f(normal_B.z, normal_B.x)/(2.f*PI), (normal_B.y + 1.f)/2.f};
		glm::vec2 uvC = {atan2f(normal_C.z, normal_C.x)/(2.f*PI), (normal_C.y + 1.f)/2.f};

		m->vertices.push_back({ vA, normal_A, WHITE, uvA });
		m->vertices.push_back({ vB, normal_B, WHITE, uvB });
		m->vertices.push_back({ vC, normal_C, WHITE, uvC });
	}

	glGenVertexArrays(1, &m->VAO);
	glBindVertexArray(m->VAO);

	glGenBuffers(1, &m->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m->VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*m->vertices.size(), (GLfloat *)&m->vertices[0], GL_STREAM_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, position)));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, normal)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, color)));
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, uv)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);

}

std::vector<glm::vec3> sub_triangles(std::vector<glm::vec3> triangles, int levels)
{
	if(levels > 0)
	{
		std::vector<glm::vec3> new_verts;
		for(auto i = triangles.begin(); i != triangles.end(); i += 3)
		{
			std::vector<glm::vec3> verts = subdivide_triangle(*i, *(i+1), *(i+2));
			for(auto j = verts.begin(); j != verts.end(); ++j)
			{
				glm::vec3 v = (*j);
				// glm::vec3 normal = glm::normalize(v - ZERO);
				// glm::vec3 real = ZERO + (normal * 0.5f);
				
				new_verts.push_back(v);
			}
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

	// get mid points
	glm::vec3 h_AB = (B+A) / 2.f;
	glm::vec3 h_BC = (C+B) / 2.f;
	glm::vec3 h_CA = (A+C) / 2.f;

	D = glm::normalize(h_AB) * 1.0f;
	E = glm::normalize(h_BC) * 1.0f;
	F = glm::normalize(h_CA) * 1.0f;

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

GLuint load_image_1d(std::string image_path)
{

	SDL_Surface *image = IMG_Load(image_path.c_str());

	GLuint texture_id;
	glGenTextures(1, &texture_id);

	glActiveTexture(GL_TEXTURE0 + 0);
	glBindTexture(GL_TEXTURE_1D, texture_id);

	glTexParameterf(GL_TEXTURE_1D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameterf(GL_TEXTURE_1D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

    glTexParameterf(GL_TEXTURE_1D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_1D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);

    std::cout << glm::vec2(image->w, image->h) << std::endl;

    glTexImage1D(GL_TEXTURE_1D,
    			 0,
    			 GL_RGBA,
    			 image->w,
    			 0,
    			 GL_BGRA,
    			 GL_UNSIGNED_BYTE,
    			 image->pixels);

    SDL_FreeSurface(image);

    return texture_id;
}

GLuint load_image_2d(std::string image)
{
	GLuint texture_id;
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);

	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);

    // glTexImage2D(GL_TEXTURE_2D, 0 ,GL_RGBA,image->w,image ->h,0,GL_RGBA,GL_UNSIGNED_BYTE,image->pixels);
    
    return texture_id;
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
