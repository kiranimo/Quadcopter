# Quadcopter
Quadcopter Design

===== BUILD INSTRUCTIONS ================

make sure bazel is installed

Build modules:
bazel build src/Modules:modules

Test modules:
bazel test src/Modules:module_tests

Look at src/Modules/BUILD to see individual tests

Build main:
bazel build src:main

Build and run main:
bazel run src:main

==========================================

The idea behind this architecture is to have a generic module 
class that runs until program is terminated. Then create threads 
for each module. An object is created to manage these threads and
help pass data from module to module. Specific modules can be 
derived from the base module and added to the list of modules
the manager should take care of. Each module has their own
datatype containing information specific to that module. This
data is added to a container that gets passed to each module,
and every module can read/write from this container.

===========================================
