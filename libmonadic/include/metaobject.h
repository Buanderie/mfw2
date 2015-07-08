#pragma once

// Stores information about a type. Things like the name of a type,
// size in bytes, and other things are important to keep track of.
struct TypeInfo
{
    const char* name;
    int size;

    // You can add an array of TypeInfo pointers here to represent
    // relationships between different types (like inheritance parent
    // child relationships, or struct/class data members).
};

// Used to store a pointer to a TypeInfo struct as a static parameter
// of a templated static function. This lets the user lookup TypeInfo
// pointers given a template type parameter.
template < typename T >
struct TypeLookupByTemplate
{
    static TypeInfo* GetType( TypeInfo* typeInfo )
    {
        static TypeInfo* s_typeInfo = NULL;

        if ( !s_typeInfo )
        {
            s_typeInfo = typeInfo;
        }

        return s_typeInfo;
    }
};

