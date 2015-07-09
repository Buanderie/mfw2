#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

// Catch
#include "catch.hpp"

// MFW
#include <monadic.h>
#include "dobj.h"

#include <unistd.h>
#include <thread>

#include <cereal/archives/xml.hpp>

using namespace monadic;

TEST_CASE( "Node default constructor", "[node]" )
{
    /*
    std::shared_ptr<monadic::BaseObject> ptr = std::make_shared<monadic::DerivedObject>();
    std::ofstream os( "polymorphism_test.xml" );
        cereal::XMLOutputArchive oarchive( os );

        oarchive( ptr );
*/
}
