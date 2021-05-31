#include "base_module.h"
// Generic implementation of BaseModule

std::shared_ptr<ModuleData> BaseModule::Init() {
  std::cout << "Initializing module: " << _module_name << "\n" << std::endl;
  std::shared_ptr<ModuleData> out = std::make_shared<ModuleData>("base_module");
  return out;
}

void BaseModule::Poll(ModuleDataWrapper* data) {
}

void BaseModule::Loop(ModuleDataWrapper* data) {
  // TODO: kirencaldwell - this eventually should become a while loop
  // that runs until the program is terminated.
  for (int i = 0; i < 1000; i++)  {
    Poll(data);
  }
}

