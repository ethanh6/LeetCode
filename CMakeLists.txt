cmake_minimum_required(VERSION 3.20)
project(LeetCode CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENTIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_EXPORT_COMPILE_COMMANDS: ${CMAKE_EXPORT_COMPILE_COMMANDS}")
message(STATUS "CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS "PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR})

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif()

find_package(Catch2 3 REQUIRED)

function(add_problem id slug)
    add_executable(${id} ${PROJECT_SOURCE_DIR}/src/${id}-${slug}.cpp)
    target_link_libraries(${id} PRIVATE Catch2::Catch2WithMain)
endfunction(add_problem)

# list of questions here

add_problem(0000 common-patterns)
add_problem(0001 two-sum)
add_problem(0121 best-time-to-buy-and-sell-stock)
add_problem(0015 3sum)
add_problem(0238 product-of-array-except-self)
add_problem(0039 combination-sum)
add_problem(0056 merge-intervals)
add_problem(0169 majority-element)
add_problem(0075 sort-colors)
add_problem(0217 contains-duplicate)
add_problem(0011 container-with-most-water)
add_problem(0252 meeting-rooms)
add_problem(0134 gas-station)
