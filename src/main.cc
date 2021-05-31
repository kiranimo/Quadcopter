#include <iostream>       // std::cout
#include <vector>
#include "Modules/module_data_wrapper.h"
#include <memory>
#include "Modules/base_module.h"
#include "Modules/module_manager.h"

struct TestModuleDataType {
  double dt;
};

class TestModule : public BaseModule {
  public: 
    TestModule(std::string module_name) {
      _module_name = module_name;
    }
    void Init() override {
    }
  protected:
    void Poll(ModuleDataWrapper* data) override {
      std::string module_rw_name = "test_module1";

      std::shared_ptr<ModuleData> module_data_container = 
        std::make_shared<ModuleData>(module_rw_name);
      ModuleData* md_ptr = data->GetModuleData(module_rw_name);
      if (md_ptr != nullptr) {
        _module_data.dt = md_ptr->get<TestModuleDataType>().dt;
        _module_data.dt++;
        std::cout << "Module: " <<  _module_name << ", dt = " << _module_data.dt << std::endl; 
        module_data_container.get()->push(_module_data); 
        data->SetModuleData(module_data_container, module_rw_name);
      }
      else {
        std::cout << "nullptr" << std::endl;
      }
    } 

    TestModuleDataType _module_data;
};


int main() {

  std::cout.flush();

  TestModuleDataType test_data;  
  test_data.dt = 0.;

  std::shared_ptr<ModuleData> test_module_data1 = std::make_shared<ModuleData>("test_module1");
  test_module_data1.get()->push(test_data); 
  std::shared_ptr<ModuleData> test_module_data2 = std::make_shared<ModuleData>("test_module2");
  test_module_data2.get()->push(test_data); 
 
  std::unique_ptr<BaseModule> test_module1(new TestModule("test_module1"));
  std::unique_ptr<BaseModule> test_module2(new TestModule("test_module2"));

  ModuleManager manager;
  manager.AddModule(std::move(test_module1), test_module_data1);
  manager.AddModule(std::move(test_module2), test_module_data2);

  manager.InitModules();
  manager.StartModules();


  return 0;
}

  


