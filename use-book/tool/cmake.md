## 资源路径
    - [原文档](https://gitlab.kitware.com/cmake/cmake/-/tree/master)

## 声明-基础项目
```cmake
cmake_minimum_required (VERSION 2.8)
project (Tutorial)
add_executable(Tutorial Tutorial.cxx)
```

## 版本号
```cmake
# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)
```

## 配置头文件
```cmake
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  )
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")
```

## 构建项目并执行文件
    - 在该目录下面建立 build 文件夹 创建run.cmd文件
```cmake
echo off
echo build:
cmake -G "Visual Studio 15 2017 Win32" ..
echo compile:
devenv Tutorial.sln /build "Debug|x32"
#
#cmake --build .
echo run:
start ./Debug/Tutorial.exe %1
```

## 添加库文件
```cmake
add_library(MathFunctions mysqrt.cxx)
```
- 为了构建并使用新的库文件, 添加额外的头文件包含路径 `add_subdirectory `
- 
```cmake
include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
add_subdirectory (MathFunctions) 
 
# add the executable
add_executable (Tutorial tutorial.cxx)
target_link_libraries (Tutorial MathFunctions)
```