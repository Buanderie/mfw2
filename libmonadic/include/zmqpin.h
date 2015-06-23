#pragma once

// Internal
#include "pin.h"
#include "link.h"

// STL
#include <cstddef>
#include <memory>

namespace monadic
{
        class ZMQPin : public monadic::Pin
        {
        public:
            ZMQPin( monadic::Pin::PinMode pinMode );
            virtual ~ZMQPin();

            virtual void setup();
            virtual void connect(std::shared_ptr<monadic::Pin> p);
            
            virtual void onConnect( std::shared_ptr<monadic::Link> link );
            virtual void onCreate();
            virtual size_t send( const void* data, size_t length );
            virtual size_t receive( const void* data );

        private:
            void init();
            void destroy();

            void * _pinSocket;

        protected:

	};
}
