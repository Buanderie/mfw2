
// Internal
#include "core/port.h"
#include "core/connection.h"

// STL
#include <memory>
#include <mutex>

using namespace std;

namespace monadic
{
	// Polling from multiple/single link
    std::vector< std::unique_ptr< Packet > > Port::poll()
	{
		while(1)
		{
			std::vector< std::unique_ptr< Packet > > res;
			std::unique_lock<mutex> lck(_incomingDataMtx);
			// Check for each link if data is available
            for( Connection* l : _activeConnections )
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

    void Port::signal_data()
	{
		std::lock_guard<std::mutex> lck (_incomingDataMtx);
        _incomingDataCnd.notify_all();
    }

    std::unique_ptr<Packet> Port::recv()
    {
        // Check if any link is connected
        // If not, wait for
        // if( )
    }

    void Port::send(std::shared_ptr<Packet> p)
    {
        for( Connection* l : _activeConnections )
        {
            l->send(p);
        }
    }

    std::string Port::label() const
	{
		return _label;
	}

    void Port::onConnect(Connection* link)
	{
        _activeConnections.push_back(link);
	}

    void Port::onDisconnect(Connection *link)
	{

	}
}
