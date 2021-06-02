#include <iostream>       // std::cout
#include <vector>
#include <memory>

#include "Modules/base_module.h"
#include "Modules/module_manager.h"
#include "Modules/module_data.h"
#include "Modules/controls_module.h"
#include "Modules/simulation_module.h"
#include "Modules/print_module.h"
#include "Modules/logging_module.h"

int main() {

  std::cout.flush();
 
  // create modules 
  std::unique_ptr<BaseModule> controls_module(new ControlsModule);
  std::unique_ptr<BaseModule> simulation_module(new SimulationModule);
  std::unique_ptr<BaseModule> print_module(new PrintModule);
  std::unique_ptr<BaseModule> logging_module(new LoggingModule);

  // add modules to manager
  ModuleManager manager;
  manager.AddModule(std::move(controls_module));
  manager.AddModule(std::move(simulation_module));
  manager.AddModule(std::move(print_module));
  manager.AddModule(std::move(logging_module));

  // init modules
  manager.InitModules();

  // start modules
  manager.StartModules();
  
  return 0;
}

  


