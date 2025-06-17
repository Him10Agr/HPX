add_library(HPX_lib STATIC "kernel.cpp" "config.cpp" "pbm.cpp")

#include path for public header
target_include_directories(HPX_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
