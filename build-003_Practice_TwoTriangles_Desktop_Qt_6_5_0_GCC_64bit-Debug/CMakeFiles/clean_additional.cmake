# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "003_Practice_TwoTriangles_autogen"
  "CMakeFiles/003_Practice_TwoTriangles_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/003_Practice_TwoTriangles_autogen.dir/ParseCache.txt"
  )
endif()
