//#define GLEW_STATIC	//スタティックリンク
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Window.hpp"
//#include "Object.hpp"
#include "Shape.hpp"
#include <glew/include/GL/glew.h>
#include <glfw/include/GLFW/glfw3.h>


GLuint CreateProgram(const char* vsrc, const char* fsrc);
bool ReadShaderSource(const char* name, std::vector<GLchar>& buffer);

//シェーダーをロード
GLuint loadProgram(const char* vert, const char* frag)
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
bool ReadShaderSource(const char* name, std::vector<GLchar>& buffer)
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
GLboolean InfoLog(GLuint shader, const char* str)
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

		std::cerr << &infoLog[0] << std::endl;
	}



	return (GLboolean)status;
}




//プログラムオブジェクト作成
GLuint CreateProgram(const char* vsrc, const char* fsrc)
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



Object::Vertex rectangleVertex[4] =
{
	{-0.5f,-0.5f},
	{0.5f,-0.5f},
	{0.5f,0.5f},
	{-0.5f,0.5f}
};


int main()
{
	if (glfwInit() == GL_FALSE)
	{
		std::cerr << "glfw初期化失敗。" << std::endl;
		return -1;
	}


	atexit(glfwTerminate);	//プログラム終了時の処理を登録
	Window window;

	//OpenGL Verison 3.2 Core Profile　を選択する
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);


	Shape* shape = new Shape(2, 4, rectangleVertex);


	GLuint program = loadProgram("Test.vert", "Test.frag");
	const GLuint asepectLoc = glGetUniformLocation(program, "asepect");



	glClearColor(1.0, 0.0, 0.0, 1.0);	//背景色
	while (window)
	{
		glClear(GL_COLOR_BUFFER_BIT);	//カラーバッファをクリア
		glUniform1f(asepectLoc, window.getAspect());
		glUseProgram(program);

		shape->Draw();

		window.SwapBuffers();	//ダブルバッファリング
	}

}
