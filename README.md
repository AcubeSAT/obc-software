# OBC Software Repository

`git submodule update --init --recursive`
To build, you first have to `cd cmake-build-debug` (or to the respective CMake build dir) and run `conan install ..  --build=missing`. If you're using CLion and don't see `cmake-build-debug`, you have to Reload CMake project to have it generated.
After you've run conan install .. you can Reload CMake project and build as per usual.