#pragma once

// STL
#include <string>

namespace monadic
{
class Packet
{
	public:
		Packet( const std::string& senderName, const std::string& receiverName, void* data, size_t dataSize );
		virtual ~Packet();

	private:
		std::string _senderName;
		std::string _receiverName;
		void*		_data;
		size_t		_dataSize;

	protected:

};
}
