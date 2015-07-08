#pragma once

// Internal
#include "node.h"
#include "pin.h"
#include "guid.h"
#include "identifiable.h"

// STL
#include <vector>
#include <map>
#include <memory>

namespace monadic
{
    class Node : public monadic::Identifiable
    {
    public:
		// ctor/dtor
        Node(){}
        virtual ~Node(){}

		//
                virtual void init(){}

		// Pins access
		std::shared_ptr<Pin> pin( const std::string& label );

                //


    private:

    protected:
		// Methods
		std::shared_ptr<Pin> addPin( const std::string& pinLabel, monadic::Pin::PinMode pinMode );
		bool checkPinLabelAvailability( const std::string& pinLabel );

		// Variables
                std::map< std::string, std::shared_ptr<monadic::Pin> >      _pins;
                std::map< std::string, std::shared_ptr<monadic::Object> >   _attributes;

    };
}
