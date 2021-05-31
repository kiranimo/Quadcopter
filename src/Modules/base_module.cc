#include "base_module.h"

// BaseModule::BaseModule(std::string module_name) {
//   _module_name = module_name;
// }

std::shared_ptr<ModuleData> BaseModule::Init() {
  std::cout << "Initializing module: " << _module_name << "\n" << std::endl;
  std::shared_ptr<ModuleData> out = std::make_shared<ModuleData>("base_module");
  return out;
}

void BaseModule::Poll(ModuleDataWrapper* data) {
}

void BaseModule::Loop(ModuleDataWrapper* data) {
  for (int i = 0; i < 5; i++)  {
    Poll(data);
  }
}

void BaseModule::CreateTimer(std::string timer_name) {

}
