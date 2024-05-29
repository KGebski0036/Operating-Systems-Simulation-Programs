cmake_minimum_required(VERSION 3.10)

project(simulations)

file(GLOB SOURCES src/**/*.cpp src/**/**/*.cpp)

add_library(${PROJECT_NAME}-lib STATIC ${SOURCES})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

target_include_directories(${PROJECT_NAME}-lib PUBLIC inc/Page/Algorithms inc/Page inc/Task/Algorithms inc/Task inc)
target_include_directories(${PROJECT_NAME} PUBLIC inc/Page/Algorithms inc/Page inc/Task/Algorithms inc/Task inc)

set_target_properties(${PROJECT_NAME} PROPERTIES
						CXX_STANDARD 17
						CXX_STANDARD_REQUIRED ON)

make_directory(out)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -g)
