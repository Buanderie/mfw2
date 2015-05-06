
// Internal
#include <monadic.h>

// PicoTest
#include "picotest.h"

TEST( monadic, foo )
{
    EXPECT_EQ( foo(), 0 );
}

TEST( azer, azazaz )
{
    EXPECT_EQ( 1, 1 );
}

TEST( azer, ererer )
{
    EXPECT_EQ( 1, 5 );
}

TEST( azer, rtrtrt )
{
    EXPECT_EQ( 1, 5 );
}

int main( int argc, char** argv )
{
    RUN_ALL_TESTS();
}
