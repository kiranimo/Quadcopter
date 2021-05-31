#include "module_manager.h"

ModuleManager::ModuleManager() {
   
}

void ModuleManager::AddModule(std::unique_ptr<BaseModule> module) {
  _modules.push_back(std::move(module));
}

void ModuleManager::InitModules() {
  for (int i = 0; i < (int)_modules.size(); i++) {
    _module_data_wrapper.AddModuleData(_modules[i].get()->Init());
  } 
}

void ModuleManager::StartModules() {

  std::cout << "Starting threads" << std::endl;
  std::vector<std::thread> module_threads;
  for (int i = 0; i < (int)_modules.size(); i++) {
    std::cout << "Starting " << _modules[i].get()->_module_name << std::endl;
    module_threads.push_back(
        std::thread(&BaseModule::Loop, _modules[i].get(), &_module_data_wrapper));
  }
 
  for (auto &th : module_threads) {
    th.join();
  }
  
}

