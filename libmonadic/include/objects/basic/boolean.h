#pragma once

// Internal
#include "../object.h"

namespace monadic
{
namespace objects
{
namespace basic
{
class Number : public monadic::Object
{
public:
    Number( bool value=true )
        :_value(value)
    {}

    virtual ~Number(){}

    virtual std::shared_ptr<ObjectBlob> serialize()
    {
        std::shared_ptr<ObjectBlob> blob( new ObjectBlob( (monadic::Object*)this ) );
        blob->push<double>(_value);
        return blob;
    }

    virtual void deserialize( std::shared_ptr<ObjectBlob> blob )
    {
        _value = blob->pop<double>();
    }

    bool value()
    {
        return _value;
    }

private:
    bool _value;

protected:

};
}
}
}
