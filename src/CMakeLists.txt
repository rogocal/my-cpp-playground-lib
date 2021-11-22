cmake_minimum_required(VERSION 3.21)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)

set(PROJECT_VERSION 1.2.0)

project(
  car
  VERSION ${PROJECT_VERSION}
  DESCRIPTION "Car Library"
  LANGUAGES C CXX)

set(PUBLIC_HEADERS "car.hpp")
set(MY_LIB_SOURCES "car.cpp")

# Create SHARED Library Object
add_library(${PROJECT_NAME} SHARED ${MY_LIB_SOURCES})

target_link_libraries(${PROJECT_NAME} jsoncpp project_warnings project_options)

# Configure SHARED Library Object
set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES PUBLIC_HEADER ${PUBLIC_HEADERS}
             RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
             VERSION ${PROJECT_VERSION})

# Import GNU Install Rules
include(GNUInstallDirs)

# Files to Install
install(
  TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
