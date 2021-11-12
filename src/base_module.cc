#include "base_module.h"
#include <thread>
// Generic implementation of BaseModule

void BaseModule::Init(std::shared_ptr<ModuleDataCollection> data) {
  std::cout << "Initializing module: " << _module_name << std::endl;
  data->AddModuleData(_module_data, _module_name);
}

// to be filled in by specific module
void BaseModule::Poll(std::shared_ptr<ModuleDataCollection> data) {
}

// This function calls the module specific Poll methods
void BaseModule::Loop(std::shared_ptr<ModuleDataCollection> data, double time_gain) {
  // get start time
  _start_time = std::chrono::steady_clock::now();
  // get current time
  auto now = std::chrono::steady_clock::now();
  auto previous_time = now; 
  while (now-_start_time < _total_runtime/time_gain)  {
    now = std::chrono::steady_clock::now();
    auto elapsed_time = time_gain*(now-_start_time);
    Poll(data);
    data->SetModuleData(_module_data, _module_name);
    _module_data.LogTelemetry();
    
    // get time between iterations
    _dt_ms = std::chrono::duration_cast<
      std::chrono::duration<double, std::milli>>(time_gain*(now-previous_time)).count();

    // compute time to wait until next iteration
    previous_time = now;
    auto next_start = now + _module_period_ms/time_gain;
    // wait until the next period start
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

// compute module runtime
double BaseModule::GetRuntimeMilliseconds() {
  auto now = std::chrono::steady_clock::now();
  return std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(now-_start_time).count();
} 
