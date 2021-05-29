#include <gtest/gtest.h>

#include <iostream>
#include "module_manager.h"
#include "base_module.h"



TEST(ModuleManagerTest, WillExecutePoll) {
  BaseModule module1("mod1");
  BaseModule module2("mod2");
  BaseModule module3("mod3");
  
  std::vector<BaseModule*> modules;
  modules.push_back(&module1);
  modules.push_back(&module2);
  modules.push_back(&module3);
  ModuleManager module_manager;
  module_manager.AddModules(modules);
  module_manager.InitModules();
  module_manager.StartModules();
}

