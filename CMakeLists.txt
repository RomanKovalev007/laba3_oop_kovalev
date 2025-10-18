cmake_minimum_required(VERSION 3.14)

project(laba_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
add_executable(figure
    src/figure.cpp
    src/octagon.cpp
    src/triangle.cpp
    src/square.cpp
    src/array.cpp
    src/main.cpp
)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests tests/main_test.cpp
    tests/array_test.cpp
    tests/octagon_test.cpp
    tests/square_test.cpp
    tests/triangle_test.cpp
    src/figure.cpp
    src/octagon.cpp
    src/triangle.cpp
    src/square.cpp
    src/array.cpp
)

target_link_libraries(tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)