cmake_minimum_required(VERSION 3.14)
set(This parser)
project(${This})
set(Test charItr)

# GoogleTest reauires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
googletest 
URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip)
# For Windows: Prevent overiding the parent project's compiler/linker settings
include_directories("${PROJECT_SOURCE_DIR}/include")
file(GLOB sources "${PROJECT_SOURCE_DIR}/src/*.c")
file(GLOB test_sources "${PROJECT_SOURCE_DIR}/test/*.cpp")
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) 
FetchContent_MAKEAvailable(googletest)
add_executable(${Test} ${test_sources} ${sources})
enable_testing()
target_link_libraries(${Test} 
gtest_main)

include(GoogleTest)
gtest_discover_tests(${Test})
