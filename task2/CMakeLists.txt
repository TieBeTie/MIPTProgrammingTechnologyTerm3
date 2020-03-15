cmake_minimum_required(VERSION 2.8)
project(MadeInAbyss)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR})

execute_process(
	COMMAND bash -c "python3 ./A/preparing.py")
add_executable(MadeInAbyss ${PROJECT_SOURCE_DIR}/C/main.cpp)
target_link_libraries(MadeInAbyss RikoAndReg)

add_subdirectory(${PROJECT_SOURCE_DIR}/B)
