#pragma once

// Internal
#include "node.h"

namespace monadic
{
    class ScriptedNode : public monadic::Node
    {
    public:
        ScriptedNode(){}
        virtual ~ScriptedNode(){}

        static void fromFile( const std::string& filePath );
        static void fromString( const std::string& src );

    private:

    protected:

    };
}
