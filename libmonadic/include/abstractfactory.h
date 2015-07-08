#pragma once

// STL
#include <memory>
#include <map>
#include <vector>

namespace monadic
{
    template <class T>
    class AbstractFactory
    {
    public:
        virtual ~AbstractFactory(){}
        virtual std::shared_ptr<T> create() = 0;
    };

    template <class DerivedType, class BaseType>
    class GenericFactory : public AbstractFactory<BaseType>
    {
    public:
        std::shared_ptr<BaseType> create()
        {
            std::shared_ptr<BaseType> ptr = std::make_shared<DerivedType>();
            return ptr;
        }
    };

    template <class Key, class T>
    class GenericObjectRegistry
    {
    public:
        void insert(Key Id, AbstractFactory<T>* Fn)
        {
            FunctionMap[Id] = Fn;
        }

        std::shared_ptr<T> create(Key Id)
        {
            if( FunctionMap.find( Id ) == FunctionMap.end() )
            {
                // TODO
                // throw dem::ObjectRegistryException();
                return 0;
            }
            else
                return FunctionMap[Id]->create();
        }

        std::vector< Key > listKeys()
        {
            std::vector< Key > ret;
            typename std::map< Key, std::shared_ptr<AbstractFactory<T>> >::iterator i = FunctionMap.begin();
            while( i != FunctionMap.end() )
            {
                ret.push_back( (*i).first );
                ++i;
            }
            return ret;
        }

        void removeAll()
        {
            typename std::map< Key, AbstractFactory<T>* >::iterator i = FunctionMap.begin();
            while (i != FunctionMap.end())
            {
                delete (*i).second;
                ++i;
            }
            FunctionMap.clear();
        }

        virtual ~GenericObjectRegistry()
        {
            removeAll();
        }

    private:
        std::map<Key, AbstractFactory<T>* > FunctionMap;
    };
}
