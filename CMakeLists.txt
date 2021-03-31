CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

project(FortYamlShackle Fortran C CXX)

# Find the yaml module
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/tools/cmake/Modules")

include(FetchContent) 

FetchContent_Declare(LibYaml
	             GIT_REPOSITORY "https://github.com/yaml/libyaml"
		     )

FetchContent_MakeAvailable(LibYaml)
find_package(Yaml REQUIRED)
include_directories(include ${YAML_INCLUDE_DIRS})
add_subdirectory(src)
install (FILES ${CMAKE_BINARY_DIR}/src/fortBinding 
 	 PERMISSIONS  GROUP_READ GROUP_EXECUTE 
         PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
	 DESTINATION ${PROJECT_SOURCE_DIR}/bin)
