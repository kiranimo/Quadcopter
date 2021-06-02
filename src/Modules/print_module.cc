#include "print_module.h"

PrintModule::PrintModule() {
  _module_name = "Print Module";
}

void PrintModule::Init(std::shared_ptr<ModuleDataCollection> data) {
  _module_period_ms = std::chrono::milliseconds(500);
}

void PrintModule::Poll(std::shared_ptr<ModuleDataCollection> data) {
  std::lock_guard<std::mutex> guard(_module_mutex);
  std::cout << "===============================" << std::endl;
  std::cout << "t = " << data->simulation_data.simulation_time << std::endl;
  std::cout << "x = " << data->simulation_data.x << std::endl;
  std::cout << "u = " << data->controls_data.u << std::endl;

  data->controls_data.tlm.LogSignals();
}

