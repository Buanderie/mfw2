
// C
#include <cstdlib>
#include <cstring>

// STL
#include <iostream>

// INTERNAL
#include "objects/objectblob.h"
#include "objects/object.h"

using namespace std;

monadic::ObjectBlob::ObjectBlob(Object *obj, const size_t blobSize)
    :_typeName(obj->typeName()), _blobSize(blobSize)
{
    _data = 0;
    reserve( _blobSize );
    markObjectName();
    _pushedSize = 0;
    _poppedSize = 0;
}

monadic::ObjectBlob::ObjectBlob(void *ptr, std::size_t size)
{
    _data = 0;
    if( size <= monadic::ObjectBlob::OBJECT_BLOB_NAME_LENGTH )
    {
        // throw something
    }
    else
    {
        _blobSize = size - monadic::ObjectBlob::OBJECT_BLOB_NAME_LENGTH;
        reserve( _blobSize );
        memcpy( _data, ptr, size );
        size_t strNameSize = (size_t)(_data[0]);
        char* strName = new char[ strNameSize + 1 ];
        //strncpy( strName, (const char*)(_data + 1), strNameSize );
		memcpy((void*)(strName), (const void*)(_data + 1), strNameSize);
		strName[ strNameSize ] = 0;
        _typeName = std::string( strName );
        delete[] strName;
        _poppedSize = 0;
        _pushedSize = _blobSize;
    }
}

monadic::ObjectBlob::~ObjectBlob()
{
    free( (void*)_data );
}

void *monadic::ObjectBlob::data()
{
    return (void*)(_data);
}

std::size_t monadic::ObjectBlob::data_size()
{
    return monadic::ObjectBlob::OBJECT_BLOB_NAME_LENGTH + _blobSize;
}


void monadic::ObjectBlob::reserve(const size_t size)
{
    _data = (unsigned char*)realloc( (void*)_data, monadic::ObjectBlob::OBJECT_BLOB_NAME_LENGTH + size );
    _blobSize = size;
}

void monadic::ObjectBlob::pushArray(void *ptr, size_t size)
{
    if( size + _pushedSize >= _blobSize )
        reserve( size + _blobSize );

    unsigned char* dPtr = (_data + OBJECT_BLOB_NAME_LENGTH + _pushedSize );
    memcpy( dPtr, ptr, size );
    _pushedSize += size;
}

void monadic::ObjectBlob::popArray(void *ptr, size_t size )
{
    unsigned char* dPtr = (_data + OBJECT_BLOB_NAME_LENGTH + _poppedSize );
    memcpy( ptr, dPtr, size );
    _poppedSize += size;
}

string monadic::ObjectBlob::getType()
{
    return this->_typeName;
}


void monadic::ObjectBlob::markObjectName()
{
    _data[0] = _typeName.size();
    memcpy( _data + 1, (void*)(_typeName.c_str()), _typeName.size() );
}
