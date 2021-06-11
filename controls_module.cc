#include "controls_module.h"

ControlsModule::ControlsModule() {
  _module_name = "Controls Module";
}

void ControlsModule::Init(std::shared_ptr<ModuleDataCollection> data) {
  // Initialize controls module data
  _x = VectorXd::Zero(3);
  _v = VectorXd::Zero(3);
  _current_time = 0.;
  std::lock_guard<std::mutex> guard(_module_mutex);
  data->controls_data.u = VectorXd::Zero(3);
}

void ControlsModule::Poll(std::shared_ptr<ModuleDataCollection> data) {
  std::lock_guard<std::mutex> guard(_module_mutex);
  _x = data->simulation_data.x;
  _v = data->simulation_data.v;

  data->controls_data.u = -5*(data->simulation_data.x-0.5*VectorXd::Ones(3)) - 4*data->simulation_data.v;
  
  
}
