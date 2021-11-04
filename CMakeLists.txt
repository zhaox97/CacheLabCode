cmake_minimum_required(VERSION 3.17)
project(Temp C)

set(CMAKE_C_STANDARD 99)

add_executable(qSort myQsort.c cacheTestTools.c)
add_executable(testMyQsort myQsort.c cacheTestTools.c testMyQsort.c)