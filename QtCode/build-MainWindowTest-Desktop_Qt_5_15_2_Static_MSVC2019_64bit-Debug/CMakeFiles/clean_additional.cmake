# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MainWindowTest_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MainWindowTest_autogen.dir\\ParseCache.txt"
  "MainWindowTest_autogen"
  )
endif()
