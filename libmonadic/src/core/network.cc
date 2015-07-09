
// Internal
#include "core/network.h"

using namespace std;

monadic::Guid monadic::Network::addNode(monadic::Component *node, const monadic::Guid &guid)
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

