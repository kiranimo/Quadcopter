#ifndef BASE_MODULE_DATA_H
#define BASE_MODULE_DATA_H

#include <iostream>
#include <map>
#include <utility>
#include <any>
#include <string>

#include "signal.h"

class BaseModuleData {
  public:
    BaseModuleData() {};
    BaseModuleData(std::string module_name);
    void Init(std::string module_name);

    template <typename T>
    void Add(std::string data_name, T value) {
        Signal signal;
        signal.SetSignalName(data_name);
        signal.SetSignal(value);
        std::pair<Signal, std::any> in(signal, value);

        _data[data_name] = in;
    };

    template <typename T>
    void Set(std::string data_name, T value) {
        _data[data_name].second = value;
    };

    template <typename T>
    T Get(std::string data_name) {
        return std::any_cast<T>(_data[data_name].second);
    };

    void LogTelemetry();
    
  protected:
    std::string _filename;
    bool _first_pass = true;
    std::map<std::string, std::pair<Signal, std::any>> _data;
};

#endif