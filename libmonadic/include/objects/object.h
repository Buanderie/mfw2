#pragma once

// Internal
#include "abstractfactory.h"
#include "../serialization/binaryserializable.h"

// STL
#include <string>

namespace monadic
{
        class Object : public serialization::BinarySerializable
	{
		public:
			Object(){}
			virtual ~Object(){}
                        virtual std::string typeName();

		private:

		protected:
			std::string _type;

	};

        typedef std::shared_ptr<Object> PtrObject;

        /** factory interface */
        class ObjectFactory {
            public:
                virtual PtrObject make_me() = 0;
        };
        typedef std::shared_ptr<ObjectFactory> PtrObjectFactory;

        /** generic factory */
        template <class T>
        class GenericObjectFactory : public ObjectFactory {
        public:
            virtual PtrObject make_me() {
                PtrObject p(new T);
                return p;
            }
        };

        /** make one. */
        static PtrObject create(const char * name);

        /** register a factory with a given name */
        static void register_me(const char * name, PtrObjectFactory fac);

        template <class _s>
        class StaticObjectRegistry {
        public:
            StaticObjectRegistry(const char * name) {
                PtrObjectFactory pf (new GenericObjectFactory<_s>);
                register_me(name, pf);
            }

        #define MONADIC_REGISTER_INTERFACE(name, type) \
            namespace {     \
                static monadic::StaticObjectRegistry<type> fac(name); \
            };
        };

}
