cmake_minimum_required(VERSION 3.16.3)
project(clothoid)

# debug mdoe.
SET(CMAKE_BUILD_TYPE "Debug")

SET(CMAKE_CXX_STANDARD 14)
# This makes C++14 a requirement,
# and prevents a "decay" to C++98 when the compiler does not support C++14.
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
# This disables the use of compiler-specific extensions.
# For example, by default, CMake passes -std=gnu++14 to GCC on Linux.
# We want to build with -std=c++14. 
SET(CMAKE_CXX_EXTENSIONS OFF)

FIND_PACKAGE(OpenCV REQUIRED)
FIND_PACKAGE(Eigen3 REQUIRED)

FIND_PATH(LOGGER_INCLUDE_DIR NAMES file_logger.h PATHS /home/neal/usr/include/file_logger)
FIND_LIBRARY(LOGGER_LIBRARIES file_logger HINTS /home/neal/usr/lib)

INCLUDE_DIRECTORIES(
  include
  ${OpenCV_INCLUDE_DIRS}
  ${LOGGER_INCLUDE_DIR}
  ${EIGEN3_INCLUDE_DIR}
)

ADD_EXECUTABLE(clothoidGenerator src/main.cpp src/clothoid.cpp src/state.cpp)
TARGET_LINK_LIBRARIES(clothoidGenerator ${OpenCV_LIBS} ${LOGGER_LIBRARIES})
