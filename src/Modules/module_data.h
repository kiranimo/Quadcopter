#ifndef MODULE_DATA_H 
#define MODULE_DATA_H 

#include <vector>
#include <iostream>
#include <mutex>
#include <memory>
#include <eigen3/Eigen/Dense>
#include <variant>
#include "telemetry_logging.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;

// TODO: kirencaldwell - these data classes should be generalized,
// especially the logging thing
class ControlsData : public TelemetryLogging {
  public:
    VectorXd u = VectorXd::Zero(3);
    double dt = 0.;

    ControlsData() {
      OpenFile("controls_module.csv");
      AddSignal("u", &u);
      AddSignal("dt", &dt);
      CreateLogHeader();
    };
    ~ControlsData() {
      EndLogging();
    };
};

class SimulationData : public TelemetryLogging {
  public:
    VectorXd x;
    VectorXd v;
    double t = 0.;
    double dt = 0.;

    SimulationData() {
      J = MatrixXd::Zero(3,3);
      OpenFile("simulation_module.csv");
      AddSignal("pos", &x);
      AddSignal("vel", &v);
      AddSignal("t", &t);
      AddSignal("dt", &dt);
      CreateLogHeader();
    };
    ~SimulationData() {
      EndLogging();
    };
};


class ModuleDataCollection {
  public:
    ControlsData controls_data;
    SimulationData simulation_data;

};


#endif
