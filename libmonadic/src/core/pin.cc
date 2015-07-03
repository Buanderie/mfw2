
// Internal
#include "core/pin.h"
#include "core/link.h"

// STL
#include <memory>
#include <mutex>

using namespace std;

namespace monadic
{
	// Polling from multiple/single link
	std::vector< std::unique_ptr< Packet > > Pin::poll()
	{
		while(1)
		{
			std::vector< std::unique_ptr< Packet > > res;
			std::unique_lock<mutex> lck(_incomingDataMtx);
			// Check for each link if data is available
			for( std::shared_ptr< Link > l : _connectedLinks )
			{
				if( l->dataAvailable() )
				{
					// Fetch data packets...
					res.push_back( l->recv() );
				}	
			}

			if( res.size() == 0 )
			{
				// If there is no data available on comm links, wait for signal
				_incomingDataCnd.wait( lck );
			}
			else
			{
				return res;
			}
		}
	}

	void Pin::signal_data()
	{
		std::lock_guard<std::mutex> lck (_incomingDataMtx);
		_incomingDataCnd.notify_all();
	}

	std::string Pin::label() const
	{
		return _label;
	}
}
