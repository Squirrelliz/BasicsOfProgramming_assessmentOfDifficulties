cmake_minimum_required(VERSION 3.20)
project(assessmentOfDifficulties2 C)

set(CMAKE_C_STANDARD 11)

add_executable(assessmentOfDifficulties2 main.c algorithms.c)
add_subdirectory(timeOfSort)
target_link_libraries(assessmentOfDifficulties2 timeOfSort)
