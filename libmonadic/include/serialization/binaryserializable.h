#pragma once

// Internal
#include "../objects/objectblob.h"

// STL
#include <memory>

namespace monadic
{
    namespace serialization
    {
	class BinarySerializable
	{
		public:
			BinarySerializable(){}
			virtual ~BinarySerializable(){}
			
			virtual void deserialize( std::shared_ptr<monadic::ObjectBlob> blob )=0;
			virtual std::shared_ptr<monadic::ObjectBlob> serialize()=0;

		private:

		protected:

	};
    }
}
