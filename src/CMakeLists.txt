add_executable(fort_yaml.exe 
               main.f90 
               )
add_library(fort_yaml
            yamlEventReader.cpp
            )

add_dependencies(fort_yaml yaml-cpp)

target_link_libraries(fort_yaml.exe fort_yaml ${EXTERNALS_DIR}/installed/lib/libyaml-cpp.a)
