#pragma once

// Internal
#include "identifiable.h"
#include "packet.h"

// STL
#include <memory>
#include <mutex>
#include <condition_variable>

namespace monadic
{
class Link;
class Pin
{
public:
    typedef enum
    {
        PIN_MODE_INPUT=0,
        PIN_MODE_OUTPUT
    } PinMode;

    Pin( monadic::Pin::PinMode pinMode, const std::string& label="None" )
        :_pinMode(pinMode), _label(label)
    {
    }

    virtual ~Pin(){}

    virtual void build(){};
    virtual void connect(std::shared_ptr<monadic::Pin> p){};
    virtual void disconnect(std::shared_ptr<monadic::Pin> p){}

    virtual void onConnect( std::shared_ptr<monadic::Link> link ){}
    virtual void onDisconnect( std::shared_ptr<monadic::Link> link){}

	std::string label() const;

	// 
	std::vector< std::unique_ptr<Packet> > poll(); 
	void signal_data();

private:
	std::mutex 				_incomingDataMtx;
	std::condition_variable _incomingDataCnd;
	bool					_incomingData;

	std::vector< std::shared_ptr< Link > > _connectedLinks;

protected:
    PinMode 	_pinMode;
	std::string	_label;
    

};
}
