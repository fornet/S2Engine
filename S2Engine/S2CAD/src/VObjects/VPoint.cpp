// VPoint.cpp
//
#include "VPoint.h"

#include "OpenGL/Renderer.h"
#include "OpenGL/Selection.h"
#include "OpenGL/OpenGL.h"

#include <iostream>

#include "Utils/MemCheck.h"

// ------------------------------------------------------------------------------------------------
VPoint::VPoint()
{}

// ------------------------------------------------------------------------------------------------
VPoint::VPoint( double x, double y, double z )
{
	_coords.push_back( Math::dvec3(x,y,z) );

	_boundingBox.extend( _coords[0] );
	_boundingBox.scale(1.2);
}

// ------------------------------------------------------------------------------------------------
VPoint::VPoint( const Math::dvec3 &p )
{
	_coords.push_back( p );

	_boundingBox.extend( p );
	_boundingBox.scale(1.2);
}

// ------------------------------------------------------------------------------------------------
VObject::ObjectType VPoint::type() const		{ return Point; }

// ------------------------------------------------------------------------------------------------
std::vector<Math::dvec3> VPoint::snapPoints() const
{
	return _coords;
}

// ------------------------------------------------------------------------------------------------
Math::dvec3 VPoint::center() const
{
	return _coords[0];
}

// ------------------------------------------------------------------------------------------------
void VPoint::draw( OpenGL::Renderer *r ) const
{
	if( _coords.empty() )
		return;

	//Math::dvec3 o = r->origin();
	const float borderSize = style().penSize() + style().borderSize();
	glPointSize(borderSize + (isHilighted() * 3.f) );
	glColor4fv( style().borderColor() );

	r->beginRendering();
	r->setVertex3DArray( _coords );
	// background as border
	glDrawArrays( GL_POINTS, 0, 1 );

	glColor4fv( color() );
	glPointSize(style().penSize() + (isHilighted() * 3.f) );

	glDrawArrays( GL_POINTS, 0, 1 );

	r->endRendering();
}

// ------------------------------------------------------------------------------------------------
void VPoint::drawForSelection( OpenGL::Renderer *r ) const
{
	OpenGL::Selection::Name name( _id );

	glPointSize(style().penSize());

	r->beginRendering();
	r->setVertex3DArray( _coords );

	glDrawArrays( GL_POINTS, 0, 1 );

	r->endRendering();
}

// ------------------------------------------------------------------------------------------------
bool VPoint::intersects( const Math::box3 &b ) const
{
	return b.contains( _coords[0] );
}

// ------------------------------------------------------------------------------------------------
std::vector<Math::dvec3> VPoint::getPoints() const
{
	return _coords;
}

// ------------------------------------------------------------------------------------------------
VObject* VPoint::clone() const
{
	VPoint* clone= new VPoint;
	this->copyDataIn( clone );

	clone->_coords=	_coords;

	return clone;
}