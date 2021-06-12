#ifndef SIMULATION_MODULE_H
#define SIMULATION_MODULE_H

#include <eigen3/Eigen/Dense>
#include <vector>
#include <iostream>
#include <chrono>

#include "src/base_module.h"
#include "controls_module.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;

class SimulationModuleDataType {
  public:
  double x;
  double v;
  double t;
}; 

class SimulationModule : public BaseModule {
  public:
    SimulationModule();
    void Init(std::shared_ptr<ModuleDataCollection> data) override;

  private:
    void Poll(std::shared_ptr<ModuleDataCollection> mdw) override;
    
    SimulationModuleDataType _simulation_data;
};

#endif
