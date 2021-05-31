#ifndef SIMULATION_MODULE_H
#define SIMULATION_MODULE_H

#include <eigen3/Eigen/Dense>
#include <vector>
#include <iostream>
#include <chrono>
#include "base_module.h"
#include "controls_module.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;

struct SimulationModuleDataType {
  VectorXd x;
  VectorXd v;
};

class SimulationModule : public BaseModule {
  public:
    SimulationModule();
    std::shared_ptr<ModuleData> Init() override;

  private:
    void Poll(ModuleDataWrapper* mdw) override;
    SimulationModuleDataType _simulation_data;
    double _dt;
    VectorXd _u;
};

#endif
