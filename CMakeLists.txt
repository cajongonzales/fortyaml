CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

project(FortYamlShackle Fortran C CXX)

include_directories(include)
add_subdirectory(src)
install (FILES ${CMAKE_BINARY_DIR}/src/fortBinding 
	PERMISSIONS GROUP_EXECUTE 
	PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
	 DESTINATION ${PROJECT_SOURCE_DIR}/bin)
