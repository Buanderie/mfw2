#pragma once

/**
 * @file interface_impl_1.cpp
 * @author Peter Krusche
 *
 */

#include "interface.h"

#include <iostream>

class interface_impl_1 : public interface {
public:
    interface_impl_1() {}
        virtual ~interface_impl_1() {}

        virtual void do_something() {
                std::cout << "Hi there, I am implementation number 1." << std::endl;
        }

};

REGISTER_INTERFACE("impl1", interface_impl_1);
