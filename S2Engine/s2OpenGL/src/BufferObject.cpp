// BufferObject.cpp
// 
#include "BufferObject.h"

#include "OpenGL.h"
#include "OpenGLWrap.h"

using namespace s2;
using namespace s2::OpenGL;

//-------------------------------------------------------------------------------------------------
BufferObject::BufferObject( int size, const Type &type, const UsageHint &usageHint )
: _size(size)
, _type(type)
, _usageHint(usageHint)
{
	//if (sizeInBytes <= 0)
	//{
	//	throw new ArgumentOutOfRangeException("sizeInBytes", "sizeInBytes must be greater than zero.");
	//}

	glGenBuffers( 1, &_id );
	glCheck;
	// Allocating here with GL.BufferData, then writing with GL.BufferSubData
	// in CopyFromSystemMemory() should not have any serious overhead:
	//
	//   http://www.opengl.org/discussion_boards/ubbthreads.php?ubb=showflat&Number=267373#Post267373
	//
	// Alternately, we can delay GL.BufferData until the first
	// CopyFromSystemMemory() call.
	//
	//glBindVertexArray( 0 );
	glBindBuffer( glWrap(_type), _id );
	glBufferData( glWrap(_type), _size, 0, glWrap(_usageHint) );
	glCheck;
}

//-------------------------------------------------------------------------------------------------
BufferObject::~BufferObject()
{
	glDeleteBuffers( 1, &_id );
	glCheck;
}

//-------------------------------------------------------------------------------------------------
void BufferObject::bind()
{
	glBindBuffer( glWrap(_type), _id );
	glCheck;
}

//-------------------------------------------------------------------------------------------------
void BufferObject::unbind()
{
	glBindBuffer( glWrap(_type), 0 );
	glCheck;
}

//-------------------------------------------------------------------------------------------------
void BufferObject::sendData( void *data, int length, int offset )
{
	// @TODO: check arguments validity

	//glBindVertexArray( 0 );
	glBindBuffer( glWrap(_type), _id );	
	glBufferSubData( glWrap(_type), offset, length, data );
	glCheck;
}

//-------------------------------------------------------------------------------------------------
void * BufferObject::receiveData( int length, int offset )
{
	// @TODO: check arguments validity

	unsigned char *data = new unsigned char[length];

	//glBindVertexArray( 0 );
	glBindBuffer( glWrap(_type), _id );	
	glBufferSubData( glWrap(_type), offset, length, data );
	glCheck;
	return data;
}

//-------------------------------------------------------------------------------------------------
void * BufferObject::mapData( const MapMode &mode )
{
	// Note that glMapBuffer() causes a synchronizing issue
	glBindBuffer( glWrap(_type), _id );	
	return glMapBuffer( glWrap(_type), glWrap(mode) );
}

//-------------------------------------------------------------------------------------------------
bool BufferObject::unmapData()
{
	return (bool)glUnmapBuffer( glWrap(_type) );
}
