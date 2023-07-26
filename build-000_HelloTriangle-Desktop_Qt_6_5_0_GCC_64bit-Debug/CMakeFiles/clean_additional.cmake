# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "000_HelloTriangle_autogen"
  "CMakeFiles/000_HelloTriangle_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/000_HelloTriangle_autogen.dir/ParseCache.txt"
  )
endif()
