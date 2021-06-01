#ifndef BASE_MODULE_H
#define BASE_MODULE_H

#include <vector>
#include <iostream>
#include <memory>
#include "module_data.h"

// Generic module type for all other modules to be derived from.
class BaseModule {
  public:
    // Generic template for initialization, should return the module
    // specific datatype. 
    virtual void Init(std::shared_ptr<ModuleDataCollection> data);

    // Generic function that calls Poll(), should be started by
    // the process managing all of the modules. Since Loop() calls
    // Poll(), we need to pass the variable containing all of the module
    // information.
    void Loop(std::shared_ptr<ModuleDataCollection> data);

    // TODO: kirencaldwell - should probably make a getter for this.
    // Module name.
    std::string _module_name;
  protected:
    // Generic function called by Loop(), this is where the meat of the
    // module lives.
    // Need to pass the variable containing all of the modules
    // information.
    virtual void Poll(std::shared_ptr<ModuleDataCollection> data);

    std::mutex _module_mutex;
};

#endif
