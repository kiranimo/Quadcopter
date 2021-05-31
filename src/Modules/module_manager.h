#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

#include <vector>
#include <thread>
#include <iostream>
#include <memory>
#include "base_module.h"
#include "module_data_wrapper.h"

class ModuleManager {

  public:
    ModuleManager();
    void AddModule(std::unique_ptr<BaseModule> module);
    void InitModules();
    void StartModules();

  private:
   
    std::vector<std::unique_ptr<BaseModule>> _modules;

    ModuleDataWrapper _module_data_wrapper;
};


#endif
