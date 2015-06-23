#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

// Catch
#include "catch.hpp"

// MFW
#include "monadic.h"

TEST_CASE( "Pins can be created", "[pin]" ) {

    std::shared_ptr<monadic::Pin> p = std::shared_ptr<monadic::Pin>(new monadic::ZMQPin( monadic::Pin::PIN_MODE_INPUT ));
    std::shared_ptr<monadic::Pin> p2 = std::shared_ptr<monadic::Pin>(new monadic::ZMQPin( monadic::Pin::PIN_MODE_OUTPUT ));
    monadic::Link l( p, p2 );
    
    REQUIRE( 1 == 4 );

}
