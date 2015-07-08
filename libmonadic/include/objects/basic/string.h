#pragma once

// Internal
#include "../object.h"

namespace monadic
{
namespace objects
{
namespace basic
{
class String : public monadic::Object
{
public:
    String( const std::string& value=std::string() )
        :_value(value)
    {}

    virtual ~String(){}

    virtual std::shared_ptr<ObjectBlob> serialize()
    {
        std::shared_ptr<ObjectBlob> blob( new ObjectBlob( (monadic::Object*)this ) );
        blob->push<size_t>(_value.size());
        for( char c : _value )
        {
            blob->push<char>(c);
        }
        return blob;
    }

    virtual void deserialize( std::shared_ptr<ObjectBlob> blob )
    {
        _value = std::string();
        size_t strSize = blob->pop<size_t>();
        for( size_t k = 0; k < strSize; ++k )
        {
            _value += ( blob->pop<char>() );
        }
    }

    std::string value()
    {
        return _value;
    }

private:
    std::string _value;

protected:

};
}
}
}
