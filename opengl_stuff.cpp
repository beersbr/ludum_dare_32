// #include "opengl_stuff.h"

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
	return in.tellg();
}
