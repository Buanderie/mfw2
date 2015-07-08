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

	// ctor/dtor
    Pin( monadic::Pin::PinMode pinMode, const std::string& label="None" )
        :_pinMode(pinMode), _label(label)
    {
    }
    virtual ~Pin(){}

	std::string label() const;

	// 
	std::vector< std::unique_ptr<Packet> > poll(); 
	void signal_data();

    virtual void onConnect( monadic::Link* link );
    virtual void onDisconnect( monadic::Link* link);

private:
	// Attributes
	std::mutex 				_incomingDataMtx;
	std::condition_variable _incomingDataCnd;
	bool					_incomingData;
	std::vector< std::shared_ptr< Link > > _connectedLinks;

	// Functions


protected:
	// Attributes
    PinMode 	_pinMode;
	std::string	_label;
    
	// Functions

};
}
