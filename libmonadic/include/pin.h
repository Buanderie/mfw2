#pragma once

// Internal
#include "identifiable.h"
#include "link.h"

// STL
#include <memory>

// ZMQ
#include <zmq.hpp>

namespace monadic
{
    class Pin : public monadic::Identifiable
    {
    public:
		Pin();
		virtual ~Pin(){}

		virtual void setup();

		virtual void onConnect( std::shared_ptr<monadic::Link> link );
		virtual void onCreate();

		virtual size_t send( const void* data, size_t length );
		virtual size_t receive( const void* data );

    private:

    protected:

    };
}
