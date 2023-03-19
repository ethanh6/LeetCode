cmake_minimum_required(VERSION 3.20)
project(LeetCode CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENTIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

find_package(Catch2 3 REQUIRED)


function(add_problem id slug)
    add_executable(${id} ${PROJECT_SOURCE_DIR}/src/${id}-${slug}.cpp)
    target_link_libraries(${id} PRIVATE Catch2::Catch2WithMain)
endfunction(add_problem)

# list of questions here

add_problem(0000 common-patterns)
add_problem(0001 two-sum)
add_problem(0121 best-time-to-buy-and-sell-stock)
