#ifndef CONTROLS_MODULE_H
#define CONTROLS_MODULE_H

#include <eigen3/Eigen/Dense>
#include <vector>
#include <thread>
#include <iostream>
#include "base_module.h"

using Eigen::VectorXd;

class ControlsModuleData : public ModuleData {
  ControlsModuleData();
  VectorXd position;
  VectorXd velocity;
    
}; 

class ControlsModule : public BaseModule {
  public:
    void Init() override;

  private:
    void Poll(ShareModuleData* data) override;
};

#endif
