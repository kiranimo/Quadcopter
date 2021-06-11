load("@rules_cc//cc:defs.bzl", "cc_test")

cc_binary (
    name = "main",
    srcs = [
           "main.cc",
           ],
    deps = [
            "//src:modules",
            "//:example",
            ],
    linkopts = ["-pthread"],
)

cc_library(
    name = "example",
    srcs = [
          "controls_module.cc",
          "simulation_module.cc",
          ],
    hdrs = [
          "controls_module.h",
          "simulation_module.h",
          ],
    deps = [
            "//src:modules",
            ],
    linkopts = ["-pthread"],
)

