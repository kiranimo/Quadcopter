#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "share_module_data.h"

TEST(ShareModuleDataTests, BasicFunctionality) {
  
  ModuleData md1; md1.name = "module1"; md1.ctr = 1;
  ModuleData md2; md2.name = "module2"; md2.ctr = 2;
  std::vector<ModuleData*> all_md;
  all_md.push_back(&md1); all_md.push_back(&md2);

  ShareModuleData smd;
  smd.AddModuleData(all_md);

  ModuleData md1n; md1n.name = "module1"; md1n.ctr = 3;
  ModuleData md2n; md2n.name = "module2"; md2n.ctr = 4;

  ModuleData md1_ctr = smd.GetModuleData("module1");
  EXPECT_EQ(md1_ctr.ctr, 1); 
  ModuleData md2_ctr = smd.GetModuleData("module2");
  EXPECT_EQ(md2_ctr.ctr, 2); 

  smd.SetModuleData(&md1n, "module1");
  md1_ctr = smd.GetModuleData("module1");
  EXPECT_EQ(md1_ctr.ctr, 3); 
}

