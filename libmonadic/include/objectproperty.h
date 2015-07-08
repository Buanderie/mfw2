#pragma once

#include "objects/object.h"

#include <string>
#include <memory>
    #include <cxxabi.h>

struct AbstractPropertyValue
{
public:
    AbstractPropertyValue(){}
    virtual ~AbstractPropertyValue(){}

    std::string typeName()
    {
        return _typeName;
    }

protected:
    std::string _typeName;

};

template< class T >
class PropertyValue : public AbstractPropertyValue
{
public:
    PropertyValue( T v )
    {
        set(v);
    }

    virtual ~PropertyValue(){}

    void set( T v )
    {
        _typeName = demangle( typeid(v).name() );
    }

private:
    T _value;
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

};
