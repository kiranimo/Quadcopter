#include "controls_module.h"

ControlsModule::ControlsModule() {
  _module_name = "Controls Module";
}

std::shared_ptr<ModuleData> ControlsModule::Init() {
  // Initialize controls module data
  _controls_data.u = VectorXd::Ones(3);
  _x = VectorXd::Zero(3);
  _v = VectorXd::Zero(3);


  // Write to module data container
  std::shared_ptr<ModuleData> out = std::make_shared<ModuleData>(_module_name);
  out.get()->push(_controls_data);
  return out;
}

void ControlsModule::Poll(ModuleDataWrapper* mdw) {
  std::shared_ptr<ModuleData> controls_data_container = 
    std::make_shared<ModuleData>("Controls Module");
 
  //_controls_data.u = 2*_controls_data.u; 
  
  try {
    _x = mdw->GetModuleData("Simulation Module")->get<SimulationModuleDataType>().x;
    _v = mdw->GetModuleData("Simulation Module")->get<SimulationModuleDataType>().v;
  }
  catch (std::exception& e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
  _controls_data.u = 20*(-_x) - 10*_v;

  controls_data_container.get()->push(_controls_data);
  mdw->SetModuleData(controls_data_container, "Controls Module");
}
