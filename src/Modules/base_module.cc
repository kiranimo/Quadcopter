#include "base_module.h"

BaseModule::BaseModule() {}

BaseModule::BaseModule(std::string module_name) {
  _module_name = module_name;
}

void BaseModule::Init() {
  std::cout << "Initializing module: " << _module_name << "\n" << std::endl;
}

void BaseModule::Poll() {
  std::cout << "Module: " << _module_name << " gets called every iteration!\n" << std::endl;
}

void BaseModule::Loop() {
  for (int i = 0; i < 20; i++)  {
    Poll();
  }
}

void BaseModule::CreateTimer(std::string timer_name) {

}
