#include <gtest/gtest.h>
#include <iostream>

#include "base_module.h"
#include "test_module.h"


TEST(BaseModuleTests, BasicFunctionality) {
  std::cout.flush();

  TestModule test_module;   

  std::shared_ptr<ModuleDataCollection> mdw = std::make_shared<ModuleDataCollection>();
  test_module.Init(mdw);
  test_module.SetModuleRuntime(std::chrono::milliseconds(5));
  test_module.Loop(mdw);

  EXPECT_EQ(test_module._ctr, 2);
  EXPECT_EQ(test_module.GetModulePeriod(), std::chrono::milliseconds(5));
}



