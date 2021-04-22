#ifndef ___SHADER_HPP
#define ___SHADER_HPP

#include <iostream>
#include <vector>
#include "glm/glm.hpp"


#include <glew/include/GL/glew.h>
//#include <glfw/include/GLFW/glfw3.h>



class Shader
{
public:
	Shader(const char* vert,const char* frag);	//コンストラクタ
	~Shader();	//デストラクタ

	void Active();	//有効にする。
	void setBindAttribVertex(const char* str);		//頂点シェーダーに属性変数を関連ずける
	void setBindAttribFragment(const char* str);	//フラグメントシェーダーに属性変数を関連ずける


	void setUniform1f(const char* name,const float vec);
	void setUniform2fv(const char* name, const glm::vec2 vec);
	void setUniform3fv(const char* name, const glm::vec3 vec);
	void setUniform4fv(const char* name, const glm::vec4 vec);



private:

	GLuint CreateProgram(const char* vsrc, const char* fsrc);				//プログラムオブジェクトを作成
	GLboolean InfoLog(GLuint shader,const char *str);						//エラーログを取得
	bool ReadShaderSource(const char* name, std::vector<GLchar>& buffer);	//ソースファイルを読み込み
	GLuint loadProgram(const char* vert, const char* frag);					//プログラムをオブジェクトをロード

	GLuint program;	//プログラムオブジェクトシェーダー

};

#endif

