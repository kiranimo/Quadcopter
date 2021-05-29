#include <iostream>       // std::cout
#include <vector>
#include "Modules/base_module.h"
#include "Modules/module_manager.h"

int main() {
  
  BaseModule module1("mod1");
  BaseModule module2("mod2");
  BaseModule module3("mod3");
  std::vector<BaseModule*> modules;
  modules.push_back(&module1);
  modules.push_back(&module2);

  ModuleManager module_manager;
  module_manager.AddModules(modules);

  module_manager.InitModules();
  module_manager.StartModules();  
  return 0;
}

