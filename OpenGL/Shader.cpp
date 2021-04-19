#include "Shader.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//コンストラクタ
Shader::Shader(const char* vert, const char* frag)
{
	program = loadProgram(vert,frag);
}

//シェーダーをロード
GLuint Shader::loadProgram(const char* vert, const char* frag)
{
	std::vector<GLchar> vsrc;
	const bool vstat = ReadShaderSource(vert, vsrc);

	std::vector<GLchar> fsrc;
	const bool fstat = ReadShaderSource(frag, fsrc);


	if (vstat && fstat)
	{
		return CreateProgram(vsrc.data(), fsrc.data());
	}
	else {
		return 0;
	}
}



//シェーダーファイルを読み込む
bool Shader::ReadShaderSource(const char* name, std::vector<GLchar>& buffer)
{
	if (name == NULL)
	{
		return false;
	}
	

	std::ifstream file(name, std::ios::binary);
	if (file.fail())
	{
		std::cerr << "ソースファイルが読み込めません: " << name << std::endl;
		file.close();
		return false;
	}

	file.seekg(0L, std::ios::end);
	GLsizei length = static_cast<GLsizei>(file.tellg());
	buffer.resize(length + 1);

	file.seekg(0L, std::ios::beg);
	file.read(buffer.data(), length);
	buffer[length] = '\0';
	
	if (file.fail())
	{
		std::cerr << "ソースファイルを読み込めません: " << name << std::endl;
		file.close();

		return false;
	}

	file.close();
	return true;
}



//エラーログを取得
GLboolean Shader::InfoLog(GLuint shader, const char* str)
{
	GLint status;

	//コンパイル結果
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		std::cerr << "コンパイルエラー　" << str << std::endl;
	}
	
	//エラーログの長さを得る
	GLsizei bufSize;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &bufSize);

	if (bufSize > 1)
	{
		std::vector<GLchar> infoLog(bufSize);
		GLsizei length;
		glGetShaderInfoLog(shader, bufSize, &length, &infoLog[0]);

		std::cerr<< &infoLog[0] << std::endl;
	}



	return (GLboolean)status;
}




//プログラムオブジェクト作成
GLuint Shader::CreateProgram(const char* vsrc, const char* fsrc)
{
	const GLuint program = glCreateProgram();

	if (vsrc != NULL)
	{
		const GLuint vobj = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vobj, 1, &vsrc, NULL);
		glCompileShader(vobj);

		InfoLog(vobj, vsrc);

		glAttachShader(program, vobj);
		glDeleteShader(vobj);

	}
	else {
		std::cout << "頂点シェーダー読み込み失敗" << std::endl;
	}

	if (fsrc != NULL)
	{
		const GLuint fobj = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fobj, 1, &fsrc, NULL);
		glCompileShader(fobj);

		InfoLog(fobj, fsrc);

		glAttachShader(program, fobj);
		glDeleteShader(fobj);
	}
	else {
		std::cout << "フラグメントシェーダー読み込み失敗" << std::endl;

	}


	glLinkProgram(program);


	return program;
}

//頂点シェーダーに属性変数を関連ずける
void Shader::setBindAttribVertex(int num, const char* str)
{
	glBindAttribLocation(program, num, str);


}


//フラグメントシェーダーに属性変数を関連ずける
void Shader::setBindAttribFragment(int num, const char* str)
{
	glBindFragDataLocation(program, num, str);
}

//有効にする
void Shader::Active()
{
	glUseProgram(program);


}


//vector2 float
void Shader::setUniform2fv(const char* name, const glm::vec2 vec)
{
	const GLuint object = glGetUniformLocation(program, name);

	GLfloat v[2] = { vec.x,vec.y };
	glUniform2fv(object, 1, v);

}

//float 1
void Shader::setUniform1f(const char* name, const float vec)
{
	const GLuint object = glGetUniformLocation(program, name);
	
	
	glUniform1f(object,vec);
	
}





//デストラクタ
Shader::~Shader()
{

}
