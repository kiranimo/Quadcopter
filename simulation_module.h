#ifndef SIMULATION_MODULE_H
#define SIMULATION_MODULE_H

#include <iostream>
#include <memory>
#include "src/base_module.h"


class SimulationModule : public BaseModule {
  public:
    SimulationModule();

  private:
    void Poll(std::shared_ptr<ModuleDataCollection> mdw) override;
    
};

#endif
