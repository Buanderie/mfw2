#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

// Catch
#include "catch.hpp"

// MFW
#include <monadic.h>

#include <unistd.h>
#include <thread>
#include <iostream>
#include <cxxabi.h>

#include "objectproperty.h"

using namespace monadic;
using namespace std;

TEST_CASE( "Numbers can be serialized/deserialized", "[binary_serialization]" )
{
    monadic::objects::basic::Number* n = new monadic::objects::basic::Number(45.0);
    std::shared_ptr<monadic::ObjectBlob> blob = n->serialize();
    monadic::objects::basic::Number* n2 = new monadic::objects::basic::Number(0.0);
    n2->deserialize(blob);
    REQUIRE( n->value() == n2->value() );
}

TEST_CASE( "Strings can be serialized/deserialized", "[binary_serialization]" )
{
    monadic::objects::basic::String* str = new monadic::objects::basic::String("Testing");
    std::shared_ptr<monadic::ObjectBlob> blob = str->serialize();
    monadic::objects::basic::String* str2 = new monadic::objects::basic::String("Nicely");
    str2->deserialize(blob);
    REQUIRE( str->value() == str2->value() );
}

TEST_CASE( "Booleans can be serialized/deserialized", "[binary_serialization]" )
{

}
