load("@rules_cc//cc:defs.bzl", "cc_test")

cc_library(
    name = "modules",
    srcs = [
            "base_module.cc",
            "module_manager.cc",
            ],
    hdrs = [
            "base_module.h",
            "module_manager.h",
            "module_data.h",
            "test_module.h",
            ],
    deps = [
            "module_data",
            ],
    linkopts = ["-pthread"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "module_data",
    srcs = [
            "base_module_data.cc",
            "signal.cc",
            ],
    hdrs = [
            "base_module_data.h",
            "signal.h",
            "module_data.h",
            ],
    linkopts = ["-pthread"],
    visibility = ["//visibility:public"],

)

test_suite(
    name = "module_tests",
    tests = [
           "module_data_test",
           "base_module_test",
           "module_manager_test",
           "base_module_data_test",
           ],
)

cc_test(
    name = "base_module_data_test",
    size = "small",
    srcs = ["base_module_data_test.cc",],
    deps = ["@com_google_googletest//:gtest_main",
            "//src:module_data"],
)
cc_test(
    name = "module_data_test",
    size = "small",
    srcs = ["module_data_test.cc",],
    deps = ["@com_google_googletest//:gtest_main",
            "//src:modules"],
)

cc_test(
    name = "base_module_test",
    size = "small",
    srcs = ["base_module_test.cc",],
    deps = ["@com_google_googletest//:gtest_main",
            "//src:modules"],
)
cc_test(
    name = "module_manager_test",
    size = "small",
    srcs = ["module_manager_test.cc",],
    deps = ["@com_google_googletest//:gtest_main",
            "//src:modules"],
)
