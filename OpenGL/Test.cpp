#include "Test.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
Test::Test()
{

}

//シェーダーをロード
GLuint Test::loadProgram(const char* vert, const char* frag)
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
bool Test::ReadShaderSource(const char* name, std::vector<GLchar>& buffer)
{
	if (name == NULL)
	{
		return false;
	}
	

	std::ifstream file(name, std::ios::binary);
	if (file.fail())
	{
		std::cerr << "ソースファイルが読み込めません: " << name << std::endl;
		return false;
	}

	file.seekg(0L, std::ios::end);
	GLsizei length = static_cast<GLsizei>(file.tellg());
	buffer.resize(length + 1);
	file.seekg(0L, std::ios::beg);
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
GLboolean Test::InfoLog(GLuint shader, const char* str)
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
GLuint Test::CreateProgram(const char* vsrc, const char* fsrc)
{
	const GLuint program(glCreateProgram());
	if (vsrc != NULL)
	{
		const GLuint vobj(glCreateShader(GL_VERTEX_SHADER));
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
		const GLuint fobj(glCreateShader(GL_VERTEX_SHADER));
		glShaderSource(fobj, 1, &fsrc, NULL);
		glCompileShader(fobj);

		InfoLog(fobj, "fsrc");

		glAttachShader(program, fobj);
		glDeleteShader(fobj);
	}
	else {
		//std::cout << "フラグメントシェーダー読み込み失敗" << std::endl;

	}


	glBindAttribLocation(program, 0, "Position");
	glBindFragDataLocation(program, 0, "fragment");
	glLinkProgram(program);


	return program;
}

void Test::Update()
{

}




void Test::Draw() 
{
	
	
}











Test::~Test()
{

}
