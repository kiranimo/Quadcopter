#include "module_data_wrapper.h"

void ModuleDataWrapper::AddModuleData(std::shared_ptr<ModuleData> module_data) {
  _module_data.push_back(module_data);
}

ModuleData* ModuleDataWrapper::GetModuleData(std::string module_name) {
  for (int i = 0; i < (int)_module_data.size(); i++) { 
    if (_module_data[i].get()->name == module_name) {
      std::lock_guard<std::mutex> lg(_m);
      return _module_data[i].get();
    }
  }
  std::cout << "Module: " << module_name << " not found" << std::endl;
  return nullptr;
}

void ModuleDataWrapper::SetModuleData(
    std::shared_ptr<ModuleData> module_data, std::string module_name) {
  for (int i = 0; i < (int)_module_data.size(); i++) {
    if (_module_data[i].get()->name == module_name) {
      {
       std::lock_guard<std::mutex> lg(_m);
      _module_data[i] = module_data;
      }
      break;
    }
  }
}
