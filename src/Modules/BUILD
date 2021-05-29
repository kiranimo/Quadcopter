load("@rules_cc//cc:defs.bzl", "cc_test")

cc_library(
    name = "modules",
    srcs = ["base_module.cc",
            "module_manager.cc",],
    hdrs = ["base_module.h",
            "module_manager.h",],
    linkopts = ["-pthread"],
    visibility = ["//src:__pkg__"],
)

cc_test(
    name = "module_manager_test",
    size = "small",
    srcs = ["module_manager_test.cc",],
    deps = ["@com_google_googletest//:gtest_main",
            "//src/Modules:modules"],
)
