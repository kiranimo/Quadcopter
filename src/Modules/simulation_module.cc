#include "simulation_module.h"

SimulationModule::SimulationModule() {
  _module_name = "Simulation Module";
}

void SimulationModule::Init(std::shared_ptr<ModuleDataCollection> data) {
  // Init simulation module data
  _x = VectorXd::Ones(3);
  _v = VectorXd::Zero(3);
  _dt = 0.01;
  _u = VectorXd::Zero(3);

  std::lock_guard<std::mutex> guard(_module_mutex);
  data->simulation_data.x = _x;
  data->simulation_data.v = _v;
  std::cout << data-> simulation_data.x << std::endl;
}

void SimulationModule::Poll(std::shared_ptr<ModuleDataCollection> data) {
  
  std::lock_guard<std::mutex> guard(_module_mutex);
  _x = data->simulation_data.x;
  _v = data->simulation_data.v;
  _u = data->controls_data.u;

  VectorXd v_dot = -2*_x - 0.5*_v + _u;
  
  data->simulation_data.x = data->simulation_data.x + _dt*data->simulation_data.v;
  data->simulation_data.v = data->simulation_data.v + _dt*v_dot; 
  std::cout << "u = " << data->controls_data.u << std::endl;
}
