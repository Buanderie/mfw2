#pragma once

// Internal
#include "guid.h"
#include "component.h"

// STL
#include <map>

namespace monadic
{
    // A network is also a node that can be reused in other networks
    class Network : public monadic::Component
    {
    public:
        Network(){}
        virtual ~Network(){}

        // Node management
        monadic::Guid addNode( monadic::Component* node, const monadic::Guid& guid = monadic::Guid() );

    private:

    protected:

        // Collection of nodes
        std::map< monadic::Guid, monadic::Component* > _nodes;

    };
}
