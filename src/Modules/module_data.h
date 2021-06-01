#ifndef MODULE_DATA_H 
#define MODULE_DATA_H 

#include <vector>
#include <iostream>
#include <mutex>
#include <memory>
#include <eigen3/Eigen/Dense>
#include <variant>

using Eigen::VectorXd;
using Eigen::MatrixXd;

class BaseModuleData {

};

class ControlsData {
  public:
    VectorXd u = VectorXd::Zero(3);
};

class SimulationData {
  public:
    VectorXd x;
    VectorXd v;
    double simulation_time = 0.;
};


class ModuleDataCollection {
  public:
    ControlsData controls_data;
    SimulationData simulation_data;

};


#endif
