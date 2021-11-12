#include <iostream>
#include <memory>
#include "base_module.h"

class TestModule : public BaseModule {
  public: 
    TestModule() {
       _module_name = "test_module";
       _module_data.Add<double>("ctr", 0);
    }

  private:
    void Poll(std::shared_ptr<ModuleDataCollection> mdw) override {
      double ctr = mdw->GetModuleData(_module_name).Get<double>("ctr");
      ctr++;
      _module_data.Set<double>("ctr", ctr);

    };
};
