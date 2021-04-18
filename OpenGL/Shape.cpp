#include "Shape.hpp"


Shape::Shape(GLint size, GLsizei vertexcount, const Object::Vertex* vertex)
	:object(std::make_shared<const Object>(size,vertexcount,vertex)), 
	vertexcount(vertexcount)
{

}
void Shape::Draw()const
{
	object->bind();
	execute();
}

void Shape::execute()const
{
	glDrawArrays(GL_LINE_LOOP, 0, vertexcount);
}
