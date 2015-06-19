#pragma once

// Internal
#include "link.h"

// STL
#include <cstddef>
#include <memory>

namespace monadic
{
	class ZMQPin
	{
		public:
			ZMQPin();
			virtual ~ZMQPin();

			virtual void setup();

			virtual void onConnect( std::shared_ptr<monadic::Link> link );
        	virtual void onCreate();
        	virtual size_t send( const void* data, size_t length );
        	virtual size_t receive( const void* data );

		private:
			void init();
			void destroy();

		protected:

	};
}
