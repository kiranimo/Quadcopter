#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include "module_manager.h"
#include "test_module.h"

TEST(ModuleManagerTests, BasicFunctionality) {

  std::cout.flush();

  std::unique_ptr<BaseModule> test_module1(new TestModule);
  std::unique_ptr<BaseModule> test_module2(new TestModule);

  ModuleManager manager;
  manager.AddModule(std::move(test_module1));
  manager.AddModule(std::move(test_module2));

  manager.InitModules();
  manager.StartModules();


}
