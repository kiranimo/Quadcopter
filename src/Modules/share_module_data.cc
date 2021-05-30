#include "share_module_data.h"

ShareModuleData::ShareModuleData() {
  _ctr = 0;
}

int ShareModuleData::GetCtr() {
  std::lock_guard<std::mutex> lg(_m);
  return _ctr;
}

void ShareModuleData::SetCtr(int val) {
  std::lock_guard<std::mutex> lg(_m);
  _ctr = val;
}

void ShareModuleData::AddModuleData(std::vector<ModuleData*> module_data) {
  _module_data = module_data;
  for (int i = 0; i < (int)_module_data.size(); i++) {
    std::cout << "Adding Module: " << _module_data[i]->name << "\n" << std::endl;
  }
}


ModuleData ShareModuleData::GetModuleData(std::string module_name) {
  for (int i = 0; i < (int)_module_data.size(); i++) { 
    if (_module_data[i]->name == module_name) {
      std::lock_guard<std::mutex> lg(_m);
      return *_module_data[i];
    }
  }
  return ModuleData();
}

void ShareModuleData::SetModuleData(ModuleData* module_data, std::string module_name) {
  for (int i = 0; i < (int)_module_data.size(); i++) {
    if (_module_data[i]->name == module_name) {
      std::lock_guard<std::mutex> lg(_m);
      _module_data[i] = module_data;
    }
  }
}
