// Mesh.cpp
//
#include "Mesh.h"

#include "Primitive.h"

using namespace s2;
using namespace s2::OpenGL;


// ------------------------------------------------------------------------------------------------
MeshPtr Mesh::New()
{
	return std::make_shared<Mesh>();
}


// ------------------------------------------------------------------------------------------------
// Mesh Attribute location:
//	 (0) vertices
//   (1) colors
//   (2) normals
//   (3) texture coords
// ------------------------------------------------------------------------------------------------
Mesh::Mesh()
: primitiveType(Primitive::Points)
, frontFaceWindingOrder(WindingOrder::Counterclockwise)
, usageHint(BufferObject::UsageHint::StaticDraw)
{}

// ------------------------------------------------------------------------------------------------
Mesh::~Mesh()
{}

// ------------------------------------------------------------------------------------------------
void Mesh::setVertices( const std::vector<Math::vec3> &points )
{
	VertexBuffer buf( usageHint, points.size() * sizeof(Math::vec3) );
	buf.sendData( (void*)(&points[0]), points.size() * sizeof(Math::vec3), 0 );

	_va.attribute(0).set( buf, AttributeBuffer::Float,3, false,0,0 );
}

// ------------------------------------------------------------------------------------------------
void Mesh::setColors( const std::vector<Color>   &colors   )
{
	VertexBuffer buf(  usageHint, colors.size() * sizeof(Color) );
	buf.sendData( (void*)(&colors[0]), colors.size() * sizeof(Color), 0 );

	_va.attribute(1).set( buf, AttributeBuffer::Float,4, false,0,0 );
}

// ------------------------------------------------------------------------------------------------
void Mesh::setNormals( const std::vector<Math::vec3>  &normals  )
{
	VertexBuffer buf(  usageHint, normals.size() * sizeof(Math::vec3) );
	buf.sendData( (void*)(&normals[0]), normals.size() * sizeof(Math::vec3), 0 );

	_va.attribute(2).set( buf, AttributeBuffer::Float,3, false,0,0 );
}

// ------------------------------------------------------------------------------------------------
void Mesh::setTextureCoords( const std::vector<Math::vec2>  &texCoords)
{
	VertexBuffer buf( usageHint, texCoords.size() * sizeof(Math::vec2) );
	buf.sendData( (void*)(&texCoords[0]), texCoords.size() * sizeof(Math::vec2), 0 );

	_va.attribute(3).set( buf, AttributeBuffer::Float,2, false,0,0 );
}

// ------------------------------------------------------------------------------------------------
//void Mesh::setAttribute( int attribID, void *data, int elementsCount, AttributeBuffer::ComponentDatatype dataType, int componentsCount )
//{
// @tbd (
//	VertexBuffer vb;
//	vb.set( elementsCount * dataType * componentsCount, BufferObject::StaticDraw );
//	vb.sendData( data, elementsCount * dataType * componentsCount, 0 );
//
//	_va.attribute(attribID)->set( vb, (void*)(&pts[0]), pts.size(),    OpenGL::AttributeBuffer::Float, 3
//}

// ------------------------------------------------------------------------------------------------
void Mesh::setIndices( const std::vector<unsigned int> &indices )
{
	_va.indexBuffer().set( indices.size() * sizeof( unsigned int ), IndexBuffer::UnsignedInt, usageHint );
	_va.indexBuffer().sendData( (void*)(&indices[0]), indices.size() * sizeof( unsigned int ), 0 );
}