cmake_minimum_required(VERSION 3.21)

project(
  car
  VERSION 1.3.0
  DESCRIPTION "Car Library"
  LANGUAGES C CXX)

MESSAGE("Configuring version.h ...")
configure_file("${PROJECT_SOURCE_DIR}/version.h.in"
               "${PROJECT_SOURCE_DIR}/version.h")

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)

# Configure headers and sources
set(PUBLIC_HEADERS "car.hpp version.h")
set(MY_LIB_SOURCES "car.cpp")

# Create SHARED Library Object
add_library(${PROJECT_NAME} SHARED ${MY_LIB_SOURCES})

# Link real libs and configuration interfaces
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
