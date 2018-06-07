// UniformSampler.h
// 
#ifndef UNIFORMSAMPLER_ONCE
#define UNIFORMSAMPLER_ONCE

#include "s2OpenGL_API.h"

#include "Uniform.h"

namespace s2 {

namespace OpenGL {

class S2OPENGL_API UniformSampler : public UniformValue<int>
{
public:
	UniformSampler( int location, const std::string  &name )
	: UniformValue<int>( location,name )
	{}

	virtual ~UniformSampler()
	{}

	void set();
};

}
}
#endif