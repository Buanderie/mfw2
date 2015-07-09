
// Internal
#include "core/connection.h"

#include <iostream>
using namespace std;

#include <spdlog/spdlog.h>

namespace monadic
{
    bool Connection::dataAvailable()
	{
        return (_buffer->blobs() > 0);
	}

    void Connection::send(std::shared_ptr<Packet> packet)
	{

        spdlog::get("file_logger")->critical( "Packet sent on connection ID=" ) << guid().toString();

        std::lock_guard<mutex> lck(_bufferMtx);
        if( _buffer->available() < packet->packetDataSize() )
        {
            // Wait for enough space (blocking mode)
            cout << "Not enough space..." << endl;
        }

        cout << "Sending... _buffer.blobs()=" << _buffer->blobs() << endl;
        char* popo = new char[156];
        _buffer->push( popo, 156 );
        delete popo;
        cout << "Sent!.. _buffer.blobs()=" << _buffer->blobs() << endl;
        _to->signal_data();
	}
 
    std::unique_ptr<Packet> Connection::recv()
	{
		// Read from internal buffer
        if( _buffer->blobs() > 0 )
        {
            size_t blobSize = _buffer->peekSize();
            if( blobSize > 0 )
            {
            uint8_t* blobBuffer = new uint8_t[blobSize];
            _buffer->pop( blobBuffer );
            delete blobBuffer;
            }
        }
		return nullptr;
	}
}
