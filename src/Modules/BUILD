load("@rules_cc//cc:defs.bzl", "cc_test")

cc_library(
    name = "modules",
    srcs = [
            "base_module.cc",
            "module_manager.cc",
            "controls_module.cc",
            "simulation_module.cc",
            ],
    hdrs = [
            "base_module.h",
            "module_manager.h",
            "module_data.h",
            # "test_module.h",
            "controls_module.h",
            "simulation_module.h",
            ],
    linkopts = ["-pthread"],
    visibility = ["//src:__pkg__"],
)

test_suite(
    name = "module_tests",
    tests = [
           "module_data_wrapper_test",
           "base_module_test",
           "module_manager_test",
           ],
)

cc_test(
    name = "module_data_wrapper_test",
    size = "small",
    srcs = ["module_data_wrapper_test.cc",],
    deps = ["@com_google_googletest//:gtest_main",
            "//src/Modules:modules"],
)
cc_test(
    name = "base_module_test",
    size = "small",
    srcs = ["base_module_test.cc",],
    deps = ["@com_google_googletest//:gtest_main",
            "//src/Modules:modules"],
)
cc_test(
    name = "module_manager_test",
    size = "small",
    srcs = ["module_manager_test.cc",],
    deps = ["@com_google_googletest//:gtest_main",
            "//src/Modules:modules"],
)
