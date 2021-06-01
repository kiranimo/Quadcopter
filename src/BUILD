load("@rules_cc//cc:defs.bzl", "cc_test")

cc_binary (
    name = "main",
    srcs = ["main.cc"],
    deps = [
            "//src/Modules:modules",
            ],
    linkopts = ["-pthread"],
)

cc_test(
    name = "base_module_test",
    size = "small",
    srcs = ["base_module_test.cc",],
    deps = ["@com_google_googletest//:gtest_main",
            "//src:src"],
)
