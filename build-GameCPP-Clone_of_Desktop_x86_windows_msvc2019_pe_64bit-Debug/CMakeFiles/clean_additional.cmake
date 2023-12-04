# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appGameCPP_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appGameCPP_autogen.dir\\ParseCache.txt"
  "appGameCPP_autogen"
  )
endif()
