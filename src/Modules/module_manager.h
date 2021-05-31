#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

#include <vector>
#include <thread>
#include <iostream>
#include <memory>
#include "base_module.h"
#include "module_data_wrapper.h"

// Class responsible for managing the instatiation and running of
// all derived modules.
class ModuleManager {

  public:
    // transfer ownership of module class to ModuleManager and
    // add to container
    void AddModule(std::unique_ptr<BaseModule> module);

    // Go through and initialize all of the modules. This also
    // adds the module specific data to the shared wrapper.
    void InitModules();

    // Create and start threads for each module, and have them
    // start their Loop().
    void StartModules();

  private:
   
    // Container for derived modules.
    std::vector<std::unique_ptr<BaseModule>> _modules;

    // Container for all module specific data 
    ModuleDataWrapper _module_data_wrapper;
};


#endif
