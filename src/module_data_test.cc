#include <gtest/gtest.h>
#include <iostream>

#include "base_module_data.h"
#include "module_data.h"


TEST(ModuleDataTest, BasicFunctionality) {
  std::cout.flush();

  BaseModuleData test_module_data;
  test_module_data.Init("test_module_data");
  test_module_data.Set<double>("time", 2.2);

  ModuleDataCollection mdc;
  
  mdc.AddModuleData(test_module_data, "test_data");

  BaseModuleData test_data_out = mdc.GetModuleData("test_data");
  EXPECT_EQ(test_data_out.Get<double>("time"), 2.2);
  
  test_data_out.Set<double>("time", 4);
  mdc.SetModuleData(test_data_out, "test_data");
  EXPECT_EQ(mdc.GetModuleData("test_data").Get<double>("time"), 4);
}
