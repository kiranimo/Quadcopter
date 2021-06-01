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
    void Init(std::shared_ptr<ModuleDataCollection> data) override;

  private:
    void Poll(std::shared_ptr<ModuleDataCollection> data) override;
    VectorXd _x;
    VectorXd _v;
    double _current_time;
};

#endif
