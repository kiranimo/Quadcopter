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

struct ControlsData {
  VectorXd u = VectorXd::Zero(3);
};

struct SimulationData {
  VectorXd x;
  VectorXd v;
};


struct ModuleDataCollection {
  ControlsData controls_data;
  SimulationData simulation_data;

};


#endif
