#include "telemetry_logging.h"

std::string CreateLoggingString(double x) {
    std::string out;
    std::string xx;
    xx = std::to_string(x) + ",";
    out.append(xx);
    return out;
}
std::string CreateLoggingString(VectorXd x) {
    std::string out;
    std::string xx;
    for (int i = 0; i < x.size(); i++) {
        xx = std::to_string(x(i)) + ",";
        out.append(xx);
    }
    return out;
}
std::string CreateLoggingString(MatrixXd x) {
    std::string out;
    std::string xx;
    for (int i = 0; i < x.cols(); i++) {
        for (int j = 0; j < x.rows(); j++) {
            xx = std::to_string(x(j,i)) + ",";
            out.append(xx);
        }
    }
    return out;
}

void TelemetryLogging::AddSignal(std::string signal_name, VectorXd *signal) {
    Signal tlm = Signal(signal_name);
    tlm.SetSignal(signal);
    _signals.push_back(tlm);
}

void TelemetryLogging::AddSignal(std::string signal_name, MatrixXd *signal) {
    Signal tlm = Signal(signal_name);
    tlm.SetSignal(signal);
    _signals.push_back(tlm);
}

void TelemetryLogging::AddSignal(std::string signal_name, double *signal) {
    Signal tlm = Signal(signal_name);
    tlm.SetSignal(signal);
    _signals.push_back(tlm);
}

void TelemetryLogging::LogSignals() {
    std::string out;
    for (int i = 0; i < (int)_signals.size(); i++) {
        out.append(_signals[i].GetSignalString());
    }
    out.append("\n");
    _logfile << out;
    // write to file
}

void TelemetryLogging::CreateLogHeader() {
    std::string out;
    for (int i = 0; i < (int)_signals.size(); i++) {
        out.append(_signals[i].GetSignalHeader());
    }
    out.append("\n");
    _logfile << out;
}


void TelemetryLogging::OpenFile(std::string filename) {
  _filename = filename;
  _logfile.open(filename);
  if (_logfile.is_open()) {
    std::cout << _filename << " is open" << std::endl;
  }
}


void TelemetryLogging::EndLogging() {
    _logfile.close();
    if (!_logfile.is_open()) {
      std::cout << _filename << " is closed" << std::endl;
    }
}

Signal::Signal(std::string signal_name) {
    SetSignalName(signal_name);
}

std::string Signal::GetSignalHeader() {
    std::string out;
    if (_datatype == "matrix") {
        for (int i = 0; i < (*_mx).cols(); i++) {
            for (int j = 0; j < (*_mx).rows(); j++) {
                out.append(_signal_name);
                out.append(std::to_string(j));
                out.append(std::to_string(i));
                out.append(",");
            }
        }
    } 
    else if (_datatype == "vector") {
        for (int i = 0; i < (*_vx).size(); i++) {
            out.append(_signal_name);
            out.append(std::to_string(i));
            out.append(",");
        }
    }
    else if (_datatype == "scalar") {
        out.append(_signal_name);
        out.append(",");
    }
    else {
        return "sorry";
    }
    return out;
}
std::string Signal::GetSignalString() {
    if (_datatype == "matrix") {
        return CreateLoggingString(*_mx);
    } 
    else if (_datatype == "vector") {
        return CreateLoggingString(*_vx);
    }
    else if (_datatype == "scalar") {
        return CreateLoggingString(*_dx);
    }
    else {
        return "sorry";
    }
}

std::string Signal::GetSignalName() {
    return _signal_name;
}

void Signal::SetSignalName(std::string signal_name) {
    _signal_name = signal_name;
}

void Signal::SetSignal(MatrixXd *x) {
    _datatype = "matrix";
    _mx = x;
}

void Signal::SetSignal(VectorXd *x) {
    _datatype = "vector";
    _vx = x;
}

void Signal::SetSignal(double *x) {
    _datatype = "scalar";
    _dx = x;
}
