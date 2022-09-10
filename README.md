# binary_tree_stuff

A repository for testing binary tree problems from leetcode. Renders trees with cairo and OpenGL.

## Platforms that were tested

- [x] macOS (arm)
- [ ] Windows
- [ ] Linux

## Compiling to emscripten

```
mkdir build
cd build

cmake -DCMAKE_TOOLCHAIN_FILE=<emsdk_path>/emscripten/cmake/Modules/Platform/Emscripten.cmake \
  -DCMAKE_BUILD_TYPE=Debug \
  -G "Unix Makefiles" \
  ..

cmake --build .
```
