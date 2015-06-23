#pragma once

// Internal
#include "pin.h"

// STL
#include "memory"

namespace monadic
{
    class Link
    {
    public:
        Link( std::shared_ptr<monadic::Pin> from, std::shared_ptr<monadic::Pin> to )
        {
            from->connect(to);
            to->connect(from);
        }
        
        virtual ~Link(){}

        std::shared_ptr<monadic::Pin> getFromPin();
        std::shared_ptr<monadic::Pin> getToPin();

    private:
        std::shared_ptr<monadic::Pin> _from;
        std::shared_ptr<monadic::Pin> _to;

    protected:

    };
}
