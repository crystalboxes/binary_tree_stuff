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
