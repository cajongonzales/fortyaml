CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

project(FortYamlShackle Fortran C CXX)

# Find the yaml module
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/tools/cmake/Modules")

include(ExternalProject)
include(GoogleTest)
include(CTest)
# Set default ExternalProject root directory
set(EXTERNALS_DIR ${CMAKE_BINARY_DIR}/ThirdParty)

# Add libyaml
ExternalProject_Add(libyaml
  PREFIX ${EXTERNALS_DIR}
  GIT_REPOSITORY "https://github.com/yaml/libyaml"
  CMAKE_ARGS -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=${EXTERNALS_DIR}/installed

  # Log output
  LOG_DOWNLOAD ON
  LOG_CONFIGURE ON
  LOG_BUILD ON
  LOG_INSTALL ON
)

find_package(GTest)

# Specify include dir
include_directories(include ${EXTERNALS_DIR}/installed/include)

add_subdirectory(src)
add_subdirectory(tests)
install (FILES ${CMAKE_BINARY_DIR}/src/fortBinding 
 	 PERMISSIONS  GROUP_READ GROUP_EXECUTE 
         PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
	 DESTINATION ${PROJECT_SOURCE_DIR}/bin)
