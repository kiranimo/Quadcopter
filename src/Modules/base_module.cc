#include "base_module.h"
// Generic implementation of BaseModule

void BaseModule::Init(std::shared_ptr<ModuleDataCollection> data) {
  std::cout << "Initializing module: " << _module_name << "\n" << std::endl;
}

void BaseModule::Poll(std::shared_ptr<ModuleDataCollection> data) {
}

void BaseModule::Loop(std::shared_ptr<ModuleDataCollection> data) {
  // get start time
  _start_time = std::chrono::steady_clock::now();
  // get current time
  auto now = std::chrono::steady_clock::now();
  
  while (now-_start_time < _total_runtime)  {
    Poll(data);

    // wait until the next period start
    now = std::chrono::steady_clock::now();
    auto iterations = (now - _start_time) / _module_period_ms;
    auto next_start = _start_time + (iterations + 1) * _module_period_ms;
    std::this_thread::sleep_until(next_start);
  }
}

// set the total runtime for this module
void BaseModule::SetModuleRuntime(std::chrono::milliseconds total_runtime) {
  _total_runtime = total_runtime;
}

// get the module period
std::chrono::milliseconds BaseModule::GetModulePeriod() {
  return _module_period_ms;
}
