# -*- mode: cmake -*-

#
# Yaml Find Module
#
# Usage:
#    Control the search through YAML_ROOT or setting environment variable
#    YAML_ROOT to the yaml installation prefix.
#
#    This module does not search default paths!
#
#    Following variables are set:
#    YAML_FOUND             (BOOL)       Flag indicating if yaml was found
#    YAML_INCLUDE_DIRS      (PATH)       Path to the yaml include files
#    YAML_LIBRARIES         (LIST)       The yaml libraries

set(YAML_FOUND TRUE)

if (YAML_INCLUDE_DIRS AND YAML_LIBRARIES)

  # Do nothing. Variables are set. No need to search again

elseif(YAML_ROOT)
  find_library(YAML_LIBRARIES
               NAMES yaml
               PATHS "${YAML_ROOT}/lib64" "${YAML_ROOT}/lib")

  if(YAML_LIBRARIES)
  else()
    set(YAML_FOUND FALSE)
  endif()

  find_path(YAML_INCLUDE_DIRS yaml.h "${YAML_ROOT}/include")
  if(YAML_INCLUDE_DIRS)
  else()
    set(YAML_FOUND FALSE)
  endif()
else()
  find_library(YAML_LIBRARIES
               NAMES yaml)

  if(YAML_LIBRARIES)
  else()
    set(YAML_FOUND FALSE)
  endif()

  find_path(YAML_INCLUDE_DIRS yaml.h)
  if(YAML_INCLUDE_DIRS)
  else()
    set(YAML_FOUND FALSE)
  endif()
endif()

if(YAML_FOUND)
  message(STATUS "YAML found")
else()
  if(YAML_FIND_REQUIRED)
    message(FATAL_ERROR "YAML not found.  Please specify library location.")
  else()
    message(STATUS "YAML not found.")
  endif()
endif()