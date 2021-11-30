cmake_minimum_required(VERSION 3.0.0)
project(header-intro)

include(CTest)
enable_testing()

include_directories(include)
file(GLOB SOURCES "./*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
