
// Internal
#include "core/packet.h"

// C
#include <cstring>

namespace monadic
{
    // Packet creation from object
    Packet::Packet( const std::string& senderName, const std::string& receiverName, std::shared_ptr<Object> obj )
        :_senderName(senderName), _receiverName(receiverName), _data(0)
	{

	}

    // Object retrieval from packet
    Packet::Packet( void* rawData, size_t rawDataSize )
        :_data(0)
    {

    }

	Packet::~Packet()
	{
		if( _data != 0 )
		{
			free( _data );
        }
    }

    size_t Packet::packetDataSize()
    {
        return 156;
    }
}
