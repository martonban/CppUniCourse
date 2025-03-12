enable_testing()
include(CTest)
include(FetchContent)

# Use CMake Fetch to pull Catch2 v3.8.0 - latest as of 11.03.2025
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.0
)

FetchContent_MakeAvailable(Catch2)

# Explicitly disable warnings for Catch2
set_target_properties(Catch2 PROPERTIES COMPILE_FLAGS "-w")

file(GLOB_RECURSE TEST_SOURCES "${CMAKE_SOURCE_DIR}/tests/*.cpp")

add_executable(test_runner ${TEST_SOURCES})
target_link_libraries(test_runner PRIVATE bank_lib Catch2::Catch2WithMain)

# If we want to add it as a single CTest
# add_test(NAME BankAccountTests COMMAND $<TARGET_FILE:test_runner>)

include(Catch)
# Add each test separately
catch_discover_tests(test_runner WORKING_DIRECTORY ${CMAKE_BINARY_DIR})