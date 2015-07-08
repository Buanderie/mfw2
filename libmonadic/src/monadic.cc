
// Internal
#include "monadic.h"
#include "objects/object.h"

#include "objects/basic/number.h"
#include "interface.h"
#include "impl1.h"

#include <fstream>
#include <iostream>
#include <memory>

using namespace std;
int foo()
{
    std::shared_ptr<interface> i = interface::create("impl1");
    i->do_something();
}
