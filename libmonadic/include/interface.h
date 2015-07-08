/**
 * @file interface.h
 * @author Peter Krusche
 *
 */

#ifndef INTERFACE_H
#define INTERFACE_H

#include <boost/shared_ptr.hpp>

class interface;
typedef std::shared_ptr<interface> Pinterface;

/** factory interface */
template< class BaseClass >
class AbstractFactory {
    public:
        virtual std::shared_ptr<BaseClass> make_me() = 0;
};
typedef std::shared_ptr<AbstractFactory<interface>> Pfactory;

/** generic factory */
template <class _s>
class GenericFactory : public AbstractFactory<interface> {
public:
    virtual Pinterface make_me() {
        Pinterface p(new _s());
        return p;
    }
};

/** the interface we want to implement elsewhere */
class interface {
    public:
    virtual ~interface() {}

    virtual void do_something() = 0;

  /** make one. */
        static Pinterface create(const char * name);

        /** register a simulator factory with a given name */
        static void register_me(const char * name, Pfactory fac);
};

/** registration by name */
template <class _s>
class register_factory {
public:
    register_factory(const char * name) {
        Pfactory pf (new GenericFactory<_s>);
        interface::register_me(name, pf);
    }
#define REGISTER_INTERFACE(name, type) \
    namespace {     \
        static register_factory<type> fac(name); \
    };
};

#endif
