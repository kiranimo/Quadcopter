#include "base_module.h"

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

BaseModule::BaseModule() {}

BaseModule::BaseModule(std::string module_name) {
  _module_name = module_name;
}

void BaseModule::Init() {
  std::cout << "Initializing module: " << _module_name << "\n" << std::endl;
}

void BaseModule::Poll(ShareModuleData* data) {
  int ctr = data->GetCtr();
  ctr++;
  data->SetCtr(ctr);
  std::cout << "Module: " << _module_name << " increased ctr to: " << data->GetCtr() << std::endl;
}

void BaseModule::Loop(ShareModuleData* data) {
  
  for (int i = 0; i < 20; i++)  {
    Poll(data);
  }
}

void BaseModule::CreateTimer(std::string timer_name) {

}
