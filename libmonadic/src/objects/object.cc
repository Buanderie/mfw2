
// Internal
#include "objects/object.h"

// Cereal
#include <cereal/archives/binary.hpp>

namespace monadic
{
		
template<class Archive>
void serialize(	Archive & archive,
				Object & m)
{
		  archive( m.u );
}

}
