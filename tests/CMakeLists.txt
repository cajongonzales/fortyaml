
# Add GoogleTest
ExternalProject_Add(googletest
  PREFIX ${EXTERNALS_DIR}
  GIT_REPOSITORY "https://github.com/google/googletest.git"
  CMAKE_ARGS -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=${EXTERNALS_DIR}/installed
  # Log output
  LOG_DOWNLOAD ON
  LOG_CONFIGURE ON
  LOG_BUILD ON
  LOG_INSTALL ON
)

include_directories(include ${EXTERNALS_DIR}/installed/include)

## Anchors not currently supported with yaml-cpp

#add_executable(anchors.exe anchors.cpp)
#target_link_libraries(anchors.exe
#		      fort_yaml 
#          ${EXTERNALS_DIR}/installed/lib/libgtest.a 
#          ${EXTERNALS_DIR}/installed/lib/libgtest_main.a
#          pthread # Must be after gtest or you get a bunch of link errors
#		      ${EXTERNALS_DIR}/installed/lib/libyaml-cpp.a
#		      )
#add_dependencies(anchors.exe googletest yaml-cpp)
#gtest_discover_tests(anchors.exe)

add_executable(array.exe array.cpp)
target_link_libraries(array.exe
		      fort_yaml 
          ${EXTERNALS_DIR}/installed/lib/libgtest.a 
          ${EXTERNALS_DIR}/installed/lib/libgtest_main.a
          pthread # Must be after gtest or you get a bunch of link errors
		      ${EXTERNALS_DIR}/installed/lib/libyaml-cpp.a
		      )
add_dependencies(array.exe googletest yaml-cpp)
gtest_discover_tests(array.exe)

add_executable(componentExample.exe componentExample.cpp)
target_link_libraries(componentExample.exe
		      fort_yaml 
          ${EXTERNALS_DIR}/installed/lib/libgtest.a 
          ${EXTERNALS_DIR}/installed/lib/libgtest_main.a
          pthread # Must be after gtest or you get a bunch of link errors
		      ${EXTERNALS_DIR}/installed/lib/libyaml-cpp.a
		      )
add_dependencies(componentExample.exe googletest yaml-cpp)
gtest_discover_tests(componentExample.exe)

# Not currently supporting global tags
#add_executable(globalTag.exe globalTag.cpp)
#target_link_libraries(globalTag.exe
#		      fort_yaml 
#          ${EXTERNALS_DIR}/installed/lib/libgtest.a 
#          ${EXTERNALS_DIR}/installed/lib/libgtest_main.a
#          pthread # Must be after gtest or you get a bunch of link errors
#		      ${EXTERNALS_DIR}/installed/lib/libyaml.a
#		      )
#add_dependencies(globalTag.exe googletest libyaml)
#gtest_discover_tests(globalTag.exe)

add_executable(json.exe json.cpp)
target_link_libraries(json.exe
		      fort_yaml 
          ${EXTERNALS_DIR}/installed/lib/libgtest.a 
          ${EXTERNALS_DIR}/installed/lib/libgtest_main.a
          pthread # Must be after gtest or you get a bunch of link errors
		      ${EXTERNALS_DIR}/installed/lib/libyaml-cpp.a
		      )
add_dependencies(json.exe googletest yaml-cpp)
gtest_discover_tests(json.exe)

add_executable(mapping.exe mapping.cpp)
target_link_libraries(mapping.exe
		      fort_yaml 
          ${EXTERNALS_DIR}/installed/lib/libgtest.a 
          ${EXTERNALS_DIR}/installed/lib/libgtest_main.a
          pthread # Must be after gtest or you get a bunch of link errors
		      ${EXTERNALS_DIR}/installed/lib/libyaml-cpp.a
		      )
add_dependencies(mapping.exe googletest yaml-cpp)
gtest_discover_tests(mapping.exe)

add_executable(numbers.exe numbers.cpp)
target_link_libraries(numbers.exe
		      fort_yaml 
          ${EXTERNALS_DIR}/installed/lib/libgtest.a 
          ${EXTERNALS_DIR}/installed/lib/libgtest_main.a
          pthread # Must be after gtest or you get a bunch of link errors
		      ${EXTERNALS_DIR}/installed/lib/libyaml-cpp.a
		      )
add_dependencies(numbers.exe googletest yaml-cpp)
gtest_discover_tests(numbers.exe)

add_executable(strings.exe strings.cpp)
target_link_libraries(strings.exe
		      fort_yaml 
          ${EXTERNALS_DIR}/installed/lib/libgtest.a 
          ${EXTERNALS_DIR}/installed/lib/libgtest_main.a
          pthread # Must be after gtest or you get a bunch of link errors
		      ${EXTERNALS_DIR}/installed/lib/libyaml-cpp.a
		      )
add_dependencies(strings.exe googletest yaml-cpp)
gtest_discover_tests(strings.exe)

add_executable(tags.exe tags.cpp)
target_link_libraries(tags.exe
		      fort_yaml 
          ${EXTERNALS_DIR}/installed/lib/libgtest.a 
          ${EXTERNALS_DIR}/installed/lib/libgtest_main.a
          pthread # Must be after gtest or you get a bunch of link errors
		      ${EXTERNALS_DIR}/installed/lib/libyaml-cpp.a
		      )

## Tags do not work with yaml-cpp
#add_dependencies(tags.exe googletest yaml-cpp)
#gtest_discover_tests(tags.exe)

#add_executable(yamlVersion.exe yamlVersion.cpp)
#target_link_libraries(yamlVersion.exe
#		      fort_yaml 
#          ${EXTERNALS_DIR}/installed/lib/libgtest.a 
#          ${EXTERNALS_DIR}/installed/lib/libgtest_main.a
#          pthread # Must be after gtest or you get a bunch of link errors
#		      ${EXTERNALS_DIR}/installed/lib/libyaml-cpp.a
#		      )
#add_dependencies(yamlVersion.exe googletest yaml-cpp)
#gtest_discover_tests(yamlVersion.exe)

add_executable(nYaml.exe nYaml.cpp)
target_link_libraries(nYaml.exe
		      fort_yaml 
          ${EXTERNALS_DIR}/installed/lib/libgtest.a 
          ${EXTERNALS_DIR}/installed/lib/libgtest_main.a
          pthread # Must be after gtest or you get a bunch of link errors
		      ${EXTERNALS_DIR}/installed/lib/libyaml-cpp.a
		      )
add_dependencies(nYaml.exe googletest yaml-cpp)
gtest_discover_tests(nYaml.exe)

