
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

add_executable(anchors.exe anchors.cpp)
target_link_libraries(anchors.exe
		      fort_yaml gtest gtest_main 
		      ${EXTERNALS_DIR}/installed/lib/libyaml.a
		      )
gtest_discover_tests(anchors.exe)
