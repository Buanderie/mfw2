
// Internal
#include "core/packet.h"

// C
#include <cstring>

namespace monadic
{
    Packet::Packet( const std::string& senderName, const std::string& receiverName, std::shared_ptr<Object> obj )
        :_senderName(senderName), _receiverName(receiverName)
	{

	}

    Packet::Packet( void* rawData, size_t rawDataSize )
    {

    }

	Packet::~Packet()
	{
		if( _data != 0 )
		{
			free( _data );
        }
    }

    void *Packet::packetData()
    {

    }

    size_t Packet::packetDataSize()
    {

    }

    void *Packet::payloadData()
    {

    }

    size_t Packet::payloadDataSize()
    {

    }

    void Packet::reserve_memory(size_t dataSize)
    {

    }

    void Packet::setPacketHeader(PacketHeader &h)
    {

    }
}
