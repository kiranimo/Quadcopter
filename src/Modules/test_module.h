#include <iostream>
#include <memory>
#include "base_module.h"

class TestModule : public BaseModule {
  public: 
    TestModule() {
       _module_name = "test_module";
    }
    void Init(std::shared_ptr<ModuleDataCollection> data) override {
       _ctr = 0;
    };

    int _ctr;
  private:
    void Poll(std::shared_ptr<ModuleDataCollection> mdw) override {
       _ctr++;
    };
};
