CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

#ENABLE_LANGUAGE(fortran)
project(FortYamlShackle Fortran C)

#${CMAKE_INSTALL_PREFIX}=/usr/local
#message(${CMAKE_CURRENT_SOURCE_DIR}) /home/clear/Work/fortYamlBinding
#message(${PROJECT_SOURCE_DIR}) same as above

add_subdirectory(src)
install (FILES ${CMAKE_BINARY_DIR}/src/fortBinding 
	PERMISSIONS GROUP_EXECUTE 
	PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
	 DESTINATION ${PROJECT_SOURCE_DIR}/bin)
