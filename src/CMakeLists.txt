add_executable(fortBinding 
	       main.f90 
	       yamlEventReader.cpp
	       )

add_dependencies(fortBinding libyaml)

target_link_libraries(fortBinding ${EXTERNALS_DIR}/installed/lib/libyaml.a)
