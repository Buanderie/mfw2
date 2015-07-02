#pragma once

// Internal
#include "identifiable.h"
#include "packet.h"

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

    Pin( monadic::Pin::PinMode pinMode, bool needResetGuid=true )
        :_pinMode(pinMode)
    {
        if( needResetGuid )
            resetGuid();
    }

    virtual ~Pin(){}

    virtual void build(){};
    virtual void connect(std::shared_ptr<monadic::Pin> p){};
    virtual void disconnect(std::shared_ptr<monadic::Pin> p){}

    virtual void onConnect( std::shared_ptr<monadic::Link> link ){}
    virtual void onDisconnect( std::shared_ptr<monadic::Link> link){}
    virtual void onBuild(){};
    virtual void onCreate(){};

	// 
	std::vector< std::shared_ptr<Packet> > poll(); 


private:

protected:
    PinMode _pinMode;
    

};
}
