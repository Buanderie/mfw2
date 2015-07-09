
// Internal
#include "monadic.h"
#include "objects/object.h"

#include "objects/basic/number.h"
#include "interface.h"
#include "impl1.h"

#include <fstream>
#include <iostream>
#include <memory>

#include <spdlog/spdlog.h>

using namespace std;

int foo()
{
    // std::shared_ptr<interface> i = interface::create("impl1");
    // i->do_something();
    auto file_logger = spdlog::rotating_logger_mt("file_logger", "log.txt", 1048576 * 5, 3);
}
