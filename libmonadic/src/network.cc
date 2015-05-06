
// Internal
#include "network.h"

using namespace std;

monadic::Guid monadic::Network::addNode(monadic::Node *node, const monadic::Guid &guid)
{
    monadic::Guid definitiveGuid = guid;
    if( guid == monadic::Guid() )
    {
        monadic::GuidGenerator gen;
        definitiveGuid = gen.newGuid();
    }
    _nodes.insert( make_pair(definitiveGuid, node) );
    return definitiveGuid;
}

