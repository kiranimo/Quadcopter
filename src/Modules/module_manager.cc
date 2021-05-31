#include "module_manager.h"

ModuleManager::ModuleManager() {
   
}

void ModuleManager::AddModule(std::unique_ptr<BaseModule> module,
   std::shared_ptr<ModuleData> module_data) {
  _modules.push_back(std::move(module));
  _module_data_wrapper.AddModuleData(module_data);
}

void ModuleManager::InitModules() {
  for (int i = 0; i < (int)_modules.size(); i++) {
    _modules[i].get()->Init();
  } 
}

void ModuleManager::StartModules() {

  std::cout << "Starting threads\n" << std::endl;
  std::vector<std::thread> module_threads;
  for (int i = 0; i < (int)_modules.size(); i++) {
    module_threads.push_back(
        std::thread(&BaseModule::Loop, _modules[i].get(), &_module_data_wrapper));
  }
 
  for (auto &th : module_threads) {
    th.join();
  }
  
}

