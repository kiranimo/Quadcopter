#include <gtest/gtest.h>
#include <iostream>

#include "module_data.h"

class TestData {
  public:
  int ctr = 0;
  double time = 1.43;
};

TEST(ModuleDataTest, BasicFunctionality) {
  std::cout.flush();

  TestData test_data;

  ModuleDataCollection mdc;
  mdc.AddModuleData(test_data, "test_data");
  test_data.time = 2.2;
  TestData test_data_out = mdc.GetModuleData<TestData>("test_data");
  EXPECT_EQ(test_data_out.ctr, 0);
  EXPECT_EQ(test_data_out.time, 1.43);
    
  mdc.SetModuleData(test_data, "test_data");
  test_data_out = mdc.GetModuleData<TestData>("test_data");
  EXPECT_EQ(test_data_out.ctr, 0);
  EXPECT_EQ(test_data_out.time, 2.2);

  EXPECT_EQ(mdc.GetModuleData<TestData>("test_data").time, 2.2);
}
