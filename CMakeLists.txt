cmake_minimum_required(VERSION 3.16)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  foreach(lang C CXX)
    if(NOT DEFINED CMAKE_${lang}_COMPILER_LAUNCHER AND NOT CMAKE_${lang}_COMPILER MATCHES ".*/ccache")
      message(STATUS "Enabling ccache for ${lang}")
      set(CMAKE_${lang}_COMPILER_LAUNCHER ${CCACHE_PROGRAM} CACHE STRING "")
    endif()
  endforeach()
endif()

set(project_name web3cpp)

project(${project_name}
    VERSION 0.0.1
    DESCRIPTION "web3 in c++"
    LANGUAGES C CXX)
include(CheckCXXSourceCompiles)
include(CheckLibraryExists)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# our pacakges we require
# set(DEPS sodium)

foreach(lib ${DEPS})
  find_package(${lib} REQUIRED)
endforeach()

#include_directories(external/rapidjson/include external)
# our subdirectories with our libs in it
#add_subdirectory(src)
add_subdirectory(external)

add_executable(${project_name} main.cpp)
target_link_libraries(${project_name} PUBLIC cpr::cpr)
target_link_libraries(${project_name} PUBLIC nlohmann_json::nlohmann_json)

foreach(lib ${DEPS})
  target_link_libraries(${project_name} PUBLIC ${lib})
endforeach()
