#include "logging_module.h"

LoggingModule::LoggingModule() {
  _module_name = "Logging Module";
}

void LoggingModule::Init(std::shared_ptr<ModuleDataCollection> data) {
  // set logging rate
  _module_period_ms = std::chrono::milliseconds(10);
}

void LoggingModule::Poll(std::shared_ptr<ModuleDataCollection> data) {
  std::lock_guard<std::mutex> guard(_module_mutex);

  // log data
  data->controls_data.tlm.LogSignals();
  data->simulation_data.tlm.LogSignals();
}
