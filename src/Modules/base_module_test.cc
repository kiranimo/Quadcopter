#include <gtest/gtest.h>
#include <iostream>

#include "base_module.h"
#include "module_data_wrapper.h"
#include "test_module.h"


TEST(BaseModuleTests, BasicFunctionality) {
  std::cout.flush();

  TestModuleDataType test_data;  
  test_data.dt = 0.;

  std::shared_ptr<ModuleData> test_module_data = std::make_shared<ModuleData>("test_module");
  test_module_data.get()->push(test_data); 
  
  ModuleDataWrapper mdw;
  mdw.AddModuleData(test_module_data);
 
  std::unique_ptr<BaseModule> test_module(new TestModule("test_module", "test_module"));
  test_module.get()->Init();
  test_module.get()->Loop(&mdw);
  EXPECT_EQ(mdw.GetModuleData("test_module")->get<TestModuleDataType>().dt, 5);
  EXPECT_EQ(mdw.GetModuleData("test_module")->get<TestModuleDataType>().dt, 5);

}

