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
class ControlsData {
  public:
    VectorXd u = VectorXd::Zero(3);
    double dt = 0.;

    TelemetryLogging tlm;
    
    ControlsData() {
      tlm.OpenFile("controls_module.csv");
      tlm.AddSignal("u", &u);
      tlm.AddSignal("dt", &dt);
      tlm.CreateLogHeader();
    };
    ~ControlsData() {
      tlm.EndLogging();
    };
};

class SimulationData {
  public:
    VectorXd x;
    VectorXd v;
    double t = 0.;
    double dt = 0.;

    TelemetryLogging tlm;
    SimulationData() {
      tlm.OpenFile("simulation_module.csv");
      tlm.AddSignal("x", &x);
      tlm.AddSignal("v", &v);
      tlm.AddSignal("t", &t);
      tlm.AddSignal("dt", &dt);
      tlm.CreateLogHeader();
    };
    ~SimulationData() {
      tlm.EndLogging();
    };
};


class ModuleDataCollection {
  public:
    ControlsData controls_data;
    SimulationData simulation_data;

};


#endif
