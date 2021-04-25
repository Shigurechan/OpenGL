#include "Shader.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <glm/gtc/type_ptr.hpp>

//コンストラクタ
Shader::Shader(const char* vert, const char* frag)
{
	program = loadProgram(vert,frag);
	if (program == 0)
	{
		std::cerr << "シェーダープログラム作成エラー"<<std::endl;
		exit(1);
	}


	

	//std::cout<< program << std::endl;

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
	const GLuint program = glCreateProgram();	//シェーダープログラムを作成

	//std::cout << program << std::endl;

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
void Shader::setBindAttribVertex(const char* str)
{
	GLint n = glGetAttribLocation(program, str);

	//エラー処理
	if (n == -1)
	{
		std::cerr <<"setBindAttribVertex(): "<< n << std::endl;
	}
	else 
	{
		glBindAttribLocation(program, n, str);
	}
}


//フラグメントシェーダーに属性変数を関連ずける
void Shader::setBindAttribFragment(const char* str)
{
	GLint n = glGetAttribLocation(program, str);

	//エラー処理
	if (n == -1)
	{
		std::cerr << "setBindAttribFragment(): " << n << std::endl;
	}
	else 
	{
		glBindFragDataLocation(program, n, str);
	}
}

//有効にする
void Shader::setEnable()
{
	glUseProgram(program);

}

//無効にする
void Shader::setDisable()
{
	glUseProgram(0);

}


//　######################################################### Uniform 設定

//vec1
void Shader::setUniform1f(const char* name, const float vec)
{
	const GLuint object = glGetUniformLocation(program, name);
	glUniform1f(object,vec);
}

//vec2
void Shader::setUniform2f(const char* name, const glm::vec2 vec)
{
	const GLuint object = glGetUniformLocation(program, name);
	glUniform2f(object,vec.x,vec.y);
}

//vec3
void Shader::setUniform3f(const char* name, const glm::vec3 vec)
{
	const GLuint object = glGetUniformLocation(program, name);
	glUniform3f(object,vec.x, vec.y,vec.z);
}

//vec4
void Shader::setUniform4f(const char* name, const glm::vec4 vec)
{	
	const GLuint object = glGetUniformLocation(program,name);
	glUniform4f(object, vec.x, vec.y, vec.z, vec.w);	
}


//行列2
void Shader::setUniformMatrix2fv(const char* name, const glm::mat2 m)
{
	const GLuint object = glGetUniformLocation(program, name);
	glUniformMatrix2fv(object,1,false,glm::value_ptr(m));
}

//行列３
void Shader::setUniformMatrix3fv(const char* name, const glm::mat3 m)
{
	const GLuint object = glGetUniformLocation(program, name);
	glUniformMatrix3fv(object, 1, false, glm::value_ptr(m));
}

//行列4
void Shader::setUniformMatrix4fv(const char* name, const glm::mat4 m)
{
	const GLuint object = glGetUniformLocation(program, name);
	glUniformMatrix4fv(object, 1, false, glm::value_ptr(m));

}

//デストラクタ
Shader::~Shader()
{

}
