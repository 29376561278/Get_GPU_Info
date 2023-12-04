# CMakeList.txt : CMake project for descosmos_gpu_monitor, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("descosmos_gpu_monitor")  

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# sys include directory
include_directories("C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/shared")
include_directories("C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um")

# this include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/./utils)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/./config)

set(SRC_SOURCES
	"config/gpuMonitor.h" 
	"src/gpuMonitor.cpp"  
	

	)

set(UTILS_SOURCES

	
	)


# Add source to this project's executable.
# 第二种方法使用add_executable是否能接到外部库
add_executable (windows-base "main.cpp" ${UTILS_SOURCES} ${SRC_SOURCES}  )
#target_link_libraries("../ConsoleApplication4/ConsoleApplication4.cpp" PRIVATE "get_outcome.h")
 #第一种 将代码打包成静态库，但是这个只能打包源文件不能打包头文件
#add_library("descosmos_gpu_monitor" STATIC 
#"src/gpuMonitor.cpp"
#"utils/getWindowsVersion.cpp" 
#"utils/Handles.cpp"
#"utils/baseup.cpp"
#"utils/get_outcome.cpp"
#)


# TODO: Add tests and install targets if needed.
