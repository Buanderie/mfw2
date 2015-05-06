#pragma once

// Internal
#include "node.h"
#include "pin.h"
#include "guid.h"

// STL
#include <map>

namespace monadic
{
    class Node
    {
    public:
        Node(){}
        virtual ~Node(){}

    private:
        void addPin( monadic::Pin* pin, const monadic::Guid& guid=monadic::Guid() );

    protected:
        std::map< monadic::Guid, monadic::Pin* > _pins;

    };
}
