#pragma once

// Internal
#include "../core/component.h"

namespace monadic
{
    class ScriptedComponent : public monadic::Component
    {
    public:
        ScriptedComponent(){}
        virtual ~ScriptedComponent(){}

        static void fromFile( const std::string& filePath );
        static void fromString( const std::string& src );

    private:

    protected:

    };
}
