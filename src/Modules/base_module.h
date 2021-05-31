#ifndef BASE_MODULE_H
#define BASE_MODULE_H

#include <vector>
#include <iostream>
#include <memory>
#include "module_data_wrapper.h"

class BaseModule {
  public:
    // Generic template for initialization, should return the module
    // specific datatype. 
    virtual std::shared_ptr<ModuleData> Init();

    // Generic function that calls Poll(), should be started by
    // the process managing all of the modules. Since Loop() calls
    // Poll(), we need to pass the variable containing all of the module
    // information.
    void Loop(ModuleDataWrapper* data);

    // TODO: kirencaldwell - should probably make a getter for this.
    // Module name.
    std::string _module_name;
  protected:
    // Generic function called by Loop(), this is where the meat of the
    // module lives.
    // Need to pass the variable containing all of the modules
    // information.
    virtual void Poll(ModuleDataWrapper* data);
};

#endif
