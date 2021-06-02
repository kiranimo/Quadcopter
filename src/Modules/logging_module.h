#ifndef LOGGING_MODULE_H
#define LOGGING_MODULE_H

#include <eigen3/Eigen/Dense>
#include <vector>
#include <iostream>
#include <chrono>
#include "base_module.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;

class LoggingModule : public BaseModule {
  public:
    LoggingModule();
    void Init(std::shared_ptr<ModuleDataCollection> data) override;

  private:
    void Poll(std::shared_ptr<ModuleDataCollection> data) override;

};

#endif

