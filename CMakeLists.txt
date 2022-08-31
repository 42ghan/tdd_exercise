cmake_minimum_required(VERSION 3.14)
project(tdd_exercise)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories("includes")

add_executable(
	bowling_test
	srcs/InputValidator.cpp
	# srcs/ScoreBoard.cpp
	srcs/ScoreCalculator.cpp
	tests/test.cpp
)

target_link_libraries(
	bowling_test
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(bowling_test)