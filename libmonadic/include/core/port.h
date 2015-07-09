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
class Connection;
class Port
{
public:
    typedef enum
    {
        PORT_MODE_INPUT=0,
        PORT_MODE_OUTPUT
    } PinMode;

    // ctor/dtor
    Port( monadic::Port::PinMode pinMode, const std::string& label="None" )
        :_pinMode(pinMode), _label(label)
    {
    }
    virtual ~Port(){}

    std::string label() const;

    // Polling/Receiving
    std::vector< std::unique_ptr<Packet> > poll();
    void signal_data();
    std::unique_ptr<Packet> recv();

    // Sending
    void send(std::shared_ptr<Packet> p );

    virtual void onConnect(Connection *link );
    virtual void onDisconnect(Connection *link);

private:
	// Attributes
	std::mutex 				_incomingDataMtx;
	std::condition_variable _incomingDataCnd;
	bool					_incomingData;
        std::vector< Connection* > _activeConnections;

	// Functions


protected:
	// Attributes
    PinMode 	_pinMode;
	std::string	_label;
    
	// Functions

};
}
