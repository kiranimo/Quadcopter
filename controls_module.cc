#include "controls_module.h"
#include <eigen3/Eigen/Dense>

using Eigen::VectorXd;

ControlsModule::ControlsModule() {
  _module_name = "controls_module";
  InitModuleData();
  _module_data.Add<VectorXd>("u", VectorXd::Zero(3));
}

void ControlsModule::Poll(std::shared_ptr<ModuleDataCollection> data) {
  double x = data->GetModuleData("simulation_module").Get<double>("x");
  double v = data->GetModuleData("simulation_module").Get<double>("v");

  VectorXd u(3);
  u << -5*x-3*v, 0, 0;
  _module_data.Set<VectorXd>("u", u);
  
}
