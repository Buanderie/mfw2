#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

// Catch
#include "catch.hpp"

// MFW
#include <monadic.h>

#include <unistd.h>
#include <thread>

using namespace monadic;

class TestNode : public monadic::Node
{
	public:
		TestNode()
		{
				Node::addPin( "in", Pin::PIN_MODE_INPUT );
				Node::addPin( "out",Pin::PIN_MODE_OUTPUT );
		}

	private:

	protected:
};

TEST_CASE( "Node default constructor", "[node]" )
{
	TestNode node();
}