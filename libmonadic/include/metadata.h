#pragma once

#include <string>
#include <cstddef>

class Metadata
{
public:
    Metadata( const std::string& name, std::size_t size )
        :_name(name), _size(size)
    {}

private:
    std::string _name;
    std::size_t _size;
};
