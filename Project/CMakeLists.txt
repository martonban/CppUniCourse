cmake_minimum_required(VERSION 3.8)
project(BankManager VERSION 0.0.0
        DESCRIPTION "Simple CMake project example with Catch2 tests"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)

# Add compiler warnings if gcc or clang is used
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(
        -Wall
        -Wextra # reasonable and standard
        -Wshadow # warn the user if a variable declaration shadows one from a parent context
        -Wnon-virtual-dtor # warn the user if a class with virtual functions has a non-virtual destructor. This helps
        # catch hard to track down memory errors
        -Wold-style-cast # warn for c-style casts
        -Wcast-align # warn for potential performance problem casts
        -Wunused # warn on anything being unused
        -Woverloaded-virtual # warn if you overload (not override) a virtual function
        -Wpedantic # warn if non-standard C++ is used
        -Wconversion # warn on type conversions that may lose data
        -Wsign-conversion # warn on sign conversions
        -Wnull-dereference # warn if a null dereference is detected
        -Wdouble-promotion # warn if float is implicit promoted to double
        -Wformat=2 # warn on security issues around functions that format output (ie printf)
        -Wimplicit-fallthrough # warn on statements that fallthrough without an explicit annotation
        -Werror # warnings as errors
    )
endif()

# AddressSanitizer only in Debug mode for GCC and Clang
if(CMAKE_BUILD_TYPE STREQUAL "Debug" AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-fsanitize=address,leak,undefined)
    add_link_options(-fsanitize=address,leak,undefined)
endif()

# separate src and tests with their own CMakeLists
add_subdirectory(src)
add_subdirectory(tests)