#include "signal.h"

Signal::Signal(std::string signal_name) {
    SetSignalName(signal_name);
}

std::string Signal::CreateLoggingString(double x) {
    std::string out;
    std::string xx;
    xx = std::to_string(x) + ",";
    out.append(xx);
    return out;
}
std::string Signal::CreateLoggingString(VectorXd x) {
    std::string out;
    std::string xx;
    for (int i = 0; i < x.size(); i++) {
        xx = std::to_string(x(i)) + ",";
        out.append(xx);
    }
    return out;
}
std::string Signal::CreateLoggingString(MatrixXd x) {
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
std::string Signal::GetSignalHeader() {
    std::string out;
    if (_datatype == "matrix") {
        for (int i = 0; i < (_mx).cols(); i++) {
            for (int j = 0; j < (_mx).rows(); j++) {
                out.append(_signal_name);
                out.append(std::to_string(j));
                out.append(std::to_string(i));
                out.append(",");
            }
        }
    } 
    else if (_datatype == "vector") {
        for (int i = 0; i < (_vx).size(); i++) {
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
        return CreateLoggingString(_mx);
    } 
    else if (_datatype == "vector") {
        return CreateLoggingString(_vx);
    }
    else if (_datatype == "scalar") {
        return CreateLoggingString(_dx);
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

void Signal::SetSignal(MatrixXd x) {
    _datatype = "matrix";
    _mx = x;
}

void Signal::SetSignal(VectorXd x) {
    _datatype = "vector";
    _vx = x;
}

void Signal::SetSignal(double x) {
    _datatype = "scalar";
    _dx = x;
}
