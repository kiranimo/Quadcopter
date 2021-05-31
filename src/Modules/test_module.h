#include <iostream>
#include "module_manager.h"
#include "base_module.h"
#include "module_data_wrapper.h"
#include <memory>

struct TestModuleDataType {
  double dt;
};

class TestModule : public BaseModule {
  public: 
    TestModule(std::string module_name, std::string module_rw_name) {
      _module_name = module_name;
      _module_rw_name = module_rw_name;
    }
    void Init() override {
    }
  protected:
    void Poll(ModuleDataWrapper* data) override {

      std::shared_ptr<ModuleData> module_data_container = 
        std::make_shared<ModuleData>(_module_rw_name);
      ModuleData* md_ptr = data->GetModuleData(_module_rw_name);
      if (md_ptr != nullptr) {
        _module_data.dt = md_ptr->get<TestModuleDataType>().dt;
        _module_data.dt++;
        std::cout << "Module: " <<  _module_name << ", dt = " << _module_data.dt << std::endl; 
        module_data_container.get()->push(_module_data); 
        data->SetModuleData(module_data_container, _module_rw_name);
      }
      else {
        std::cout << "nullptr" << std::endl;
      }
    } 
    std::string _module_rw_name;
    TestModuleDataType _module_data;
};
