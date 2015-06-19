#pragma once

// Internal
#include "node.h"
#include "pin.h"
#include "guid.h"
#include "identifiable.h"

// STL
#include <vector>
#include <memory>

namespace monadic
{
    class Node : public monadic::Identifiable
    {
    public:
        Node(){}
        virtual ~Node(){}

    private:
        void addPin( monadic::Pin* pin, const monadic::Guid& guid=monadic::Guid() );

    protected:
        std::vector< std::shared_ptr<monadic::Pin> > _pins;

    };
}
