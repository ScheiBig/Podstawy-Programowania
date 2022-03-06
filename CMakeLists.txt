cmake_minimum_required(VERSION 3.20)
project(Podstawy_Programowania_1 C)

set(CMAKE_C_STANDARD 11)

add_compile_options(
      "-pedantic"
      "-Wall"
      "-Weverything"
      "-ferror-limit=16"
)

# add_executable(Podstawy_Programowania_1 
# workspace.c 
# vector_utils.c
# )

add_executable(Podstawy_Programowania_1 workspace_copy.c)

target_link_libraries(Podstawy_Programowania_1 m) # I f🤬kin' hate *nix