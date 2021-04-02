add_executable(fort_yaml 
	       main.f90 
	       yamlEventReader.cpp
	       )

add_dependencies(fort_yaml libyaml)

target_link_libraries(fort_yaml ${EXTERNALS_DIR}/installed/lib/libyaml.a)
