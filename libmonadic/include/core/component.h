#pragma once

// Internal
#include "component.h"
#include "port.h"
#include "guid.h"
#include "identifiable.h"

// STL
#include <vector>
#include <map>
#include <memory>

namespace monadic
{
    class Component : public monadic::Identifiable
    {
    public:
		// ctor/dtor
        Component(){}
        virtual ~Component(){}

		//
                virtual void init(){}

		// Pins access
                std::shared_ptr<Port> port( const std::string& label );

                //
                virtual void tick()=0;


    private:

    protected:
		// Methods
                std::shared_ptr<Port> addPort( const std::string& pinLabel, monadic::Port::PinMode pinMode );
		bool checkPinLabelAvailability( const std::string& pinLabel );

		// Variables
                std::map< std::string, std::shared_ptr<monadic::Port> >      _pins;
                std::map< std::string, std::shared_ptr<monadic::Object> >   _attributes;

    };
}
