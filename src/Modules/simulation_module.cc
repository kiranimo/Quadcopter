#include "simulation_module.h"

SimulationModule::SimulationModule() {
  _module_name = "Simulation Module";
}

std::shared_ptr<ModuleData> SimulationModule::Init() {
  // Init simulation module data
  _simulation_data.x = VectorXd::Ones(3);
  _simulation_data.v = VectorXd::Zero(3);
  _dt = 0.1;
  _u = VectorXd::Zero(3);

  // write to module data container
  std::shared_ptr<ModuleData> out = std::make_shared<ModuleData>(_module_name);
  out.get()->push(_simulation_data);
  return out;
}

void SimulationModule::Poll(ModuleDataWrapper* mdw) {
  std::shared_ptr<ModuleData> simulation_data_container =
    std::make_shared<ModuleData>("Simulation Module");

  try {
    _u = mdw->GetModuleData("Controls Module")->get<ControlsModuleDataType>().u;
  }
  catch (std::exception& e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  _simulation_data.x = _simulation_data.x + _dt*_simulation_data.v;
  _simulation_data.v = _simulation_data.v + _dt*(-5*_simulation_data.x - 2*_simulation_data.v + _u);
  
  std::cout << "x = " << _simulation_data.x << std::endl;

  simulation_data_container.get()->push(_simulation_data);
  mdw->SetModuleData(simulation_data_container, "Simulation Module");
}
