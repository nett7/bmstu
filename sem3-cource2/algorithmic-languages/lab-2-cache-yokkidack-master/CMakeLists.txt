cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include("tools/gate/cmake/HunterGate.cmake")

HunterGate(
  URL "https://github.com/ruslo/hunter/archive/v0.23.31.tar.gz"
  SHA1 "3d94b8522541c4c8eaac606f4c47d09322a8019c"
)

project(cache)
string(APPEND CMAKE_CXX_FLAGS " -pedantic -Werror -Wall -Wextra")
string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

# message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}") -> /home/travis/build/bmstu-iu8-34-cpp-2018/lab-2-cache-yokkidack

# set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/bypass.hpp)


# enum your files and delete this comment

file(GLOB SOURCES
    include/*.hpp
    *.cpp
) 
add_executable(tests
    ${SOURCES}
)


target_link_libraries(tests GTest::main)

enable_testing()
add_test(NAME unit_tests COMMAND tests) 

list(APPEND CMAKE_MODULE_PATH "tools/codecov/cmake")
list(APPEND LCOV_REMOVE_PATTERNS "'${CMAKE_CURRENT_SOURCE_DIR}/tests/*'")
list(APPEND LCOV_REMOVE_PATTERNS "'${CMAKE_CURRENT_SOURCE_DIR}/tools/*'")
include(Findcodecov)
find_package(codecov)
add_coverage(tests)
