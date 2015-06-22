#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

// Catch
#include "catch.hpp"

// MFW
#include "monadic.h"

TEST_CASE( "Pins can be created", "[pin]" ) {

    monadic::Pin * p = new monadic::ZMQPin(monadic::Pin::PIN_MODE_OUTPUT);
    p->setup();

    REQUIRE( 2 == 1 );

}
