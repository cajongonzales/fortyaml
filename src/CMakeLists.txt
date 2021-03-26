add_executable(fortBinding 
	       main.f90 
	       yamlEventReader.cpp
	       )

target_link_libraries(fortBinding yaml)
