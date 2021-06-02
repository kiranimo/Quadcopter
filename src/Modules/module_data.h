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


class ControlsData {
  public:
    VectorXd u = VectorXd::Zero(3);

    TelemetryLogging tlm;
    
    ControlsData() {
      tlm.OpenFile("controls_module.csv");
      tlm.AddSignal("u", &u);
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
    double simulation_time = 0.;

    TelemetryLogging tlm;
    SimulationData() {
      tlm.OpenFile("simulation_module.csv");
      tlm.AddSignal("x", &x);
      tlm.AddSignal("v", &v);
      tlm.AddSignal("t", &simulation_time);
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
