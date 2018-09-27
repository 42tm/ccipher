cmake_minimum_required(VERSION 3.0.0)
project(ccipher CXX)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include_directories("${PROJECT_SOURCE_DIR}")

# Libraries from lib/
add_library(atbash STATIC lib/atbash)
add_library(caesar STATIC lib/caesar)
add_library(vigenere STATIC lib/vigenere)

# Output executable
add_executable(ccipher ${PROJECT_SOURCE_DIR}/ccipher.cpp)
target_link_libraries(ccipher
                        PUBLIC atbash
                        PUBLIC caesar
                        PUBLIC vigenere
                        )
