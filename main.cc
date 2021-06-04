#include <iostream>       // std::cout
#include <vector>
#include <memory>

#include "src/base_module.h"
#include "src/module_manager.h"
#include "src/module_data.h"
#include "controls_module.h"
#include "simulation_module.h"
#include "src/print_module.h"
#include "src/logging_module.h"

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

  


