// MFW
#include <monadic.h>

#include <unistd.h>
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;
using namespace monadic;

class ReceiverNode : public monadic::Component
{
	public:
        ReceiverNode()
		{
                Component::addPort( "in", Port::PORT_MODE_INPUT );
                Component::addPort( "out",Port::PORT_MODE_OUTPUT );
		}

        virtual void tick()
        {
            start = std::chrono::system_clock::now();
            std::vector< std::unique_ptr<Packet> > ps = this->port("in")->poll();
            end = std::chrono::system_clock::now();
            double elapsed_seconds = std::chrono::duration_cast<std::chrono::microseconds>
                                         (end-start).count();
            cout << "Receiver_elapsed_millis=" << elapsed_seconds/1000.0 << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2));
        }

	private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

	protected:
};

class SenderNode : public monadic::Component
{
    public:
        SenderNode()
        {
                Component::addPort( "in", Port::PORT_MODE_INPUT );
                Component::addPort( "out",Port::PORT_MODE_OUTPUT );
        }

        virtual void tick()
        {
            std::shared_ptr<Packet> p(new Packet("s", "r", nullptr));
            this->port("out")->send( p );
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

    private:

    protected:
};

void ticktock( std::shared_ptr<Component> n )
{
    while(1)
    {
        n->tick();
    }
}

int main( int argc, char** argv )
{
    foo();
     monadic::objects::basic::Number n(45.0);
     //n.type();

    std::shared_ptr<Component> nodea( new SenderNode );
    std::shared_ptr<Component> nodeb( new ReceiverNode );

    Connection l( nodea->port("out"), nodeb->port("in") );
    l.resetGuid();

    std::thread t1 = std::thread(ticktock, nodea);
    std::thread t2 = std::thread(ticktock, nodeb);

    while(1)
    sleep(3);

    return 1;

}
