#include <iostream>       // std::cout
#include <vector>
#include "Modules/module_data_wrapper.h"
#include <memory>
#include "Modules/base_module.h"
#include "Modules/module_manager.h"
#include "Modules/test_module.h"



int main() {

  std::cout.flush();

  TestModuleDataType test_data;  
  test_data.dt = 0.;

  std::shared_ptr<ModuleData> test_module_data1 = std::make_shared<ModuleData>("test_module1");
  test_module_data1.get()->push(test_data); 
  std::shared_ptr<ModuleData> test_module_data2 = std::make_shared<ModuleData>("test_module2");
  test_module_data2.get()->push(test_data); 
 
  std::unique_ptr<BaseModule> test_module1(new TestModule("test_module1", "test_module1"));
  std::unique_ptr<BaseModule> test_module2(new TestModule("test_module2", "test_module1"));

  ModuleManager manager;
  manager.AddModule(std::move(test_module1), test_module_data1);
  manager.AddModule(std::move(test_module2), test_module_data2);

  manager.InitModules();
  manager.StartModules();


  return 0;
}

  


