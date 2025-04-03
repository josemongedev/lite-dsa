cmake_minimum_required(VERSION 3.13)

project(codecrafters-http-server)

file(GLOB_RECURSE SOURCE_FILES src/*.c include/*.h)

set(CMAKE_C_STANDARD 23) # Enable the C23 standard
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Generate compile commands for clangd
set(LITE_DSA_SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(LITE_DSA_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include())
set(LITE_DSA_TESTS_DIR ${CMAKE_SOURCE_DIR}/tests)


# Add hash map library
add_library(hash_map STATIC ${LITE_DSA_SRC_DIR}/hash_map/hash_map.c)
target_include_directories(hash_map PUBLIC ${LITE_DSA_INCLUDE_DIR})

add_executable(test_hash_map ${LITE_DSA_TESTS_DIR}/test_hash_map.c) 
target_link_libraries(test_hash_map PRIVATE hash_map)
