#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "module_data_wrapper.h"
#include <memory>
#include <variant>
#include "test_module.h"

TEST(DataWrapperTests, BasicFunctionality) {

  std::cout.flush();

  TestModuleDataType test_data;  
  test_data.dt = 0.;
  EXPECT_EQ(test_data.dt, 0.);


  std::shared_ptr<ModuleData> test_module_data = std::make_shared<ModuleData>("test_module");
  test_module_data.get()->push(test_data); 
  EXPECT_EQ(test_module_data.get()->get<TestModuleDataType>().dt, 0.);
  std::shared_ptr<ModuleData> test_module_data2 = std::make_shared<ModuleData>("test_module2");
  test_module_data2.get()->push(test_data); 

  ModuleDataWrapper mdw;
  mdw.AddModuleData(test_module_data);
  mdw.AddModuleData(test_module_data2);
  
  mdw.SetModuleData(test_module_data, "test_module");
  EXPECT_EQ(mdw.GetModuleData("test_module")->get<TestModuleDataType>().dt, 0.);
}


