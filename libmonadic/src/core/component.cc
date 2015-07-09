
// Internal
#include "core/component.h"

// STL
#include <set>

using namespace std;

namespace monadic
{
    std::shared_ptr<Port> Component::addPort( const std::string& pinLabel, monadic::Port::PinMode pinMode )
	{
		if( _pins.find( pinLabel ) != _pins.end() )
		{
			// throws
			return nullptr;
		}

        std::shared_ptr<monadic::Port> ret = std::shared_ptr<monadic::Port>(new Port(pinMode, pinLabel));
		_pins.insert( make_pair(pinLabel, ret) );

		return ret;
	}

    std::shared_ptr<Port> Component::port( const std::string& pinLabel )
	{
		if( _pins.find( pinLabel ) == _pins.end() )
			// throw, maybe ?
			return nullptr;
		else
		{
			return _pins[ pinLabel ];
		}
	}
}
