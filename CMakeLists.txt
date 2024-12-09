cmake_minimum_required(VERSION 3.14...3.30)

project(
    naibench
    VERSION 0.1.0
    DESCRIPTION "Naive benchmark, simple header-only, benchmark library to time function executions"
    LANGUAGES CXX C
)

add_library(
    ${PROJECT_NAME}
    INTERFACE
)

add_library(NAIBENCH::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

include("${PROJECT_SOURCE_DIR}/cmake/config-setup.cmake")
include("${PROJECT_SOURCE_DIR}/cmake/naibench-install.cmake")
