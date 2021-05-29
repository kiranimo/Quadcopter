#include "module_manager.h"


void ModuleManager::AddModules(std::vector<BaseModule*> modules) {
  _modules = modules;
}

void ModuleManager::InitModules() {
  for (int i = 0; i < (int)_modules.size(); i++) {
    _modules[i]->Init();
  } 
}

void ModuleManager::StartModules() {
  std::cout << "Starting threads\n" << std::endl;
  std::vector<std::thread> module_threads;
  for (int i = 0; i < (int)_modules.size(); i++) {
    module_threads.push_back(
        std::thread(&BaseModule::Loop, *_modules[i]));
  }
 
  for (auto &th : module_threads) {
    th.join();
  }

  // std::thread mod1_thread(&BaseModule::Loop, _test_module);
  // mod1_thread.join();

}

