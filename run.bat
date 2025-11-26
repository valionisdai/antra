@echo off
mkdir build
cd build

cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS_RELEASE="-flto=auto -O3 -funroll-loops -march=znver3" ..
cmake --build .

Work_with_Files.exe
pause
