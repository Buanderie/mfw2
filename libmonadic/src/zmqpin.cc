
// Internal
#include "zmqpin.h"

// ZMQ
#include <zmq.hpp>

// STL
#include <sstream>

// Global ZMQ context
zmq::context_t _zmqContext(1);

using namespace std;

namespace monadic
{
    ZMQPin::ZMQPin(monadic::Pin::PinMode pinMode)
        :Pin(pinMode)
	{

	}

	ZMQPin::~ZMQPin()
	{

	}

	void ZMQPin::setup()
	{
        zmq::socket_t * ls;
        // Create socket
        if( _pinMode == Pin::PIN_MODE_OUTPUT )
        {
            ls = new zmq::socket_t( _zmqContext, ZMQ_PUB );
            stringstream sstr;
            sstr << "inproc://" << _guid.toString();
            ls->bind( sstr.str().c_str() );
        }
        else if( _pinMode == Pin::PIN_MODE_INPUT )
        {
            ls = new zmq::socket_t( _zmqContext, ZMQ_SUB );
        }
        _pinSocket = (void*)ls;
    }

	void ZMQPin::onConnect( std::shared_ptr<monadic::Link> link )
	{

	}
     
	void ZMQPin::onCreate()
	{

	}

    size_t ZMQPin::send( const void* data, size_t length )
	{
		return 0;
	}

    size_t ZMQPin::receive( const void* data )
	{
		return 0;
	}
}
