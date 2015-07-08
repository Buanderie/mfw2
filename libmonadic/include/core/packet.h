#pragma once

#include "../objects/object.h"

// STL
#include <string>
#include <chrono>

namespace monadic
{

class PacketHeader
{
public:
    PacketHeader( const std::string& senderURI, const std::string& receiverURI, std::chrono::high_resolution_clock::time_point& t ){}
    virtual ~PacketHeader(){}

    static size_t headerSize();

private:

protected:

};

class Packet
{
        const static size_t PACKET_SENDER_NAME_LENGTH = 256;
        const static size_t PACKET_RECEIVER_NAME_LENGTH = 256;

	public:
                Packet(const std::string& senderName, const std::string& receiverName, std::shared_ptr<Object> obj);
                Packet( void* rawData, size_t rawDataSize );
		virtual ~Packet();

                void* packetData();
                size_t packetDataSize();

                void* payloadData();
                size_t payloadDataSize();

	private:
                // Attributes
		std::string _senderName;
		std::string _receiverName;
                void*       _data;
                size_t      _payloadSize;

                // Functions
                void reserve_memory( size_t dataSize );
                void setPacketHeader( PacketHeader& h );

	protected:

};
}
