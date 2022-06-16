cmake_minimum_required(VERSION 3.20)
project(Podstawy_Programowania C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_MAKE_PROGRAM make)
set(CMAKE_GENERATOR make)

add_compile_options(
      "-pedantic"
      "-Wall"
      "-Weverything"
      "-ferror-limit=16"
)

add_executable(Podstawy_Programowania
      PP2/workspace.c
      # PP2/my_file.c
      # PP2/my_exit.c
      # PP2/vector.c
      # PP2/circular_buffer.c
      # PP2/array.c
      # PP2/matrix_utils.c
      # PP2/image_utils.c
      # PP2/statistics_utils.c
      # PP2/student_utils_v2.c
      # PP2/big_number_utils.c
      # PP2/wordcross_utils.c
      PP2/my_string.c
      # PP2/int_operations.c
      # PP2/for_loop.c
      PP2/comparators.c

      # PP1/workspace.c
      # PP1/functions.c
      # PP1/vector_utils.c
)

target_link_libraries(Podstawy_Programowania m) # I f🤬kin' hate *nix
