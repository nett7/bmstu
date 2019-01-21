cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include("tools/gate/cmake/HunterGate.cmake")

huntergate(
  URL "https://github.com/ruslo/hunter/archive/v0.23.34.tar.gz"
  SHA1 "70287b1ffa810ee4e952052a9adff9b4856d0d54"
)

project(lab02-2)
string(APPEND CMAKE_CXX_FLAGS " -pedantic -Wall -Wextra")
string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)


add_library(library STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp
)

target_include_directories(library
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(template-tests
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp
)

target_link_libraries(template-tests library GTest::main)

enable_testing()
add_test(NAME unit_tests COMMAND template-tests)

list(APPEND CMAKE_MODULE_PATH "tools/codecov/cmake")
list(APPEND LCOV_REMOVE_PATTERNS "'${CMAKE_CURRENT_SOURCE_DIR}/tests/*'")
list(APPEND LCOV_REMOVE_PATTERNS "'${CMAKE_CURRENT_SOURCE_DIR}/tools/*'")
include(Findcodecov)
find_package(codecov)
add_coverage(library)
add_coverage(template-tests)
