cmake_minimum_required(VERSION 3.0.0)
project(dynamic_polymorfism_alternatives VERSION 0.1.0)

# Configure compiler to use C++latest
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

File(GLOB MyCppSources src/*.cpp src/*.ixx)

add_executable(dynamic_polymorfism_alternatives ${MyCppSources})

#add_compile_options(/NODEFAULTLIB:LIBCMT)
#add_compile_options(/NODEFAULTLIB:LIBCMTD)
#add_compile_options(/MTd)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(GENERATED_FILES_DIR ${CMAKE_CURRENT_BINARY_DIR}/cpp20.dir/${CMAKE_BUILD_TYPE})

message(STATUS "Generating ${GENERATED_FILES_DIR}")

target_compile_options(dynamic_polymorfism_alternatives
    PRIVATE
    /experimental:module
    /ifcSearchDir"${GENERATED_FILES_DIR}"
)