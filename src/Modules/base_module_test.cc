#include <gtest/gtest.h>
#include <iostream>

#include "base_module.h"
#include "share_module_data.h"

class DerivedModule : public BaseModule {
  public:
    DerivedModule() {
      _module_name = "derived_module";
    };
    void Init() override {
      std::cout << "Initializing DerivedModule\n" << std::endl;
    };
  private:
    void Poll(ShareModuleData* data) override {
      ModuleData module_data = data->GetModuleData("derived_module");
      std::cout << "ctr = " << module_data.ctr << std::endl; 
    };
      
};



TEST(BaseModuleTests, BasicFunctionality) {
  BaseModule test_module("test_module");
  test_module.Init();
  
}

TEST(BaseModuleTests, DerivedModuleTest) {
  std::cout.flush();

  ShareModuleData smd = ShareModuleData();
  ModuleData md;
  md.name = "derived_module";
  std::vector<ModuleData*> all_md;
  all_md.push_back(&md);

  smd.AddModuleData(all_md);

  DerivedModule derived_module = DerivedModule();
  derived_module.Init();
  derived_module.Loop(&smd);
}


