#pragma once

// Internal
#include "port.h"
#include "bipbuffer.h"
#include "identifiable.h"

// STL
#include <memory>
#include <mutex>

namespace monadic
{
    class Connection : public Identifiable
    {
    public:
        Connection( std::shared_ptr<monadic::Port> from, std::shared_ptr<monadic::Port> to )
            :_from(from), _to(to)
        {
            from->onConnect(this);
            to->onConnect(this);
            _buffer = new BipBuffer(1000000, BipBuffer::BIPBUFFER_OVERWRITE);
        }
        
        virtual ~Connection()
        {

        }

        std::shared_ptr<monadic::Port> getFromPin();
        std::shared_ptr<monadic::Port> getToPin();

        void send( std::shared_ptr<Packet> packet );
        std::unique_ptr<Packet> recv();

        bool dataAvailable();

    private:
        std::shared_ptr<monadic::Port> _from;
        std::shared_ptr<monadic::Port> _to;

        BipBuffer*      _buffer;
        std::mutex      _bufferMtx;

    protected:

    };
}
