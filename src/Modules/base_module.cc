#include "base_module.h"
// Generic implementation of BaseModule

void BaseModule::Init(std::shared_ptr<ModuleDataCollection> data) {
  std::cout << "Initializing module: " << _module_name << "\n" << std::endl;
}

void BaseModule::Poll(std::shared_ptr<ModuleDataCollection> data) {
}

void BaseModule::Loop(std::shared_ptr<ModuleDataCollection> data) {
  // TODO: kirencaldwell - this eventually should become a while loop
  // that runs until the program is terminated.
  for (int i = 0; i < 100; i++)  {
    Poll(data);
  }
}

