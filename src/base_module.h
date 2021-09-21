#ifndef BASE_MODULE_H
#define BASE_MODULE_H

#include <vector>
#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include <ratio>
#include "module_data.h"
#include "telemetry_logging.h"

class BaseModuleData : public TelemetryLogging {

};

// Generic module type for all other modules to be derived from.
class BaseModule {
  public:
    // Generic template for initialization, should intialize the module
    // specific datatype. 
    virtual void Init(std::shared_ptr<ModuleDataCollection> data);

    // Generic function that calls Poll(), should be started by
    // the process managing all of the modules. Since Loop() calls
    // Poll(), we need to pass the variable containing all of the module
    // information.
    void Loop(std::shared_ptr<ModuleDataCollection> data);

    void SetModuleRuntime(std::chrono::milliseconds total_runtime);
    std::chrono::milliseconds GetModulePeriod();

    // TODO: kirencaldwell - should probably make a getter for this.
    // Module name.
    std::string _module_name;
  protected:
    // Generic function called by Loop(), this is where the meat of the
    // module lives.
    // Need to pass the variable containing all of the modules
    // information.
    virtual void Poll(std::shared_ptr<ModuleDataCollection> data);

    // return module runtime
    // TODO: kirencaldwell - actually implement this freaking function
    double GetRuntimeMilliseconds();

    // default runtime is 5 seconds
    std::chrono::milliseconds _total_runtime = std::chrono::milliseconds(5000);
    // default refresh rate is 200Hz
    std::chrono::milliseconds _module_period_ms = std::chrono::milliseconds(5);
    // initial time module is started
    std::chrono::time_point<std::chrono::steady_clock> _start_time;
    // time between calls to Poll (ms)
    double _dt_ms = 0.005;

};

#endif