
// Internal
#include "core/link.h"

namespace monadic
{
	bool Link::dataAvailable()
	{
		return true;
	}

	void Link::send( std::unique_ptr<Packet> packet )
	{
		// Write to internal buffer
		// Signal connected pin of available data
	}
 
    std::unique_ptr<Packet> Link::recv()
	{
		// Read from internal buffer
		return nullptr;
	}
}
