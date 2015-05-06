#pragma once

// Internal
#include "guid.h"
#include "node.h"

// STL
#include <map>

namespace monadic
{
    // A network is also a node that can be reused in other networks
    class Network : public monadic::Node
    {
    public:
        Network(){}
        virtual ~Network(){}

        // Node management
        monadic::Guid addNode( monadic::Node* node, const monadic::Guid& guid = monadic::Guid() );

    private:

    protected:

        // Collection of nodes
        std::map< monadic::Guid, monadic::Node* > _nodes;

    };
}
