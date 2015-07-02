
#include "core/packet.h"

namespace monadic
{
	Packet::Packet( const std::string& senderName, const std::string& receiverName, void* data, size_t dataSize )
			:_senderName(senderName), _receiverName(receiverName), _dataSize(dataSize), _data(0)
	{
		if( _data != 0 )
		{
			free( _data );
		}
		_data = malloc( sizeof( uint8_t ) * _dataSize );
	}

	Packet::~Packet()
	{
		if( _data != 0 )
		{
			free( _data );
		}
	}
}
