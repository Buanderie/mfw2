
// Internal
#include "objects/object.h"

#ifdef __LINUX__
#include <cxxabi.h>
const char* demangle(const char* name)
{
    char buf[1024];
    unsigned int size=1024;
    int status;
    char* res = abi::__cxa_demangle (name,
                                 buf,
                                 &size,
                                 &status);
    return res;
}
#else
const char* demangle(const char* name)
{
    return name;
}
#endif

namespace monadic
{

std::string Object::typeName()
{
    _type = demangle( typeid(*this).name() );
    return _type;
}
		
}
