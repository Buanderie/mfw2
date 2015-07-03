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

		virtual void build(){}

    private:

    protected:
		// Methods
		std::shared_ptr<Pin> addPin( const std::string& pinLabel, monadic::Pin::PinMode pinMode );
		bool checkPinLabelAvailability( const std::string& pinLabel );

		// Variables
        std::vector< std::shared_ptr<monadic::Pin> > _pins;

    };
}
