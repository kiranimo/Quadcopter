#include <gtest/gtest.h>
#include <iostream>
#include <eigen3/Eigen/Dense>
#include "base_module_data.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;

TEST(BaseModuleDataTests, WorksWithDoubles) {
    std::cout.flush();

    BaseModuleData test_data;
    test_data.Init("test_data");

    double x = 4;
    test_data.Add<double>("x", x);

    test_data.LogTelemetry();
    x = test_data.Get<double>("x");
    x++;
    test_data.Set<double>("x", x);

    EXPECT_EQ(test_data.Get<double>("x"), 5);

}

TEST(BaseModuleDataTests, WorksWithVectors) {
    std::cout.flush();

    BaseModuleData test_data("test_data");

    VectorXd y = VectorXd::Ones(3);
    test_data.Add<VectorXd>("y", y);

    test_data.LogTelemetry();

    EXPECT_EQ(test_data.Get<VectorXd>("y"), VectorXd::Ones(3));

}

