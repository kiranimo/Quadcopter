load("@rules_cc//cc:defs.bzl", "cc_test")

cc_library(
    name = "modules",
    srcs = ["base_module.cc",
            "module_manager.cc",
            "share_module_data.cc",
           # "controls_module.cc",
            ],
    hdrs = ["base_module.h",
            "module_manager.h",
            "share_module_data.h",
           # "controls_module.h",
            ],
    linkopts = ["-pthread"],
    visibility = ["//src:__pkg__"],
)

cc_test(
    name = "share_module_data_test",
    size = "small",
    srcs = ["share_module_data_test.cc",],
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
