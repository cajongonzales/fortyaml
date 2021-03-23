add_executable(fortBinding 
	       main.f90 
	       yamlEventReader.c
	       )

target_link_libraries(fortBinding libyaml.a)
