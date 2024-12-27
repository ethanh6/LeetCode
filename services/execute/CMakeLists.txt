cmake_minimum_required(VERSION 3.20) # Support for C++23
project(CPP23Example)


# Add Catch2 library
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.7.1
)

FetchContent_MakeAvailable(Catch2)


# Enable C++23 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Add header files
include_directories(include)

# Add problem source files
file(GLOB_RECURSE PROBLEM_SOURCES problems/*.cpp)

# Create an executable for each problem under ./problems/
foreach(SOURCE_FILE ${PROBLEM_SOURCES})
    get_filename_component(PROBLEM_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${PROBLEM_NAME} ${SOURCE_FILE})
    target_link_libraries(${PROBLEM_NAME} PRIVATE Catch2::Catch2WithMain)
endforeach()

add_executable(prelog src/prelog.cpp)
target_include_directories(prelog PRIVATE include)
target_link_libraries(prelog PRIVATE Catch2::Catch2WithMain)

