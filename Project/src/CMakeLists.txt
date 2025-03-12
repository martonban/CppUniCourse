# All .cpp files under src/
file(GLOB_RECURSE ALL_CPP_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Remove main.cpp explicitly
list(REMOVE_ITEM ALL_CPP_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp")

# Create the bank_model library
add_library(bank_lib ${ALL_CPP_FILES})
target_include_directories(bank_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Define the executable
add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE bank_lib)
