#include "simulation_module.h"
#include <eigen3/Eigen/Dense>
#include <chrono>

using Eigen::VectorXd;

SimulationModule::SimulationModule() {
  _module_name = "simulation_module";
  _module_period_ms = std::chrono::milliseconds(1);
  InitModuleData();
  _module_data.Add<double>("x", 1);
  _module_data.Add<double>("v", 0);
  _module_data.Add<double>("t", 0);
}

void SimulationModule::Poll(std::shared_ptr<ModuleDataCollection> data) {
  
  VectorXd u = 
   data->GetModuleData("controls_module").Get<VectorXd>("u");
  double x = _module_data.Get<double>("x");
  double v = _module_data.Get<double>("v");
  double t = _module_data.Get<double>("t");
  double v_dot = -2*x - 0.5*v + u[0];

  _module_data.Set<double>("x", x+_dt_ms/1000*v);
  _module_data.Set<double>("v", v+_dt_ms/1000*v_dot);
  _module_data.Set<double>("t", t+_dt_ms/1000);

}
