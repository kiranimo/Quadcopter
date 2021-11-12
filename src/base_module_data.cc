#include "base_module_data.h"
#include <fstream>

void BaseModuleData::LogTelemetry() {
    std::string out;
    std::ofstream logfile;
    std::map<std::string, std::pair<Signal, std::any>>::iterator it;
    if (_first_pass) {
        logfile.open(_filename);
        _first_pass = false;
        std::string header;
        for (it = _data.begin(); it != _data.end(); it++) {
            auto signal = it->second.first;
            header.append(signal.GetSignalHeader()); 
        }
        logfile << header;
        logfile.close();
    }
    for (it = _data.begin(); it != _data.end(); it++) {
        auto signal = it->second.first;
        out.append(signal.GetSignalString());
    }
    // logfile << out;
    // logfile.close();
}

BaseModuleData::BaseModuleData(std::string module_name) {
    Init(module_name);
}

void BaseModuleData::Init(std::string module_name) {
    _filename = module_name + ".csv";
}

