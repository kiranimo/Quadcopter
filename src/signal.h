#ifndef SIGNAL_H
#define SIGNAL_H

#include <eigen3/Eigen/Dense>
#include <iostream>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class Signal {
    public:
        Signal() {};
        Signal(std::string signal_name);

        std::string CreateLoggingString(double x);
        std::string CreateLoggingString(VectorXd x);
        std::string CreateLoggingString(MatrixXd x);
        std::string GetSignalString();
        std::string GetSignalName();
        std::string GetSignalHeader();
        void SetSignalName(std::string signal_name);
        void SetSignal(MatrixXd x);
        void SetSignal(VectorXd x);
        void SetSignal(double x);

    private:
        std::string _signal_name;
        MatrixXd _mx;
        VectorXd _vx;
        double _dx;
        std::string _datatype;
};

#endif