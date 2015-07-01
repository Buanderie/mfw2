//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

// Catch
#include "catch.hpp"

// MFW
#include "monadic.h"

#include <unistd.h>

#include <thread>

using namespace std;

    std::shared_ptr<monadic::Pin> p = std::shared_ptr<monadic::Pin>(new monadic::ZMQPin( monadic::Pin::PIN_MODE_INPUT ));

    std::shared_ptr<monadic::Pin> p2 = std::shared_ptr<monadic::Pin>(new monadic::ZMQPin( monadic::Pin::PIN_MODE_OUTPUT ));

void pinsend(std::shared_ptr<monadic::Pin> p)
{
		p->setup();
		for(;;)
		{
				cout << "pinsend.." << endl;
		char * popo = new char[256];
		    p->send( popo, 256 );
		sleep(1);
		}
}

//TEST_CASE( "Pins can be created", "[pin]" ) {
int main( int argc, char** argv )
{
	p->setup();
    monadic::Link l( p, p2 );

	sleep(1);

	thread t1(&pinsend, p2);

	for(;;)
	{
		cout << "receive ?" << endl;
		char * popo = new char[ 256 ];
		size_t s = p->receive( popo );
		sleep(1);
	}

	t1.join();


    //REQUIRE( 1 == 4 );
	return 0;
}
