#include "print_module.h"
#include "controls_module.h"
#include "simulation_module.h"

PrintModule::PrintModule() {
  _module_name = "Print Module";
}

void PrintModule::Init(std::shared_ptr<ModuleDataCollection> data) {
  _module_period_ms = std::chrono::milliseconds(500);
}

void PrintModule::Poll(std::shared_ptr<ModuleDataCollection> data) {
  std::lock_guard<std::mutex> guard(_module_mutex);
  std::cout << "===============================" << std::endl;
  std::cout << "t = " << 
    data->GetModuleData<SimulationModuleDataType>("simulation_data").t << std::endl;
  std::cout << "x = " << 
    data->GetModuleData<SimulationModuleDataType>("simulation_data").x << std::endl;

}

