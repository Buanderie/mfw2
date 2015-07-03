
// Internal
#include "core/node.h"

// STL
#include <set>

using namespace std;

namespace monadic
{
	std::shared_ptr<Pin> Node::addPin( const std::string& pinLabel, monadic::Pin::PinMode pinMode )
	{
		if( !checkPinLabelAvailability( pinLabel ) )
			return nullptr;

		std::shared_ptr<monadic::Pin> ret = std::shared_ptr<monadic::Pin>(new Pin( pinMode, pinLabel ));
		
		_pins.push_back( ret );
		return ret;
	}

	bool Node::checkPinLabelAvailability( const std::string& pinLabel )
	{
		bool ret = true;
		for( std::shared_ptr<Pin> p : _pins )
		{
			if( p->label() == pinLabel )
			{	
				ret = false;
				break;
			}
		}
		return ret;
	}
}
