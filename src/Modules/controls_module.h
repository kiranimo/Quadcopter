#ifndef CONTROLS_MODULE_H
#define CONTROLS_MODULE_H

#include <eigen3/Eigen/Dense>
#include <vector>
#include <iostream>
#include "base_module.h"
#include "simulation_module.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;

struct ControlsModuleDataType {
  VectorXd u;
};

class ControlsModule : public BaseModule {
  public:
    ControlsModule();
    std::shared_ptr<ModuleData> Init() override;

  private:
    void Poll(ModuleDataWrapper* mdw) override;
    ControlsModuleDataType _controls_data;
    VectorXd _x;
    VectorXd _v;
};

#endif
