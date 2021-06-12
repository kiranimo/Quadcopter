#ifndef PRINT_MODULE_H
#define PRINT_MODULE_H

#include <eigen3/Eigen/Dense>
#include <vector>
#include <iostream>
#include <chrono>
#include "src/base_module.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;

class PrintModule : public BaseModule {
  public:
    PrintModule();
    void Init(std::shared_ptr<ModuleDataCollection> data) override;

  private:
    void Poll(std::shared_ptr<ModuleDataCollection> data) override;

};

#endif


