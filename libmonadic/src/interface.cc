/**
 * @file interface.cpp
 * @author Peter Krusche
 *
 */

#include "interface.h"
#include "abstractfactory.h"

#include <map>
#include <string>

typedef std::map<std::string, Pfactory> FMAP;
typedef boost::shared_ptr<FMAP> PFMAP;

struct FactorySingleton {
    static FMAP & get() {
        static FMAP factory_map;
        return factory_map;
    }
} fs;

/** make one. */
Pinterface interface::create(const char * name) {
    std::string n(name);
    FMAP::iterator it = fs.get().find(n);
    if (it == fs.get().end()) {
    throw "I don't know this type.";
    }
    return it->second->make_me();
}

/** register a simulator factory with a given name */
void interface::register_me(const char * name, Pfactory fac) {
    fs.get()[std::string(name)] = fac;
}
