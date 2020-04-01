cmake_minimum_required(VERSION 3.0)

option(TOOLCHAIN ON)
set(CMAKE_C_COMPILER ${TOOLCHAIN}/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/arm-linux-gnueabihf-g++)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)





set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)

project(SimpleLibrary)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_subdirectory(${CMAKE_SOURCE_DIR}/src)

add_executable(Main main.cpp)

add_executable(MainLib main_lib.cpp)
target_link_libraries(MainLib buffer)

set_target_properties(
  MainLib PROPERTIES INSTALL_RPATH ${CMAKE_SOURCE_DIR}/lib
)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include DESTINATION ${CMAKE_INSTALL_PREFIX})
install(
  TARGETS Main MainLib
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)



