#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

#include <vector>
#include <thread>
#include <iostream>
#include <memory>
#include "base_module.h"
#include "module_data.h"

// Class responsible for managing the instatiation and running of
// all derived modules.
class ModuleManager {

  public:
    // transfer ownership of module class to ModuleManager and
    // add to container
    void AddModule(std::unique_ptr<BaseModule> module);

    // Go through and initialize all of the modules. This also
    // adds the module specific data to the shared container.
    void InitModules();

    // Create and start threads for each module, and have them
    // start their Loop().
    void StartModules(double time_gain=1.0);

  private:
   
    // Container for derived modules.
    std::vector<std::unique_ptr<BaseModule>> _modules;

    // Container for all module specific data 
    std::shared_ptr<ModuleDataCollection> _module_data_container = std::make_shared<ModuleDataCollection>();
};


#endif
