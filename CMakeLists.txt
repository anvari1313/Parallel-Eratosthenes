cmake_minimum_required(VERSION 3.8)
project(Eratosthenes)

find_package (Threads)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp single_thread.cpp single_thread.h eratosthenes.h eratosthenes.cpp multi_thread.cpp multi_thread.h multi_process.cpp multi_process.h)
add_executable(Eratosthenes ${SOURCE_FILES})
target_link_libraries (Eratosthenes ${CMAKE_THREAD_LIBS_INIT})