#pragma once

// Internal
#include "guid.h"

namespace monadic
{
	class Identifiable
	{
		public:
			Identifiable()
			{

			}

			virtual ~Identifiable()
			{

			}

			monadic::Guid& guid()
			{
				return _guid;
			}

			void setGuid( const monadic::Guid& guid )
			{
				_guid = guid;
			}

			void resetGuid()
			{
				monadic::GuidGenerator gen;
				_guid = gen.newGuid();				
			}

		protected:
			monadic::Guid _guid;

	};
}
