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
  auto now = std::chrono::steady_clock::now();
  // how long should we run for
  // TODO: kirencaldwell - don't hardcode this shit
  auto runtime = std::chrono::seconds(5);
  
  // TODO: kirencaldwell - this eventually should become a while loop
  // that runs until the program is terminated.
  while (now-_start_time < runtime)  {
    Poll(data);

    // wait until the next period start
    now = std::chrono::steady_clock::now();
    auto iterations = (now - _start_time) / _module_period_ms;
    auto next_start = _start_time + (iterations + 1) * _module_period_ms;
    std::this_thread::sleep_until(next_start);
  }
}

