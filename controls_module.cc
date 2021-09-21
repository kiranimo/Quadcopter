#include "controls_module.h"

ControlsModule::ControlsModule() {
  _module_name = "Controls Module";
}

void ControlsModule::Init(std::shared_ptr<ModuleDataCollection> data) {
  // Initialize controls module data
  // std::lock_guard<std::mutex> g(data->mut);
  _controls_data.u << 0, 0, 0;
  data->AddModuleData(_controls_data, "controls_data"); 
}

void ControlsModule::Poll(std::shared_ptr<ModuleDataCollection> data) {
  // std::lock_guard<std::mutex> g(data->mut);
  double x = data->GetModuleData<SimulationModuleDataType>("simulation_data").x;
  double v = data->GetModuleData<SimulationModuleDataType>("simulation_data").v;
 
  _controls_data.u[0] = -5*x -3*v;
  data->SetModuleData(_controls_data, "controls_data");
  
}
