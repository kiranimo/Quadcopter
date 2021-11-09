#include "module_manager.h"

void ModuleManager::AddModule(std::unique_ptr<BaseModule> module) {
  // transfers ownership of specific module to manager.
  _modules.push_back(std::move(module));
}

void ModuleManager::InitModules() {
  // Initialize module and add module specific datatype to container.
  for (int i = 0; i < (int)_modules.size(); i++) {
    _modules[i].get()->Init(_module_data_container);
  } 
}

void ModuleManager::StartModules(double time_gain) {
  std::cout << "Starting threads" << std::endl;

  // vector of threads
  std::vector<std::thread> module_threads;
  for (int i = 0; i < (int)_modules.size(); i++) {
    std::cout << "Starting " << _modules[i].get()->_module_name << std::endl;
    // initialize threads
    module_threads.push_back(
        std::thread(&BaseModule::Loop, _modules[i].get(), _module_data_container, time_gain));
  }
 
  // join threads
  for (auto &th : module_threads) {
    th.join();
  }
  std::cout << "========= Finished Running ==========" << std::endl;  
}

