
// Internal
#include "zmqpin.h"

// ZMQ
#include <zmq.hpp>

using namespace zmq;

// Global ZMQ context
zmq::context_t _zmqContext

namespace monadic
{
	ZMQPin::ZMQPin()
	{

	}

	ZMQPin::~ZMQPin()
	{

	}

	void ZMQPin::setup()
	{
		// 
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
