
// Internal
#include "core/node.h"

// STL
#include <set>

using namespace std;

namespace monadic
{
	std::shared_ptr<Pin> Node::addPin( const std::string& pinLabel, monadic::Pin::PinMode pinMode )
	{
		if( _pins.find( pinLabel ) != _pins.end() )
		{
			// throws
			return nullptr;
		}

		std::shared_ptr<monadic::Pin> ret = std::shared_ptr<monadic::Pin>(new Pin(pinMode, pinLabel));
		_pins.insert( make_pair(pinLabel, ret) );

		return ret;
	}

	std::shared_ptr<Pin> Node::pin( const std::string& pinLabel )
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
