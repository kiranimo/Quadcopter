#include "simulation_module.h"

SimulationModule::SimulationModule() {
  _module_name = "Simulation Module";
  _module_period_ms = std::chrono::milliseconds(1);
}

void SimulationModule::Init(std::shared_ptr<ModuleDataCollection> data) {
  // Init simulation module data
  _simulation_data.x = 1;
  _simulation_data.v = 0;
  _simulation_data.t = 0;

  // std::lock_guard<std::mutex> guard(_module_mutex);
  // std::scoped_lock(data.get()->data_mutex);
  // std::lock_guard<std::mutex> g(data->mut);
  data->AddModuleData(_simulation_data, "simulation_data");
}

void SimulationModule::Poll(std::shared_ptr<ModuleDataCollection> data) {
  
  // std::lock_guard<std::mutex> guard(_module_mutex);
  // std::scoped_lock(data.get()->data_mutex);
  // std::lock_guard<std::mutex> g(data->mut);
  VectorXd u = 
   data->GetModuleData<ControlsModuleDataType>("controls_data").u;

  double v_dot = -2*_simulation_data.x - 0.5*_simulation_data.v + u[0];

  _simulation_data.x += _dt_ms/1000*_simulation_data.v; 
  _simulation_data.v += _dt_ms/1000*v_dot;  
  _simulation_data.t += _dt_ms/1000;

  data->SetModuleData(_simulation_data, "simulation_data");
}
