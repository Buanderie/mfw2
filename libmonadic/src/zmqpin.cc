
// Internal
#include "zmqpin.h"

// ZMQ
#include <zmq.hpp>

// STL
#include <sstream>
#include <string>

// Global ZMQ context
void * _zmqContext= zmq_ctx_new();

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
        // Create socket
        if( _pinMode == Pin::PIN_MODE_OUTPUT )
        {
            _pinSocket = zmq_socket( _zmqContext, ZMQ_PUSH );
            stringstream sstr;
            sstr << "inproc://" << _guid.toString();
			//sstr << "tcp://127.0.0.1:2609";
			cout << "binding to " << sstr.str() << endl;
            int rc = zmq_bind( _pinSocket, sstr.str().c_str() );
			cout << "binding_rc=" << rc << endl;
        }
        else if( _pinMode == Pin::PIN_MODE_INPUT )
        {
            _pinSocket = zmq_socket( _zmqContext, ZMQ_PULL );
        }
    }
    
    void ZMQPin::connect( std::shared_ptr<monadic::Pin> p )
    {
        cout << _guid.toString() << " Connecting.. " << endl;
		if( _pinMode == Pin::PIN_MODE_INPUT )
		{
			// That shall be a SUB request
			zmq::socket_t* ls = (zmq::socket_t*)(_pinSocket);
			stringstream sstr;
			sstr << "inproc://" << p->guid().toString() << endl;
			//sstr << "tcp://127.0.0.1:2609";
			cout << "connecting to " << sstr.str() << endl;
			int rc = zmq_connect( _pinSocket, sstr.str().c_str() );
			cout << "connect_rc=" << rc << endl;
		}
    }

	void ZMQPin::onConnect( std::shared_ptr<monadic::Link> link )
	{

	}
     
	void ZMQPin::onCreate()
	{

	}

    size_t ZMQPin::send( const void* data, size_t length )
	{
		/* Create a new message, allocating 6 bytes for message content */
		zmq_msg_t msg;
		int rc = zmq_msg_init_size (&msg, 6);
		assert (rc == 0);
		/* Fill in message content with 'AAAAAA' */
		memset (zmq_msg_data (&msg), 'A', 6);
		/* Send the message to the socket */
		//rc = zmq_send (_pinSocket, &msg, 6, 0);
		rc = zmq_send (_pinSocket, "Hello", 5, 0);
		cout << "rc=" << rc << endl;
		// this prints "an error: " + the error message from errno:
		//printf("an error: %s\n", strerror(errno));
		cout << "zmq_error=" << zmq_strerror(errno) << endl;
		return 0;
	}

    size_t ZMQPin::receive( const void* data )
	{
			/* Create an empty ØMQ message */
			zmq_msg_t msg;
			int rc = zmq_msg_init (&msg);
			assert (rc == 0);
			/* Block until a message is available to be received from socket */
			rc = zmq_recv (_pinSocket, &msg, 0, 0);
			assert (rc == 0);
			/* Release message */ zmq_msg_close (&msg);
		return 0;
	}
}
