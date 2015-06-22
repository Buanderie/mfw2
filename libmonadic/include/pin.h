#pragma once

// Internal
#include "identifiable.h"

// STL
#include <memory>

namespace monadic
{
class Link;
class Pin : public monadic::Identifiable
{
public:
    typedef enum
    {
        PIN_MODE_INPUT=0,
        PIN_MODE_OUTPUT
    } PinMode;

    Pin( monadic::Pin::PinMode pinMode )
        :_pinMode(pinMode)
    {}

    virtual ~Pin(){}

    virtual void setup()=0;

    virtual void onConnect( std::shared_ptr<monadic::Link> link )=0;
    virtual void onCreate()=0;

    virtual size_t send( const void* data, size_t length )=0;
    virtual size_t receive( const void* data )=0;

private:

protected:
    PinMode _pinMode;

};
}
