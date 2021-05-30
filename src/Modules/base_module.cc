#include "base_module.h"

// ================================================================== //


// ====================================================================//
BaseModule::BaseModule() {}

BaseModule::BaseModule(std::string module_name) {
  _module_name = module_name;
}

void BaseModule::Init() {
  std::cout << "Initializing module: " << _module_name << "\n" << std::endl;
}

void BaseModule::Poll(ShareModuleData* data) {
}

void BaseModule::Loop(ShareModuleData* data) {
  for (int i = 0; i < 5; i++)  {
    Poll(data);
  }
}

void BaseModule::CreateTimer(std::string timer_name) {

}
